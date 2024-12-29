//
// Created by aoweichen on 2024/12/29.
//

#ifndef CNNX_ZIPPARSER_HPP
#define CNNX_ZIPPARSER_HPP

#include <filesystem>
#include <vector>
#include <string>
#include <optional>

namespace cnnx::zippy {
    class ArchiveParser {
    public:
        virtual ~ArchiveParser() = default;

        virtual bool open(const std::filesystem::path &path) = 0;

        virtual void close() = 0;

        [[nodiscard]] virtual std::vector<std::string> get_file_names() const = 0;

        [[nodiscard]] virtual std::optional<uint64_t> get_file_size(const std::string &name) const = 0;

        [[nodiscard]] virtual std::optional<std::vector<char>> read_file(const std::string &name) const = 0;

    };
}

namespace cnnx::zippy {
    class ArchiveFactory {
        virtual ~ArchiveFactory() = default;

        virtual std::unique_ptr<ArchiveParser> create_parser() = 0;
    };
}

namespace cnnx::zippy {
    class ZipParser : public ArchiveParser {
    public:
        ZipParser();

        ~ZipParser() override;

        bool open(const std::filesystem::path &path) override;

        void close() override;

        std::vector<std::string> get_file_names() const override;

        std::optional<uint64_t> get_file_size(const std::string &name) const override;

        std::optional<std::vector<char>> read_file(const std::string &name) const override;
    private:

    };
}

#endif //CNNX_ZIPPARSER_HPP
