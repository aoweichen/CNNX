//
// Created by aoweichen on 2024/12/22.
//
#include <iostream>
#include <IZIP/FileHandle.hpp>

using namespace cnnx::zippy;

int main() {
    try {
        // 创建文件句柄
        FileHandle file;

        // 打开文件
        auto openResult = file.open("./main.txt", "r+");
        if (openResult) {
            std::cerr << "Error: " << *openResult << std::endl;
            return 1;
        }

        // 检查文件是否打开
        if (file.is_open()) {
            std::cout << "File opened successfully!" << std::endl;

            // 读取文件内容
            auto data = file.read(1024);
            if (data) {
                std::cout << "Read data: " << std::string(data->begin(), data->end()) << std::endl;
            } else {
                std::cerr << "Error: failed to read file" << std::endl;
            }
        }

        // 关闭文件
        file.close();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}