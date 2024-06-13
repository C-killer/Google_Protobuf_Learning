# Google_Protobuf_Learning
C++中关于protobuf的学习 

1. protobuf
   
   在极其特殊的情况下通过protobuf创建两个名称相同的类（person和info），并采取作用域标识以示区分。
该项目简单地实现了一个对象“创建初始化 - 赋值 - 序列化 - 传输 - 反序列化 - 得到原始数据”的全过程
同时，记录了相关问题和编译方法
   1.1 使用 "protoc --cpp_out=. ./person.proto" 生成对应的pb.h和pb.cc文件
   1.2 


3. protobuf service

   利用grpc简单实现了peotobuf service框架，用户端和服务端简单的信息交互。
