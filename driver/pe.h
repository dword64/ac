#ifndef PE_H
#define PE_H

#include "common.h"

#define IMAGE_DOS_SIGNATURE 0x5a4d     /* MZ   */
#define IMAGE_NT_SIGNATURE  0x00004550 /* PE00 */

PVOID
PeFindExportByName(_In_ PVOID Image, _In_ PCHAR Name);

PNT_HEADER_64
PeGetNtHeader(_In_ PVOID Image);

PIMAGE_DATA_DIRECTORY
PeGetExportDataDirectory(_In_ PVOID Image);

PIMAGE_EXPORT_DIRECTORY
PeGetExportDirectory(_In_ PVOID                 Image,
                     _In_ PIMAGE_DATA_DIRECTORY ExportDataDirectory);

UINT32
GetSectionCount(_In_ PNT_HEADER_64 Header);

#endif