#include "person.pb.h"
#include "info.pb.h"
#include <iostream>

using namespace std;
using namespace PERSON;
//或 using namespace INFO; 二者同时出现则会使目标不明确

int main() {
    // Step 1 : 创建并初始化对象
    SameName p;   // person
    p.set_id(31415926);
    string *namePtr = new string("Jack");
    p.set_allocated_name(namePtr);
    p.set_sex("male");
    p.set_age(22);
    p.add_color(RED);   
    p.add_color(BLUE);  
    p.add_color(YELLOW);
    //通过 mutable 访问赋值
    INFO::SameName *info = p.mutable_info();
    info->set_address("Suzhou");
    info->set_tel(123456789);

    // Step 2 : 序列化对象
    string output;
    if (p.SerializeToString(&output)) { // 检查序列化是否成功
        cout << "序列化后数据为：" << output << endl;
        cout << "=======================" << endl;
    } else {
        cerr << "序列化失败！" << endl;
        return -1;
    }

    // Step 3 : 数据传输
    // Step 4 : 接收数据、解析、解码、得到原始数据
    // 反序列化对象
    SameName pp;
    if (pp.ParseFromString(output)) { // 检查反序列化是否成功
        cout << "id = " << pp.id() << endl;
        cout << "name : " << pp.name() << endl;
        cout << "sex : " << pp.sex() << endl;
        cout << "age : " << pp.age() << endl;
        for (int i = 0; i < pp.color_size(); i++) {
            cout << "color[" << i << "] = " << pp.color(i) << endl;
        }
        if (pp.has_info()) { // 确保只有在 info 字段存在时才访问它
            INFO::SameName ii = pp.info();
            cout << "address : " << ii.address() << endl;
            cout << "tel : " << ii.tel() << endl;
        }
    } else {
        cerr << "反序列化失败！" << endl;
        return -1;
    }

    google::protobuf::ShutdownProtobufLibrary(); // 关闭 Protocol Buffers 库
    return 0;
}


 // g++ -o main main.cpp info.pb.cc person.pb.cc -lprotobuf
