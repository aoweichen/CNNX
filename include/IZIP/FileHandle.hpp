//
// Created by aoweichen on 2024/12/29.
//

#ifndef CNNX_FILEHANDLE_HPP
#define CNNX_FILEHANDLE_HPP

#include <functional>
#include <optional>
#include <vector>
#include <string>
#include <span>
#include <concepts>
#include <memory>

//namespace cnnx::zippy {
//    template<typename T>
//    concept Readable = requires(T t){
//        { t.read(std::declval<size_t>()) }->std::same_as<std::optional<std::vector<char>>>;
//    };
//
//    template<typename T>
//    concept Writable = requires(T t, std::span<const char> data){
//        { t.write(data) }->std::same_as<std::optional<std::string>>;
//    };
//}

namespace cnnx::zippy {
    class IFileHandle {
    public:
        virtual ~IFileHandle() = default;

        [[maybe_unused]] virtual std::optional<std::string> open(const std::string &path, const std::string &mode) = 0;

        [[maybe_unused]] virtual void close() noexcept = 0;

        [[maybe_unused]] [[nodiscard]] virtual bool is_open() const noexcept = 0;

        [[maybe_unused]] [[nodiscard]] virtual std::optional<std::vector<char>> read(const size_t &size) const = 0;

        [[maybe_unused]] [[nodiscard]] virtual std::optional<std::string> write(std::span<const char> data) const = 0;

        [[maybe_unused]] [[nodiscard]] virtual std::optional<size_t> size() const = 0;
    };
}

namespace cnnx::zippy {
    class FileHandle : public IFileHandle {
    public:
        explicit FileHandle() = default;

        ~FileHandle() override;

        std::optional<std::string> open(const std::string &path, const std::string &mode) override;

        void close() noexcept override;

        bool is_open() const noexcept override;

        std::optional<std::vector<char>> read(const size_t &size) const override;

        std::optional<std::string> write(std::span<const char> data) const override;

        std::optional<size_t> size() const override;

    private:
        std::unique_ptr<FILE, decltype(&std::fclose)> file_pointer{nullptr, &std::fclose};
        mutable std::mutex file_mutex;
    };
}


#endif //CNNX_FILEHANDLE_HPP
