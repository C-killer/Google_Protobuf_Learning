#include <iostream>                      
#include <memory>                        
#include <string>                        

#include <grpcpp/grpcpp.h>
#include "example.grpc.pb.h" 

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using example::HelloRequest;
using example::HelloReply;
using example::MyService;

using namespace std;

class MyServiceClient {
    public: 
    MyServiceClient(std::shared_ptr<Channel> channel) 
        : stub_(MyService::NewStub(channel)) {}
    
    string SayHello(const string& user) {
        //创建并填充request信息
        HelloRequest request;    
        request.set_name(user);

        //创建回复响应reply
        HelloReply reply;

        // 创建客户端上下文
        ClientContext context;

        // 调用远程方法并获取结果
        Status status = stub_->SayHello(&context, request, &reply);

        if (status.ok()) {   //如果RPC调用成功  
            return reply.message();
        } else {
            cout << status.error_code() << ": " << status.error_message()
                 << endl;
            return "RPC failed";
        }
    }
    
    private:
    // gRPC存根，封装与服务器的通信
    std::unique_ptr<MyService::Stub> stub_;
};


int main(int argc, char** argv) {
    // 创建gRPC通道，连接到服务器
    auto channel = grpc::CreateChannel("localhost:50051",grpc::InsecureChannelCredentials());

    MyServiceClient client (channel);
    
    // 发送请求并获取响应
    string user("world");
    string reply = client.SayHello(user);
    cout << "Greeter received: " << reply << endl;

    return 0;
}