# Google_Protobuf_Learning
C++中关于protobuf的学习 

1. protobuf
   
   在极其特殊的情况下通过protobuf创建两个名称相同的类（person和info），并采取作用域标识以示区分。
该项目简单地实现了一个对象“创建初始化 - 赋值 - 序列化 - 传输 - 反序列化 - 得到原始数据”的全过程
同时，记录了相关问题和编译方法

   1.1 编译proto文件：
   
         protoc --cpp_out=. ./person.proto

   1.2 在main函数中的主要流程 ：创建对象 - 序列化对象 - （数据传输） - （数据接收） - 反序列化对象 - 得到原始数据

   1.3 编译main文件：

         g++ -o main main.cpp info.pb.cc person.pb.cc -lprotobuf



3. protobuf service

   利用grpc简单实现了peotobuf service框架，用户端和服务端简单的信息交互。
