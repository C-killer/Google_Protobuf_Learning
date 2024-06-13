#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h"

//基本上是规定流程
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using example::HelloRequest;
using example::HelloReply;
using example::MyService;

using namespace std;

// 定义服务的实现类，继承由protoc生成的服务基类
class MyServiceImpl final : public MyService::Service {
    // 覆盖SayHello方法，处理客户端的SayHello请求
    Status SayHello(ServerContext* context, const HelloRequest* request, HelloReply* reply) override {
        string prefix("Hello ");
        reply->set_message(prefix + request->name());
        return Status::OK;     // 返回状态为OK
    }
};

void RunServer() {
    string server_address("0.0.0.0:50051");    //监听的地址和端口
    MyServiceImpl service;    // 创建服务实现实例

    ServerBuilder builder;    // 创建服务器构建器(规定流程)
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());    // 添加监听端口
    builder.RegisterService(&service);     // 注册服务

    unique_ptr<Server> server(builder.BuildAndStart());    // 构建并启动服务器
    cout << "Server listening on " << server_address << endl;

    server->Wait();    // 等待服务器终止
}


int main(int argc, char** argv) {
    RunServer();    // 运行服务器
    return 0;
}
