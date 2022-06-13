## protobuf测试工程

```
源码
git clone https://github.com/protocolbuffers/protobuf.git

```

## windwos vs2019 win64 （编译验证）

```
https://github.com/protocolbuffers/protobuf/releases/tag/v3.20.1
下载protobuf-cpp-3.20.1.zip
cmake-gui打开 选VS 2019   指定x64
1.勾选protobuf_BUILD_SHARED_LIBS 是否开启编译动态库
2.取消勾选protobuf_BUILD_TESTS
3.设置安装路径：CMAKE_INSTALL_PREFIX  我设置在了D盘
遇到报错
Could NOT find ZLIB (missing: ZLIB_LIBRARY) (found version "1.2.11")
去这里下载zlib,
http://gnuwin32.sourceforge.net/packages/zlib.htm
```

```
打开ZLIB设置栏，配置zlib的头文件路径和库文件：
```

```
重新configure-》gernerate-》使用vs打开编译
结果遇到报错
```

```
看报错内容是zlib这个库不能正常识别，日璇和林哥都可以的。解决方法
去https://github.com/madler/zlib下载源码
cmake-gui+vs2019重新编译一个库，问题解决。

最后调用库的时候windows下我的方式是
set(CMAKE_PREFIX_PATH "${CMAKE_MY_PROJECT_PATH}/thirdparty/libprotobuf_win64")
find_package(protobuf CONFIG REQUIRED)
include_directories ( ${CMAKE_MY_THIRDPARTY_PATH}/libprotobuf_win64/include)
target_link_libraries(${CMAKE_MY_TARGET_NAME} PRIVATE protobuf::libprotobuf)

```

###### 