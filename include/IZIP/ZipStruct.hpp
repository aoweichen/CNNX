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
        uint16_t version_needed_to_extract;
        uint16_t general_purpose_bit_flag;
        uint16_t compression_method;
        uint16_t last_modification_time;
        uint16_t last_modification_date;
        uint32_t crc32_checksum;
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
        uint16_t version_needed_to_extract;
        uint16_t general_purpose_bit_flag;
        uint16_t compression_method;
        uint16_t last_modification_time;
        uint16_t last_modification_date;
        });

    PACK(struct CentralDirectoryFileHeader64 {
        uint32_t version_made;
        uint32_t version_needed_to_extract;
        uint32_t general_purpose_bit_flag;
        uint32_t compression_method;
        uint32_t last_modification_time;
        uint32_t last_modification_date;
        });

    PACK(struct Zip64EndOfCentralDirectoryRecord {
        uint32_t disk_number_with_eocdr64;
        uint64_t offset_to_eocdr64;
        uint32_t total_number_of_disks;
        });

    PACK(struct EndOfCentralDirectoryRecord {
        uint16_t current_disk_number;
        uint16_t central_directory_start_disk;
        uint16_t central_directory_records_on_current_disk;
        uint16_t total_central_directory_records;
        uint32_t central_directory_size;
        uint32_t central_directory_offset;
        uint32_t comment_length;
        });
}

#endif //CNNX_ZIPSTRUCT_HPP