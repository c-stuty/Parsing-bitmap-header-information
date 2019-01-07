#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define DEBUG

#if defined(DEBUG)
#define debug printf
#else
#define debug
#endif

#define WORD unsigned short int
#define DWORD unsigned int
#define LONG unsigned int

typedef struct tagBITMAPFILEHEADER
{
    WORD bfType;                            // 位图文件的类型，必须为BM(1-2字节)
    DWORD bfSize;                           // 位图文件的大小，以字节为单位(3-6字节，低位在前)
    WORD bfReserved1;                       // 位图文件保留字，必须为0(7-8字节)
    WORD bfReserved2;                       // 位图文件保留字，必须为0(9-10字节)
    DWORD bfOffBits;                        // 位图数据的起始位置，以相对于位图(11-14字节，低位在前)
} __attribute__((packed)) BITMAPFILEHEADER; // 文件头的偏移量表示，以字节为单位

typedef struct tagBITMAPINFOHEADER
{
    DWORD biSize;         // 本结构所占用字节数(15-18字节)
    LONG biWidth;         // 位图的宽度，以像素为单位(19-22字节)
    LONG biHeight;        // 位图的高度，以像素为单位(23-26字节)
    WORD biPlanes;        // 目标设备的级别，必须为1(27-28字节)
    WORD biBitCount;      // 每个像素所需的位数，必须是1(双色)，(29-30字节) 4(16色)，8(256色)16(高彩色)或24(真彩色)之一
    DWORD biCompression;  // 位图压缩类型，必须是0(不压缩)，(31-34字节) 1(BI_RLE8压缩类型)或2(BI_RLE4压缩类型)之一
    DWORD biSizeImage;    // 位图的大小(其中包含了为了补齐行数是4的倍数而添加的空字节)，以字节为单位(35-38字节)
    LONG biXPelsPerMeter; // 位图水平分辨率，每米像素数(39-42字节)
    LONG biYPelsPerMeter; // 位图垂直分辨率，每米像素数(43-46字节)
    DWORD biClrUsed;      // 位图实际使用的颜色表中的颜色数(47-50字节)
    DWORD biClrImportant; // 位图显示过程中重要的颜色数(51-54字节)
} __attribute__((packed)) BITMAPINFOHEADER;

int main(int argc, char const *argv[])
{
    char bmp_name[16];
    FILE *bmp_file = NULL;

    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;

    /* 打印函数使用方法 */
    if (argc != 2)
    {
        printf("usage: ./app xxx.bmp\n");
        printf("eg   : ./app demo.bmp\n");
        printf("\n");
        return -1;
    }

    strcpy(bmp_name, argv[1]);
    debug("bmp_name = %s\n", bmp_name);

    bmp_file = fopen(bmp_name, "r");
    if (bmp_file == NULL)
    {
        printf("err: can not open %s file\n", bmp_name);
        return -1;
    }

    debug("sizeof(WORD) = %lu\n", sizeof(WORD));
    debug("sizeof(DWORD) = %lu\n", sizeof(DWORD));
    debug("sizeof(LONG) = %lu\n", sizeof(LONG));
    debug("sizeof(BITMAPFILEHEADER) = %lu\n", sizeof(BITMAPFILEHEADER));
    debug("sizeof(BITMAPINFOHEADER) = %lu\n", sizeof(BITMAPINFOHEADER));
    fread(&file_header, 1, sizeof(BITMAPFILEHEADER), bmp_file);
    fread(&info_header, 1, sizeof(BITMAPINFOHEADER), bmp_file);
    fclose(bmp_file);

    printf("------------------------------------------------\n");
    printf(" BITMAP FILE HEADER\n");
    printf("------------------------------------------------\n");
    printf("[%lu] file_header.bfType          = 0x%x, %u\n", sizeof(file_header.bfType), file_header.bfType, file_header.bfType);
    printf("[%lu] file_header.bfSize          = 0x%x, %u\n", sizeof(file_header.bfSize), file_header.bfSize, file_header.bfSize);
    printf("[%lu] file_header.bfReserved1     = 0x%x, %u\n", sizeof(file_header.bfReserved1), file_header.bfReserved1, file_header.bfReserved1);
    printf("[%lu] file_header.bfReserved2     = 0x%x, %u\n", sizeof(file_header.bfReserved2), file_header.bfReserved2, file_header.bfReserved2);
    printf("[%lu] file_header.bfOffBits       = 0x%x, %u\n", sizeof(file_header.bfOffBits), file_header.bfOffBits, file_header.bfOffBits);
    printf("\n");

    printf("------------------------------------------------\n");
    printf(" BITMAP INFO HEADER\n");
    printf("------------------------------------------------\n");
    printf("[%lu] info_header.biSize          = 0x%x, %u\n", sizeof(info_header.biSize), info_header.biSize, info_header.biSize);
    printf("[%lu] info_header.biWidth         = 0x%x, %u\n", sizeof(info_header.biWidth), info_header.biWidth, info_header.biWidth);
    printf("[%lu] info_header.biHeight        = 0x%x, %u\n", sizeof(info_header.biHeight), info_header.biHeight, info_header.biHeight);
    printf("[%lu] info_header.biPlanes        = 0x%x, %u\n", sizeof(info_header.biPlanes), info_header.biPlanes, info_header.biPlanes);
    printf("[%lu] info_header.biBitCount      = 0x%x, %u\n", sizeof(info_header.biBitCount), info_header.biBitCount, info_header.biBitCount);
    printf("[%lu] info_header.biCompression   = 0x%x, %u\n", sizeof(info_header.biCompression), info_header.biCompression, info_header.biCompression);
    printf("[%lu] info_header.biSizeImage     = 0x%x, %u\n", sizeof(info_header.biSizeImage), info_header.biSizeImage, info_header.biSizeImage);
    printf("[%lu] info_header.biXPelsPerMeter = 0x%x, %u\n", sizeof(info_header.biXPelsPerMeter), info_header.biXPelsPerMeter, info_header.biXPelsPerMeter);
    printf("[%lu] info_header.biYPelsPerMeter = 0x%x, %u\n", sizeof(info_header.biYPelsPerMeter), info_header.biYPelsPerMeter, info_header.biYPelsPerMeter);
    printf("[%lu] info_header.biClrUsed       = 0x%x, %u\n", sizeof(info_header.biClrUsed), info_header.biClrUsed, info_header.biClrUsed);
    printf("[%lu] info_header.biClrImportant  = 0x%x, %u\n", sizeof(info_header.biClrImportant), info_header.biClrImportant, info_header.biClrImportant);
    printf("\n");

    return 0;
}
