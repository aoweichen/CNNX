//
// Created by aoweichen on 2024/12/22.
//

#ifndef CNNX_STOREZIP_HPP
#define CNNX_STOREZIP_HPP

#include <string>

namespace cnnx {
    class StoreZipReader {
    public:
        StoreZipReader() = default;

        ~StoreZipReader() = default;

        [[maybe_unused]] int Open(const std::string &ZipFilePath);
    };
}
#endif //CNNX_STOREZIP_HPP
