//
// Created by aoweichen on 2024/12/22.
//

#ifndef CNNX_STOREZIP_HPP
#define CNNX_STOREZIP_HPP

#include <cstdint>
#include <string>
#include <map>
#include <vector>
#include <optional>
#include <span>
#include <stdexcept>


namespace cnnx{
    class FileHandle{

    };
}


namespace cnnx {
    template<typename T>
    concept Readable = requires(T t) {
        { t.read(std::declval<char *>(), std::declval<size_t>()) }->std::same_as<std::streamsize>;
    };
}


// RAII 封装文件句柄
class FileHandle {
public:
    FileHandle(const std::string& path, const std::string& mode) {
        fp = std::fopen(path.c_str(), mode.c_str());
        if (!fp) {
            throw std::runtime_error("Failed to open file: " + path);
        }
    }
    ~FileHandle() {
        if (fp) {
            std::fclose(fp);
        }
    }
    FILE* get() const { return fp; }

private:
    FILE* fp;
};

namespace cnnx {
    class FileHandler {

    };
}

namespace cnnx {
    class IZIPBackend {
    private:

    public:
    };
}


namespace cnnx {
    class StoreZipReader {
    public:
        StoreZipReader() = default;

        ~StoreZipReader() = default;

        [[maybe_unused]] int Open(const std::string &ZipFilePath);

        std::vector<std::string> get_file_names() const;

        uint64_t get_file_size(const std::string &name) const;

        int read_file(const std::string &name, char *data);

        int close();
    };
}
#endif //CNNX_STOREZIP_HPP
