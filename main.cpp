//
// Created by aoweichen on 2024/12/22.
//
#include <iostream>
#include <IZIP/ZipStruct.hpp>

using namespace cnnx::zippy;

int main() {
    LocalFileHeader header{};
    std::cout << "Size of LocalFileHeader: " << sizeof(header) << " bytes\n";
    return 0;
}