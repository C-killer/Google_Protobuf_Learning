// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: example.proto

#include "example.pb.h"
#include "example.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace example {

static const char* MyService_method_names[] = {
  "/example.MyService/SayHello",
};

std::unique_ptr< MyService::Stub> MyService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< MyService::Stub> stub(new MyService::Stub(channel, options));
  return stub;
}

MyService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SayHello_(MyService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status MyService::Stub::SayHello(::grpc::ClientContext* context, const ::example::HelloRequest& request, ::example::HelloReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::example::HelloRequest, ::example::HelloReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

void MyService::Stub::async::SayHello(::grpc::ClientContext* context, const ::example::HelloRequest* request, ::example::HelloReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::example::HelloRequest, ::example::HelloReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, std::move(f));
}

void MyService::Stub::async::SayHello(::grpc::ClientContext* context, const ::example::HelloRequest* request, ::example::HelloReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::example::HelloReply>* MyService::Stub::PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::example::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::example::HelloReply, ::example::HelloRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SayHello_, context, request);
}

::grpc::ClientAsyncResponseReader< ::example::HelloReply>* MyService::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::example::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSayHelloRaw(context, request, cq);
  result->StartCall();
  return result;
}

MyService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MyService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MyService::Service, ::example::HelloRequest, ::example::HelloReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](MyService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::example::HelloRequest* req,
             ::example::HelloReply* resp) {
               return service->SayHello(ctx, req, resp);
             }, this)));
}

MyService::Service::~Service() {
}

::grpc::Status MyService::Service::SayHello(::grpc::ServerContext* context, const ::example::HelloRequest* request, ::example::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace example

