#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "logInOut.grpc.pb.h"

//基本上是规定流程
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using RPC::UserServiceRPC;
using RPC::LoginRequest;
using RPC::LoginResponse;
using RPC::RegisterRequest;
using RPC::RegisterResponse;
using RPC::ResultCode;

using namespace std;

class UserServiceRPCImpl final : public UserServiceRPC::Service {
    //重写 Login方法
    Status Login(ServerContext* context, const LoginRequest* request, 
                            LoginResponse* response) override{
        if (request->name() == "username" && request->pwd() == "password") {    //如果用户名密码正确则返回登陆成功
            response->mutable_result()->set_errcode(0);
            response->mutable_result()->set_errmsg("");
            response->set_success(true);
        } else {    //如果错误则返回错误信息
            response->mutable_result()->set_errcode(1);
            response->mutable_result()->set_errmsg("Invalid username or password");
            response->set_success(false);
        }
        return Status::OK;     //最后返回Login状态：OK
    }

    //重写 Register 方法    
    Status Register (ServerContext* context, const RegisterRequest* request, 
                            RegisterResponse* response) override{
        //仅考虑注册成功的情况
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        response->set_success(true);
        return Status::OK;
    }
};

void RunServer() {
    string server_address("0.0.0.0:50051");    //监听的地址和端口
    UserServiceRPCImpl service;    // 创建服务实现实例

    ServerBuilder builder;    // 创建服务器构建器(规定流程)
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());    // 添加监听端口
    builder.RegisterService(&service);     // 注册服务

    unique_ptr<Server> server(builder.BuildAndStart());    // 构建并启动服务器
    cout << "Server listening on " << server_address << endl;

    server->Wait();    // 等待服务器终止
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}