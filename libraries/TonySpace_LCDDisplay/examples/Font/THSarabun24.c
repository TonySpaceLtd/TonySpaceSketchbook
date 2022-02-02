/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef THSARABUN24
#define THSARABUN24 1
#endif

#if THSARABUN24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xa0,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x22, 0x22, 0x22, 0xff, 0x44, 0x44, 0x44, 0xff,
    0x44, 0x44, 0x44,

    /* U+0024 "$" */
    0x21, 0xec, 0x20, 0x81, 0x3, 0x2, 0x4, 0x18,
    0xfc, 0x20, 0x80,

    /* U+0025 "%" */
    0x70, 0x88, 0x88, 0x89, 0x8, 0x90, 0x8a, 0xe7,
    0x5b, 0x5, 0x10, 0x91, 0x9, 0x11, 0x1b, 0x20,
    0xe0,

    /* U+0026 "&" */
    0x3c, 0x18, 0x84, 0x21, 0x10, 0x38, 0x14, 0x18,
    0x8a, 0x1a, 0x83, 0x30, 0xe3, 0xc4,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x12, 0x44, 0x88, 0x88, 0x88, 0x44, 0x22,

    /* U+0029 ")" */
    0x84, 0x22, 0x11, 0x11, 0x11, 0x22, 0x44,

    /* U+002A "*" */
    0x28, 0xcf, 0xca, 0x48,

    /* U+002B "+" */
    0x8, 0x4, 0x2, 0x1f, 0xf0, 0x80, 0x40, 0x20,
    0x10,

    /* U+002C "," */
    0xd8,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x4, 0x8, 0x20, 0x41, 0x2, 0x8, 0x10, 0x40,
    0x82, 0x4, 0x0,

    /* U+0030 "0" */
    0x38, 0x8b, 0x14, 0x18, 0x30, 0x60, 0xc1, 0x44,
    0x88, 0xe0,

    /* U+0031 "1" */
    0x23, 0x28, 0x42, 0x10, 0x84, 0x21, 0x3e,

    /* U+0032 "2" */
    0x3c, 0x8d, 0x8, 0x10, 0x41, 0x82, 0x8, 0x61,
    0x83, 0xf8,

    /* U+0033 "3" */
    0x39, 0x88, 0x10, 0x43, 0xc0, 0xc0, 0x81, 0x3,
    0x1b, 0xe0,

    /* U+0034 "4" */
    0x4, 0x1c, 0x24, 0x44, 0x44, 0x84, 0x84, 0x84,
    0xff, 0x4, 0x4,

    /* U+0035 "5" */
    0x7e, 0x81, 0x2, 0x7, 0x88, 0xc0, 0x81, 0x2,
    0xb, 0xe0,

    /* U+0036 "6" */
    0xc, 0x20, 0x82, 0xf, 0x98, 0xa0, 0xc1, 0x82,
    0x88, 0xf0,

    /* U+0037 "7" */
    0xfe, 0x8, 0x20, 0x41, 0x2, 0x4, 0x10, 0x20,
    0x40, 0x80,

    /* U+0038 "8" */
    0x7d, 0x8e, 0xc, 0x16, 0xcf, 0xa0, 0xc1, 0x83,
    0x8d, 0xf0,

    /* U+0039 "9" */
    0x78, 0x8a, 0xc, 0x18, 0x28, 0xcf, 0x82, 0x8,
    0x21, 0x80,

    /* U+003A ":" */
    0x82,

    /* U+003B ";" */
    0x80, 0xf, 0x80,

    /* U+003C "<" */
    0x1, 0x6, 0x18, 0x20, 0xc0, 0x60, 0x10, 0xc,
    0x3,

    /* U+003D "=" */
    0xff, 0x0, 0x0, 0xff,

    /* U+003E ">" */
    0x0, 0xc0, 0x30, 0xc, 0x3, 0x6, 0x18, 0x60,
    0x80,

    /* U+003F "?" */
    0xf0, 0x42, 0x11, 0x11, 0x8, 0x40, 0x10,

    /* U+0040 "@" */
    0xf, 0x83, 0x6, 0x4e, 0x2c, 0x11, 0x8f, 0x19,
    0x91, 0x91, 0x19, 0x32, 0x4d, 0xc6, 0x0, 0x1e,
    0x0,

    /* U+0041 "A" */
    0x8, 0x3, 0x1, 0x40, 0x48, 0x12, 0x8, 0x82,
    0x11, 0xfc, 0x41, 0x90, 0x28, 0x8,

    /* U+0042 "B" */
    0xf9, 0xe, 0xc, 0x18, 0x5f, 0x21, 0xc1, 0x83,
    0xf, 0xe0,

    /* U+0043 "C" */
    0x1f, 0x10, 0x10, 0x10, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x40, 0x10, 0x7, 0xc0,

    /* U+0044 "D" */
    0xf8, 0x86, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x82, 0x86, 0xf8,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0x83, 0xf8, 0x20, 0x82, 0xf,
    0xc0,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x2, 0x0,

    /* U+0047 "G" */
    0x1f, 0x10, 0x10, 0x10, 0x8, 0x4, 0x3e, 0x3,
    0x1, 0x40, 0xb0, 0x47, 0xe0,

    /* U+0048 "H" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81,
    0x81, 0x81, 0x81,

    /* U+0049 "I" */
    0xff, 0xe0,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x84, 0x21, 0x8, 0xfc,

    /* U+004B "K" */
    0x82, 0x84, 0x88, 0x90, 0xa0, 0xf0, 0x90, 0x88,
    0x84, 0x82, 0x81,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x3, 0xf8,

    /* U+004D "M" */
    0xc0, 0x78, 0x1f, 0x3, 0xd0, 0xba, 0x13, 0x22,
    0x64, 0x8c, 0x91, 0x8a, 0x31, 0x86, 0x10, 0x80,

    /* U+004E "N" */
    0x81, 0xc1, 0xa1, 0xa1, 0x91, 0x99, 0x89, 0x85,
    0x85, 0x83, 0x81,

    /* U+004F "O" */
    0x1f, 0x4, 0x11, 0x1, 0x40, 0x18, 0x3, 0x0,
    0x60, 0xc, 0x1, 0x40, 0x44, 0x10, 0x7c, 0x0,

    /* U+0050 "P" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x2, 0x0,

    /* U+0051 "Q" */
    0x1f, 0x4, 0x11, 0x1, 0x40, 0x18, 0x3, 0x0,
    0x60, 0xc, 0x1, 0x40, 0x44, 0x10, 0x7c, 0x0,
    0xe0,

    /* U+0052 "R" */
    0xf9, 0xe, 0xc, 0x18, 0x5f, 0x21, 0x42, 0x83,
    0x6, 0x8,

    /* U+0053 "S" */
    0x7d, 0x82, 0x4, 0x4, 0x7, 0x1, 0x1, 0x3,
    0xf, 0xe0,

    /* U+0054 "T" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+0055 "U" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0xc1, 0xb1, 0x8f, 0x80,

    /* U+0056 "V" */
    0x80, 0xa0, 0x50, 0x48, 0x22, 0x11, 0x10, 0x88,
    0x24, 0x14, 0x6, 0x2, 0x0,

    /* U+0057 "W" */
    0x83, 0x7, 0xc, 0x14, 0x30, 0x91, 0x42, 0x44,
    0x88, 0x92, 0x42, 0x49, 0xa, 0x14, 0x18, 0x60,
    0x61, 0x81, 0x82, 0x0,

    /* U+0058 "X" */
    0x40, 0x88, 0x42, 0x10, 0x48, 0xc, 0x3, 0x0,
    0xc0, 0x48, 0x21, 0x18, 0x64, 0x8,

    /* U+0059 "Y" */
    0x80, 0xa0, 0x88, 0x84, 0x41, 0x40, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+005A "Z" */
    0x7f, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x40, 0x60, 0x20, 0x3f, 0xe0,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0xc0,

    /* U+005C "\\" */
    0x81, 0x1, 0x2, 0x2, 0x4, 0x4, 0x8, 0x8,
    0x10, 0x10, 0x20,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x93, 0xc0,

    /* U+005E "^" */
    0x10, 0x18, 0x28, 0x24, 0x24, 0x42, 0x42, 0x81,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0x48,

    /* U+0061 "a" */
    0x78, 0x30, 0x4f, 0xc6, 0x18, 0xdd,

    /* U+0062 "b" */
    0x80, 0x80, 0x80, 0xbc, 0xc2, 0x81, 0x81, 0x81,
    0x81, 0xc2, 0xbc,

    /* U+0063 "c" */
    0x3e, 0x82, 0x4, 0x8, 0x10, 0x10, 0x9f,

    /* U+0064 "d" */
    0x1, 0x1, 0x1, 0x3d, 0x43, 0x81, 0x81, 0x81,
    0x81, 0x43, 0x3d,

    /* U+0065 "e" */
    0x3c, 0x42, 0x81, 0xff, 0x80, 0x80, 0x41, 0x3e,

    /* U+0066 "f" */
    0x3b, 0x10, 0x8f, 0x21, 0x8, 0x42, 0x10, 0x80,

    /* U+0067 "g" */
    0x7f, 0x28, 0x61, 0x4d, 0xe4, 0xc, 0xc, 0x10,
    0x5e,

    /* U+0068 "h" */
    0x81, 0x2, 0x5, 0xec, 0x70, 0x60, 0xc1, 0x83,
    0x6, 0x8,

    /* U+0069 "i" */
    0x9f, 0xe0,

    /* U+006A "j" */
    0x20, 0x12, 0x49, 0x24, 0x92, 0xf0,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x8, 0xd2, 0x38, 0x50, 0x91,
    0x12, 0x10,

    /* U+006C "l" */
    0x92, 0x49, 0x24, 0x99, 0x80,

    /* U+006D "m" */
    0xb9, 0xd9, 0x4e, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xc, 0x21,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1,

    /* U+006F "o" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+0070 "p" */
    0xbc, 0xc2, 0x81, 0x81, 0x81, 0x81, 0xc2, 0xbc,
    0x80, 0x80, 0x80, 0x80,

    /* U+0071 "q" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,
    0x1, 0x1, 0x1, 0x1,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88,

    /* U+0073 "s" */
    0x74, 0x20, 0x83, 0x4, 0x3e,

    /* U+0074 "t" */
    0x20, 0x82, 0x3f, 0x20, 0x82, 0x8, 0x20, 0x81,
    0x80,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x71, 0xbd,

    /* U+0076 "v" */
    0x81, 0x42, 0x42, 0x22, 0x24, 0x24, 0x18, 0x18,

    /* U+0077 "w" */
    0x86, 0x14, 0x61, 0x46, 0x24, 0x92, 0x49, 0x23,
    0x14, 0x30, 0xc1, 0x8,

    /* U+0078 "x" */
    0x42, 0x44, 0x28, 0x18, 0x18, 0x24, 0x44, 0x82,

    /* U+0079 "y" */
    0x81, 0x42, 0x42, 0x24, 0x24, 0x14, 0x18, 0x8,
    0x10, 0x20, 0x60,

    /* U+007A "z" */
    0xfe, 0x8, 0x20, 0xc1, 0x4, 0x10, 0x7f,

    /* U+007B "{" */
    0x34, 0x44, 0x44, 0x84, 0x44, 0x44, 0x30,

    /* U+007C "|" */
    0xff, 0xff,

    /* U+007D "}" */
    0xc2, 0x22, 0x22, 0x12, 0x22, 0x22, 0xc0,

    /* U+007E "~" */
    0x78, 0xc3, 0x80,

    /* U+0E00 "฀" */
    0x0,

    /* U+0E01 "ก" */
    0x3c, 0x62, 0x41, 0x21, 0x41, 0x41, 0x41, 0x41,
    0x41, 0x41,

    /* U+0E02 "ข" */
    0x73, 0xd6, 0xaf, 0x51, 0x22, 0x44, 0x89, 0x12,
    0x18,

    /* U+0E03 "ฃ" */
    0x51, 0xa9, 0xe9, 0xa9, 0xf1, 0x11, 0x11, 0x11,
    0x11, 0xe,

    /* U+0E04 "ค" */
    0x3c, 0x8e, 0x6d, 0x5b, 0xb8, 0x50, 0xa1, 0x42,
    0x84,

    /* U+0E05 "ฅ" */
    0x6d, 0xae, 0xc, 0xda, 0xb7, 0x50, 0xa1, 0x42,
    0x84,

    /* U+0E06 "ฆ" */
    0x59, 0xa9, 0xe9, 0xa9, 0xf1, 0x11, 0x39, 0x4f,
    0x4b, 0x31,

    /* U+0E07 "ง" */
    0x39, 0x4e, 0x18, 0xa5, 0x25, 0x18, 0x40,

    /* U+0E08 "จ" */
    0x7d, 0x8c, 0xb, 0x15, 0x2e, 0x44, 0x89, 0xa,
    0x1c,

    /* U+0E09 "ฉ" */
    0x7c, 0xc6, 0x2, 0x62, 0xa2, 0xa2, 0xc6, 0x4e,
    0x79, 0x6f,

    /* U+0E0A "ช" */
    0x73, 0xd6, 0xaf, 0x51, 0x22, 0x44, 0x89, 0x12,
    0x18,

    /* U+0E0B "ซ" */
    0x51, 0xab, 0xeb, 0xa9, 0xf1, 0x11, 0x11, 0x11,
    0x11, 0xe,

    /* U+0E0C "ฌ" */
    0x78, 0x63, 0x18, 0x45, 0x11, 0x84, 0x61, 0x18,
    0x47, 0xb9, 0xab, 0xfb, 0x90,

    /* U+0E0D "ญ" */
    0x3c, 0x28, 0xc5, 0x8, 0x91, 0x14, 0x22, 0x84,
    0x50, 0x8b, 0x91, 0x92, 0x2e, 0x38, 0xc, 0x81,
    0x90, 0x34, 0x3, 0x80,

    /* U+0E0E "ฎ" */
    0x1e, 0x63, 0x41, 0x11, 0x21, 0x21, 0x61, 0xa1,
    0xa1, 0x61, 0x1, 0x9, 0x39, 0x4f, 0x71,

    /* U+0E0F "ฏ" */
    0x1e, 0x63, 0x41, 0x11, 0x21, 0x21, 0x61, 0xa1,
    0xa1, 0x61, 0x1, 0x11, 0xf1, 0x9f, 0xe1,

    /* U+0E10 "ฐ" */
    0x3f, 0x40, 0x3c, 0x32, 0x52, 0x52, 0x32, 0x12,
    0x12, 0x1c, 0x0, 0x16, 0xe6, 0xb6, 0xca,

    /* U+0E11 "ฑ" */
    0x51, 0xd5, 0x7a, 0xb5, 0x9f, 0x48, 0xa4, 0x62,
    0x31, 0x18, 0x88, 0x40,

    /* U+0E12 "ฒ" */
    0x6c, 0x32, 0x46, 0x8, 0xdd, 0x1a, 0xa3, 0xf4,
    0x54, 0x8b, 0x3d, 0x65, 0x68, 0xe4,

    /* U+0E13 "ณ" */
    0x3c, 0x24, 0x62, 0xc2, 0x22, 0x22, 0x42, 0x24,
    0x22, 0x72, 0x65, 0x2d, 0x93, 0x57, 0x27,

    /* U+0E14 "ด" */
    0x3c, 0x8e, 0xed, 0x5b, 0xba, 0x54, 0xb1, 0x42,
    0x84,

    /* U+0E15 "ต" */
    0x6d, 0xb6, 0xd, 0xda, 0xb7, 0x54, 0xb1, 0x62,
    0x84,

    /* U+0E16 "ถ" */
    0x3c, 0x62, 0x41, 0x61, 0x41, 0x41, 0x41, 0x71,
    0x91, 0x71,

    /* U+0E17 "ท" */
    0xe3, 0xd3, 0x79, 0x24, 0x92, 0x89, 0x44, 0xc2,
    0x61, 0x30, 0x90, 0x40,

    /* U+0E18 "ธ" */
    0x7d, 0x1, 0xe0, 0x64, 0x48, 0x91, 0x22, 0x44,
    0x70,

    /* U+0E19 "น" */
    0xe1, 0x50, 0xb8, 0x44, 0x22, 0x11, 0x8, 0x8c,
    0x4d, 0x3a, 0x99, 0xc0,

    /* U+0E1A "บ" */
    0xe0, 0xd0, 0x78, 0x24, 0x12, 0x9, 0x4, 0x82,
    0x41, 0x31, 0x8f, 0x80,

    /* U+0E1B "ป" */
    0x0, 0x80, 0x40, 0x20, 0x1e, 0xd, 0x7, 0x82,
    0x41, 0x20, 0x90, 0x48, 0x24, 0x13, 0x18, 0xf8,

    /* U+0E1C "ผ" */
    0xe3, 0x47, 0x8c, 0x18, 0x32, 0x6a, 0xe5, 0xc7,
    0x4,

    /* U+0E1D "ฝ" */
    0x2, 0x4, 0x8, 0x1e, 0x34, 0x78, 0xc1, 0x83,
    0x26, 0xae, 0x5c, 0x70, 0x40,

    /* U+0E1E "พ" */
    0xe4, 0xd6, 0x7a, 0xa5, 0x52, 0xa9, 0x94, 0xc6,
    0x63, 0x31, 0x90, 0x40,

    /* U+0E1F "ฟ" */
    0x0, 0x80, 0x40, 0x20, 0x1e, 0x4d, 0x67, 0xaa,
    0x55, 0x2a, 0x99, 0x4c, 0x66, 0x33, 0x19, 0x4,

    /* U+0E20 "ภ" */
    0x1e, 0x23, 0x41, 0x31, 0x21, 0x21, 0x21, 0xe1,
    0xa1, 0xe1,

    /* U+0E21 "ม" */
    0xe1, 0xa1, 0xe1, 0x21, 0x21, 0x21, 0x61, 0xb9,
    0xa7, 0xc3,

    /* U+0E22 "ย" */
    0x63, 0x47, 0x8c, 0x16, 0x30, 0x60, 0xc1, 0x86,
    0xf8,

    /* U+0E23 "ร" */
    0x7e, 0xf, 0x6, 0x8, 0x20, 0x8e, 0x28, 0xe0,

    /* U+0E24 "ฤ" */
    0x3c, 0x62, 0x41, 0x61, 0x41, 0x41, 0x41, 0x71,
    0x91, 0x71, 0x1, 0x1, 0x1, 0x1, 0x1,

    /* U+0E25 "ล" */
    0x3c, 0x43, 0x81, 0x3d, 0x63, 0x41, 0x41, 0x71,
    0x91, 0x71,

    /* U+0E26 "ฦ" */
    0x1e, 0x23, 0x41, 0x31, 0x21, 0x21, 0x21, 0xe1,
    0xa1, 0xe1, 0x1, 0x1, 0x1, 0x1, 0x1,

    /* U+0E27 "ว" */
    0x7a, 0x38, 0x41, 0x4, 0x10, 0x47, 0x14, 0x70,

    /* U+0E28 "ศ" */
    0x2, 0x79, 0x14, 0xda, 0xb7, 0x70, 0xa1, 0x42,
    0x85, 0x8,

    /* U+0E29 "ษ" */
    0xe0, 0xa8, 0x2e, 0xc8, 0xaa, 0x2c, 0xc9, 0xe2,
    0x8, 0x82, 0x31, 0x87, 0xc0,

    /* U+0E2A "ส" */
    0x1, 0x3d, 0x42, 0x5, 0x3d, 0x63, 0x41, 0x41,
    0x71, 0x91, 0x71,

    /* U+0E2B "ห" */
    0xe3, 0xd1, 0x78, 0x44, 0x52, 0x49, 0x44, 0xa2,
    0x61, 0x30, 0x90, 0x40,

    /* U+0E2C "ฬ" */
    0x0, 0x78, 0xea, 0x2b, 0x8e, 0x20, 0x89, 0x22,
    0xa8, 0xaa, 0x31, 0x8c, 0x62, 0x8,

    /* U+0E2D "อ" */
    0x3d, 0x8e, 0xb, 0x99, 0x2e, 0x50, 0xa1, 0x42,
    0x78,

    /* U+0E2E "ฮ" */
    0x79, 0x86, 0xfa, 0x62, 0xd2, 0x92, 0xe2, 0x82,
    0xc6, 0x7c,

    /* U+0E2F "ฯ" */
    0xef, 0x55, 0xc8, 0x10, 0x20, 0x40, 0x81, 0x2,
    0x4,

    /* U+0E30 "ะ" */
    0xe3, 0x47, 0x93, 0xc0, 0x1c, 0x68, 0xf2, 0x78,

    /* U+0E31 "ั" */
    0xe3, 0x47, 0x93, 0xc0,

    /* U+0E32 "า" */
    0x7b, 0x38, 0x41, 0x4, 0x10, 0x41, 0x4, 0x10,

    /* U+0E33 "ำ" */
    0x60, 0x24, 0x9, 0x1, 0x80, 0x0, 0x0, 0xe0,
    0x44, 0x11, 0x0, 0x40, 0x10, 0x4, 0x1, 0x0,
    0x40, 0x10, 0x4,

    /* U+0E34 "ิ" */
    0x79, 0x8b, 0xe8, 0x30,

    /* U+0E35 "ี" */
    0x2, 0xf6, 0x1f, 0xd0, 0x60,

    /* U+0E36 "ึ" */
    0x2, 0x7e, 0xc6, 0xfa, 0x6,

    /* U+0E37 "ื" */
    0xa, 0xf7, 0x1f, 0xd0, 0x60,

    /* U+0E38 "ุ" */
    0x75, 0x92,

    /* U+0E39 "ู" */
    0x6d, 0x5a, 0x53, 0x80,

    /* U+0E3A "ฺ" */
    0x80,

    /* U+0E3F "฿" */
    0x20, 0x8f, 0xa3, 0x86, 0x18, 0xfc, 0x8e, 0x18,
    0x63, 0xf0, 0x82, 0x0,

    /* U+0E40 "เ" */
    0x92, 0x49, 0x27, 0xbc,

    /* U+0E41 "แ" */
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xee,
    0xa9, 0xe6,

    /* U+0E42 "โ" */
    0x62, 0x6c, 0x8, 0x10, 0x41, 0x4, 0x10, 0x41,
    0x4, 0x10, 0x41, 0xc9, 0x1c,

    /* U+0E43 "ใ" */
    0x72, 0x2c, 0xb2, 0xd0, 0x41, 0x4, 0x10, 0x41,
    0x4, 0x10, 0x41, 0xc9, 0x1c,

    /* U+0E44 "ไ" */
    0x92, 0xcd, 0x34, 0x10, 0x41, 0x4, 0x10, 0x41,
    0x4, 0x10, 0x41, 0xc9, 0x1c,

    /* U+0E45 "ๅ" */
    0x7b, 0x38, 0x41, 0x4, 0x10, 0x41, 0x4, 0x10,
    0x41, 0x4, 0x10, 0x40,

    /* U+0E46 "ๆ" */
    0x6d, 0x27, 0x8d, 0x1a, 0x2c, 0x40, 0x81, 0x2,
    0x4, 0x8, 0x10, 0x20, 0x40, 0x80,

    /* U+0E47 "็" */
    0x4, 0x17, 0xa3, 0xf7, 0x70,

    /* U+0E48 "่" */
    0xe0,

    /* U+0E49 "้" */
    0xc7, 0x2c, 0x94, 0xa0,

    /* U+0E4A "๊" */
    0xfb, 0x5f, 0x70,

    /* U+0E4B "๋" */
    0x5d, 0x0,

    /* U+0E4C "์" */
    0x12, 0xcc, 0xc0,

    /* U+0E4D "ํ" */
    0x69, 0x96,

    /* U+0E4E "๎" */
    0x74, 0x68, 0xe0,

    /* U+0E4F "๏" */
    0x3c, 0x42, 0xdf, 0xa3, 0xa3, 0xa3, 0xdf, 0x42,
    0x3c,

    /* U+0E50 "๐" */
    0x3e, 0x21, 0xa0, 0x30, 0x18, 0xc, 0x5, 0x4,
    0x7c,

    /* U+0E51 "๑" */
    0x3e, 0x21, 0xa2, 0x72, 0x99, 0x4c, 0xe5, 0x22,
    0xf2,

    /* U+0E52 "๒" */
    0xc0, 0x10, 0x4, 0x1, 0x0, 0x4d, 0x94, 0x95,
    0xe5, 0x51, 0x5c, 0x50, 0x12, 0x8, 0x7c,

    /* U+0E53 "๓" */
    0x7b, 0x66, 0x61, 0x30, 0x9f, 0x4c, 0xa5, 0xd2,

    /* U+0E54 "๔" */
    0x0, 0x40, 0x23, 0xf1, 0x0, 0x9c, 0x25, 0x9,
    0x42, 0x20, 0x46, 0x1f, 0xe0, 0x0,

    /* U+0E55 "๕" */
    0xe, 0x1, 0x48, 0x3b, 0x1f, 0xc4, 0x1, 0x38,
    0x25, 0x4, 0xa0, 0x88, 0x8, 0xc0, 0xff, 0x0,
    0x20,

    /* U+0E56 "๖" */
    0x80, 0x60, 0x17, 0x8c, 0x20, 0x8, 0x5, 0xc2,
    0xa1, 0x71, 0x1f, 0x0,

    /* U+0E57 "๗" */
    0x0, 0x40, 0x17, 0x65, 0x65, 0x89, 0x62, 0x58,
    0x97, 0xc5, 0x92, 0x9c, 0xc0,

    /* U+0E58 "๘" */
    0x0, 0x80, 0x40, 0x67, 0xe4, 0x4, 0xe, 0xb,
    0x25, 0xab, 0xa3, 0x80,

    /* U+0E59 "๙" */
    0x0, 0x40, 0x13, 0x25, 0x37, 0x84, 0x20, 0x88,
    0x22, 0xe4, 0x68, 0x8e, 0x30,

    /* U+0E5A "๚" */
    0xee, 0xea, 0xd7, 0x24, 0x9, 0x2, 0x40, 0x90,
    0x24, 0x9, 0x2, 0x40, 0x90,

    /* U+0E5B "๛" */
    0x70, 0x3, 0x20, 0xb, 0xad, 0x2a, 0xbe, 0xab,
    0xde, 0xdf, 0x4, 0x40, 0xe, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 83, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 56, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 80, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 5, .adv_w = 155, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 139, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 27, .adv_w = 225, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 162, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 46, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 59, .adv_w = 73, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 66, .adv_w = 73, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 73, .adv_w = 109, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 77, .adv_w = 158, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 62, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 87, .adv_w = 83, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 88, .adv_w = 62, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 104, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 100, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 139, .box_w = 5, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 139, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 62, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 62, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 202, .adv_w = 158, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 158, .box_w = 8, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 215, .adv_w = 158, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 109, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 206, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 248, .adv_w = 154, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 145, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 156, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 166, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 296, .adv_w = 135, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 163, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 169, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 56, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 101, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 210, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 169, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 187, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 145, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 187, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 439, .adv_w = 146, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 146, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 179, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 150, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 226, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 161, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 141, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 163, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 558, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 564, .adv_w = 101, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 575, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 581, .adv_w = 158, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 589, .adv_w = 135, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 590, .adv_w = 78, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 591, .adv_w = 132, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 597, .adv_w = 154, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 608, .adv_w = 127, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 154, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 144, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 79, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 642, .adv_w = 119, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 651, .adv_w = 150, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 661, .adv_w = 55, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 663, .adv_w = 60, .box_w = 3, .box_h = 15, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 669, .adv_w = 121, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 77, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 684, .adv_w = 231, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 695, .adv_w = 150, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 702, .adv_w = 153, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 710, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 722, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 734, .adv_w = 83, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 108, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 743, .adv_w = 91, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 752, .adv_w = 150, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 759, .adv_w = 131, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 767, .adv_w = 195, .box_w = 12, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 779, .adv_w = 122, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 787, .adv_w = 129, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 798, .adv_w = 123, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 805, .adv_w = 80, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 812, .adv_w = 59, .box_w = 1, .box_h = 16, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 814, .adv_w = 80, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 821, .adv_w = 160, .box_w = 9, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 824, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 825, .adv_w = 148, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 835, .adv_w = 145, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 844, .adv_w = 147, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 854, .adv_w = 151, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 863, .adv_w = 151, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 872, .adv_w = 157, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 882, .adv_w = 113, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 898, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 908, .adv_w = 146, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 917, .adv_w = 147, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 199, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 940, .adv_w = 199, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 960, .adv_w = 163, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 975, .adv_w = 163, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 990, .adv_w = 132, .box_w = 8, .box_h = 15, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 1005, .adv_w = 177, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1017, .adv_w = 204, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1031, .adv_w = 209, .box_w = 12, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1046, .adv_w = 150, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1055, .adv_w = 150, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1064, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1074, .adv_w = 165, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1086, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1095, .adv_w = 161, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1107, .adv_w = 164, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1119, .adv_w = 164, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1135, .adv_w = 146, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1144, .adv_w = 146, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1157, .adv_w = 172, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1169, .adv_w = 172, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1185, .adv_w = 163, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1195, .adv_w = 154, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1205, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1214, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1222, .adv_w = 145, .box_w = 8, .box_h = 15, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 1237, .adv_w = 146, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1247, .adv_w = 163, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1262, .adv_w = 129, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1270, .adv_w = 151, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1280, .adv_w = 168, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1293, .adv_w = 146, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1304, .adv_w = 164, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1316, .adv_w = 174, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1330, .adv_w = 149, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1339, .adv_w = 143, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1349, .adv_w = 150, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1358, .adv_w = 137, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1366, .adv_w = 0, .box_w = 7, .box_h = 4, .ofs_x = -6, .ofs_y = 12},
    {.bitmap_index = 1370, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1378, .adv_w = 121, .box_w = 10, .box_h = 15, .ofs_x = -4, .ofs_y = 0},
    {.bitmap_index = 1397, .adv_w = 0, .box_w = 7, .box_h = 4, .ofs_x = -8, .ofs_y = 11},
    {.bitmap_index = 1401, .adv_w = 0, .box_w = 7, .box_h = 5, .ofs_x = -8, .ofs_y = 11},
    {.bitmap_index = 1406, .adv_w = 0, .box_w = 8, .box_h = 5, .ofs_x = -8, .ofs_y = 11},
    {.bitmap_index = 1411, .adv_w = 0, .box_w = 7, .box_h = 5, .ofs_x = -8, .ofs_y = 11},
    {.bitmap_index = 1416, .adv_w = 0, .box_w = 3, .box_h = 5, .ofs_x = -4, .ofs_y = -6},
    {.bitmap_index = 1418, .adv_w = 0, .box_w = 5, .box_h = 5, .ofs_x = -7, .ofs_y = -6},
    {.bitmap_index = 1422, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = -2, .ofs_y = -2},
    {.bitmap_index = 1423, .adv_w = 158, .box_w = 6, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1435, .adv_w = 78, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1439, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1449, .adv_w = 91, .box_w = 6, .box_h = 17, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1462, .adv_w = 93, .box_w = 6, .box_h = 17, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1475, .adv_w = 94, .box_w = 6, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1488, .adv_w = 79, .box_w = 6, .box_h = 15, .ofs_x = -2, .ofs_y = -5},
    {.bitmap_index = 1500, .adv_w = 153, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1514, .adv_w = 0, .box_w = 6, .box_h = 6, .ofs_x = -7, .ofs_y = 11},
    {.bitmap_index = 1519, .adv_w = 0, .box_w = 1, .box_h = 3, .ofs_x = -2, .ofs_y = 17},
    {.bitmap_index = 1520, .adv_w = 0, .box_w = 6, .box_h = 5, .ofs_x = -4, .ofs_y = 16},
    {.bitmap_index = 1524, .adv_w = 0, .box_w = 7, .box_h = 3, .ofs_x = -7, .ofs_y = 17},
    {.bitmap_index = 1527, .adv_w = 0, .box_w = 3, .box_h = 3, .ofs_x = -3, .ofs_y = 17},
    {.bitmap_index = 1529, .adv_w = 0, .box_w = 4, .box_h = 5, .ofs_x = -4, .ofs_y = 16},
    {.bitmap_index = 1532, .adv_w = 0, .box_w = 4, .box_h = 4, .ofs_x = -4, .ofs_y = 11},
    {.bitmap_index = 1534, .adv_w = 0, .box_w = 4, .box_h = 5, .ofs_x = -5, .ofs_y = 11},
    {.bitmap_index = 1537, .adv_w = 173, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1546, .adv_w = 172, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1555, .adv_w = 172, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1564, .adv_w = 172, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1579, .adv_w = 172, .box_w = 9, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1587, .adv_w = 172, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1601, .adv_w = 172, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1618, .adv_w = 172, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1630, .adv_w = 172, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1643, .adv_w = 172, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1655, .adv_w = 172, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1668, .adv_w = 200, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1681, .adv_w = 268, .box_w = 14, .box_h = 8, .ofs_x = 2, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 3584, .range_length = 59, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 3647, .range_length = 29, .glyph_id_start = 155,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    34, 53,
    34, 55,
    34, 56,
    34, 58,
    34, 90,
    39, 34,
    45, 53,
    45, 55,
    45, 56,
    45, 58,
    49, 34,
    49, 43,
    53, 34,
    53, 43,
    53, 66,
    53, 68,
    53, 70,
    53, 72,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 83,
    53, 84,
    53, 86,
    53, 87,
    53, 88,
    53, 89,
    53, 90,
    53, 91,
    55, 34,
    55, 43,
    55, 68,
    55, 70,
    55, 72,
    55, 80,
    55, 82,
    55, 84,
    56, 34,
    56, 68,
    56, 70,
    56, 72,
    56, 80,
    56, 82,
    56, 84,
    58, 34,
    58, 66,
    58, 68,
    58, 70,
    58, 72,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 86,
    156, 98,
    156, 99,
    156, 104,
    156, 106,
    156, 107,
    156, 113,
    156, 131,
    156, 135,
    157, 98,
    157, 99,
    157, 104,
    157, 106,
    157, 107,
    157, 113,
    157, 131,
    157, 135,
    158, 98,
    158, 99,
    158, 104,
    158, 106,
    158, 107,
    158, 113,
    158, 131,
    158, 135,
    159, 98,
    159, 99,
    159, 104,
    159, 106,
    159, 107,
    159, 113,
    159, 131,
    159, 135,
    160, 98,
    160, 99,
    160, 104,
    160, 106,
    160, 107,
    160, 113,
    160, 131,
    160, 135
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -15, -19, -17, -15, -6, -15, -31, -31,
    -27, -27, -19, -23, -15, -15, -12, -12,
    -12, -13, -12, -12, -12, -12, -12, -12,
    -12, -12, -12, -12, -12, -12, -12, -19,
    -15, -12, -12, -12, -12, -12, -8, -17,
    -8, -8, -8, -8, -8, -8, -15, -8,
    -10, -10, -10, -8, -8, -10, -8, -10,
    -8, -10, -8, -12, -12, -8, -12, -12,
    -12, -10, -8, -12, -12, -8, -12, -12,
    -8, -10, -8, -12, -12, -8, -12, -12,
    -12, -10, -8, -12, -12, -8, -12, -12,
    -12, -10, -8, -12, -12, -8, -12, -12,
    -12, -10, -8
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 99,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t THSarabun24 = {
#else
lv_font_t THSarabun24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 27,          /*The maximum line height required by the font*/
    .base_line = 6,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if THSARABUN24*/

