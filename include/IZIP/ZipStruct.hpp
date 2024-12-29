//
// Created by aoweichen on 2024/12/29.
//

#ifndef CNNX_ZIPSTRUCT_HPP
#define CNNX_ZIPSTRUCT_HPP

#include <cstdint>


namespace cnnx::zippy {
#ifdef _MSC_VER
#define PACK(__Declaration__) __pragma(pack(push, 1)) __Declaration__ __pragma(pack(pop))
#else
#define PACK(__Declaration__) __Declaration__ __attribute__((__packed__))
#endif
}


namespace cnnx::zippy {
    PACK(struct LocalFileHeader {
             uint16_t version;
             uint16_t flag;
             uint16_t compression;
             uint16_t last_modify_time;
             uint16_t last_modify_date;
             uint32_t crc32;
             uint32_t compressed_size;
             uint32_t uncompressed_size;
             uint16_t file_name_length;
             uint16_t extra_field_length;
         });

    PACK(struct Zip64ExtendedExtraField {
             uint64_t uncompressed_size;
             uint64_t compressed_size;
             uint64_t relative_lfh_offset;
             uint32_t disk_number;
         });

    PACK(struct CentralDirectoryFileHeader {
             uint16_t version_made;
             uint16_t version;
             uint16_t flag;
             uint16_t compression;
             uint16_t last_modify_time;
             uint16_t last_modify_date;


         });
}

#endif //CNNX_ZIPSTRUCT_HPP
