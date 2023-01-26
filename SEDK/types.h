/*

    SEDK - Simple Extensible Firmware Interface Development Kit
    
    File: types.h

    Last change: 26.01.2023
*/

#ifndef __TYPES_H
#define __TYPES_H

// Types
typedef unsigned long       uint64_t;
typedef long                int64_t;
typedef unsigned int        uint32_t;
typedef int                 int32_t;
typedef unsigned short      uint16_t;
typedef short               int16_t;
typedef unsigned char       uint8_t;
typedef signed char         int8_t;

typedef uint8_t             boolean;
typedef uint16_t            char16;
typedef uint64_t            EFI_LBA;
typedef uint64_t            EFI_PHYSICAL_ADDRESS;
typedef uint64_t            EFI_STATUS;
typedef uint64_t            EFI_TL;
typedef uint64_t            EFI_TPL;
typedef uint64_t            EFI_VIRTUAL_ADDRESS;           
typedef void                *EFI_HANDLE;
typedef void                *EFI_EVENT;

#define EFI_SUCCESS                 0x0000000000000000
#define EFI_ERR                     0x8000000000000000
#define EFI_LOAD_ERROR              (EFI_ERR | 0x0000000000000001)
#define EFI_INVALID_PARAMETER       (EFI_ERR | 0x0000000000000002)
#define EFI_UNSUPPORTED             (EFI_ERR | 0x0000000000000003)
#define EFI_BAD_BUFFER_SIZE         (EFI_ERR | 0x0000000000000004)
#define EFI_BUFFER_TOO_SMALL        (EFI_ERR | 0x0000000000000005)
#define EFI_NOT_READY               (EFI_ERR | 0x0000000000000006)
#define EFI_DEVICE_ERROR            (EFI_ERR | 0x0000000000000007)
#define EFI_WRITE_PROTECTED         (EFI_ERR | 0x0000000000000008)
#define EFI_OUT_OF_RESOURCES        (EFI_ERR | 0x0000000000000009)
#define EFI_VOLUME_CORRUPTED        (EFI_ERR | 0x000000000000000a)
#define EFI_VOLUME_FULL             (EFI_ERR | 0x000000000000000b)
#define EFI_NO_MEDIA                (EFI_ERR | 0x000000000000000c)
#define EFI_MEDIA_CHANGED           (EFI_ERR | 0x000000000000000d)
#define EFI_NOT_FOUND               (EFI_ERR | 0x000000000000000e)
#define EFI_ACCESS_DENIED           (EFI_ERR | 0x000000000000000f)
#define EFI_NO_RESPONSE             (EFI_ERR | 0x0000000000000010)
#define EFI_NO_MAPPING              (EFI_ERR | 0x0000000000000011)
#define EFI_TIMEOUT                 (EFI_ERR | 0x0000000000000012)
#define EFI_NOT_STARTED             (EFI_ERR | 0x0000000000000013)
#define EFI_ALREADY_STARTED         (EFI_ERR | 0x0000000000000014)
#define EFI_ABORTED                 (EFI_ERR | 0x0000000000000015)
#define EFI_ICMP_ERROR              (EFI_ERR | 0x0000000000000016)
#define EFI_TFTP_ERROR              (EFI_ERR | 0x0000000000000017)
#define EFI_PROTOCOL_ERROR          (EFI_ERR | 0x0000000000000018)
#define EFI_INCOMPATIBLE_VERSION    (EFI_ERR | 0x0000000000000019)
#define EFI_SECURITY_VIOLATION      (EFI_ERR | 0x000000000000001a)
#define EFI_CRC_ERROR               (EFI_ERR | 0x000000000000001b)
#define EFI_END_OF_MEDIA            (EFI_ERR | 0x000000000000001c)
#define EFI_END_OF_FILE             (EFI_ERR | 0x000000000000001f)
#define EFI_INVALID_LANGUAGE        (EFI_ERR | 0x0000000000000020)
#define EFI_COMPROMISED_DATA        (EFI_ERR | 0x0000000000000021)
#define EFI_IP_ADDRESS_CONFLICT     (EFI_ERR | 0x0000000000000022)
#define EFI_HTTP_ERROR              (EFI_ERR | 0x0000000000000023)

#define EFI_MEMORY_UC               0x0000000000000001
#define EFI_MEMORY_WC               0x0000000000000002
#define EFI_MEMORY_WT               0x0000000000000004
#define EFI_MEMORY_WB               0x0000000000000008
#define EFI_MEMORY_UCE              0x0000000000000010
#define EFI_MEMORY_WP               0x0000000000001000
#define EFI_MEMORY_RP               0x0000000000002000
#define EFI_MEMORY_XP               0x0000000000004000
#define EFI_MEMORY_NV               0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE    0x0000000000010000
#define EFI_MEMORY_RO               0x0000000000020000
#define EFI_MEMORY_RUNTIME          0x8000000000000000

#endif // End of file
