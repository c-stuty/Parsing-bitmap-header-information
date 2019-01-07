### 程序说明

解析 bitmap 格式图片信息。

### 编译执行

    user@ubuntu:~/work/c-study/Parsing-bitmap-header-information$ make
    gcc -o app main.c
    user@ubuntu:~/work/c-study/Parsing-bitmap-header-information$ ./app 
    usage: ./app xxx.bmp
    eg   : ./app demo.bmp

    user@ubuntu:~/work/c-study/Parsing-bitmap-header-information$ ./app demo.bmp 
    ------------------------------------------------
    BITMAP FILE HEADER
    ------------------------------------------------
    [2] file_header.bfType          = 0x4d42, 19778
    [4] file_header.bfSize          = 0x66, 102
    [2] file_header.bfReserved1     = 0x0, 0
    [2] file_header.bfReserved2     = 0x0, 0
    [4] file_header.bfOffBits       = 0x36, 54

    ------------------------------------------------
    BITMAP INFO HEADER
    ------------------------------------------------
    [4] info_header.biSize          = 0x28, 40
    [4] info_header.biWidth         = 0x4, 4
    [4] info_header.biHeight        = 0x4, 4
    [2] info_header.biPlanes        = 0x1, 1
    [2] info_header.biBitCount      = 0x18, 24
    [4] info_header.biCompression   = 0x0, 0
    [4] info_header.biSizeImage     = 0x30, 48
    [4] info_header.biXPelsPerMeter = 0x0, 0
    [4] info_header.biYPelsPerMeter = 0x0, 0
    [4] info_header.biClrUsed       = 0x0, 0
    [4] info_header.biClrImportant  = 0x0, 0

### 背景知识

BITMAP 图像数据的存储格式是：B G R。扫描方式为从左往右，从上往下。

