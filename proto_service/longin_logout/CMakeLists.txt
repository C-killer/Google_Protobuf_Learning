cmake_minimum_required(VERSION 3.5)
project(UserServiceRPC)

set(CMAKE_CXX_STANDARD 14)  # 使用C++14

# 设置Protobuf路径
set(Protobuf_INCLUDE_DIR /home/parallels/protobuf-3.20.1/src)
set(Protobuf_LIBRARIES /home/parallels/protobuf-3.20.1/src/.libs/libprotobuf.a)
set(Protobuf_PROTOC_EXECUTABLE /home/parallels/protobuf-3.20.1/src/protoc)

# 设置gRPC路径
set(gRPC_INCLUDE_DIR /home/parallels/grpc/include)
file(GLOB gRPC_LIBRARIES /home/parallels/grpc/libs/*.a)

# 设置Abseil路径
set(ABSL_INCLUDE_DIR /home/parallels/abseil-cpp)
file(GLOB ABSL_LIBRARIES /home/parallels/abseil-cpp/absl/*.a)

include_directories(${Protobuf_INCLUDE_DIR})
include_directories(${gRPC_INCLUDE_DIR})
include_directories(${ABSL_INCLUDE_DIR})

add_executable(server server.cpp logInOut.grpc.pb.cc logInOut.pb.cc)
target_link_libraries(server ${Protobuf_LIBRARIES} ${gRPC_LIBRARIES} ${ABSL_LIBRARIES} grpc++)

add_executable(client client.cpp logInOut.grpc.pb.cc logInOut.pb.cc)
target_link_libraries(client ${Protobuf_LIBRARIES} ${gRPC_LIBRARIES} ${ABSL_LIBRARIES} grpc++)
