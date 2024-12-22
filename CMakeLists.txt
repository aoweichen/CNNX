cmake_minimum_required(VERSION 3.20)
project(cnnx)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加源文件
set(SOURCES
        source/StoreZip.cpp
        main.cpp
)

# 创建可执行文件
add_executable(main ${SOURCES})

# 更现代的方式：使用 target_include_directories
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)