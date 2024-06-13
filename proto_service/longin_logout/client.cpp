#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "logInOut.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using RPC::UserServiceRPC;
using RPC::LoginRequest;
using RPC::LoginResponse;
using RPC::RegisterRequest;
using RPC::RegisterResponse;

using namespace std;

class UserServiceRPCClient {
    public: 
    UserServiceRPCClient(std::shared_ptr<Channel> channel) 
        : stub_(UserServiceRPC::NewStub(channel)) {}

    bool Login(const string& name, const string& pwd) {
        //创建并填充request信息
        LoginRequest request;
        request.set_name(name);
        request.set_pwd(pwd);

        //创建回复响应
        LoginResponse response;
        // 创建客户端上下文
        ClientContext context;

        // 调用远程方法并获取结果
        Status status = stub_->Login(&context, request, &response);

        if (status.ok()) {      //如果RPC调用成功  
            if (response.success()) {   //如果登陆成功
                cout << "Login successful!" << endl;
            } else {    //如果登陆失败
                cout << "Login failed : " << response.result().errmsg() << endl;
            }
            return response.success();
        } else {    //RPC调用失败
            cout << "RPC failed! " << endl;
            return false;
        }
    }

    bool Register(int id, const string& name, const string& pwd) {
        //创建并填充request信息
        RegisterRequest request;
        request.set_id(id);
        request.set_name(name);
        request.set_pwd(pwd);

        //创建回复响应
        RegisterResponse response;
        // 创建客户端上下文
        ClientContext context;

        // 调用远程方法并获取结果
        Status status = stub_->Register(&context, request, &response);

        if (status.ok()) {      //如果RPC调用成功  
            if (response.success()) {   //如果注册成功
                cout << "Register successful!" << endl;
            } else {    //如果登陆失败
                cout << "Register failed : " << response.result().errmsg() << endl;
            }
            return response.success();
        } else {    //RPC调用失败
            cout << "RPC failed! " << endl;
            return false;
        }
    }

    private:
    // gRPC存根，封装与服务器的通信
    std::unique_ptr<UserServiceRPC::Stub> stub_;
};

int main(int argc, char** argv) {
    // 创建gRPC通道，连接到服务器
    auto channel = grpc::CreateChannel("localhost:50051",grpc::InsecureChannelCredentials());

    UserServiceRPCClient client (channel);
    
    // 发送请求并获取响应
    string name("username");
    string pwd("password");
    int id = 1;
    client.Login(name,pwd);
    client.Register(id,name,pwd);

    return 0;
}