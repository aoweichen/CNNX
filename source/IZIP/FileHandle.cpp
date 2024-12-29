//
// Created by aoweichen on 2024/12/29.
//

#include <IZIP/FileHandle.hpp>
#include <stdexcept>
#include <format>

namespace cnnx::zippy {

    std::optional<std::string> FileHandle::open(const std::string &path, const std::string &mode) {
        std::lock_guard<std::mutex> lock(this->file_mutex);
        this->file_pointer.reset(std::fopen(path.c_str(), mode.c_str()));
        if (not this->file_pointer) {
            std::string message = std::string{"Failed to open file: " + path + "."};
            return std::make_optional(message);
        } else {
            return std::nullopt;
        }
    }

    void FileHandle::close() noexcept {
        std::lock_guard<std::mutex> lock(this->file_mutex);
        if (this->file_pointer) {
            this->file_pointer.reset();
        }
    }

    bool FileHandle::is_open() const noexcept {
        std::lock_guard<std::mutex> lock(this->file_mutex);
        return this->file_pointer != nullptr;
    }

    std::optional<std::vector<char>> FileHandle::read(const size_t &size) const {
        std::lock_guard<std::mutex> lock(this->file_mutex);
        std::vector<char> buffer(size);
        size_t bytes_read = std::fread(buffer.data(), 1, size, this->file_pointer.get());
        if (bytes_read < size && std::ferror(this->file_pointer.get())) {
            return std::nullopt;
        } else {
            buffer.resize(bytes_read);
            return buffer;
        }
    }

    std::optional<std::string> FileHandle::write(std::span<const char> data) const {
        std::lock_guard<std::mutex> lock(this->file_mutex);
        size_t bytes_written = std::fwrite(data.data(), 1, data.size(), this->file_pointer.get());
        if (bytes_written < data.size()) {
            return std::string{"Failed to write to file."};
        } else {
            return std::nullopt;
        }
    }

    std::optional<size_t> FileHandle::size() const {
        std::lock_guard<std::mutex> lock(this->file_mutex);
        std::fseek(this->file_pointer.get(), 0, SEEK_END);
        size_t size = std::ftell(this->file_pointer.get());
        std::fseek(this->file_pointer.get(), 0, SEEK_SET);
        return size;
    }

    FileHandle::~FileHandle() {
        this->close();
    }


}