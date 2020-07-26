#pragma once
#include <stdint.h>
#ifdef ON_WINDOWS
typedef enum _camera_pixel_format
{
	PixelFormatGray = 1,//灰度
	PixelFormatRGB565 = 2,
}camera_pixel_format_t;
typedef struct __img {
	camera_pixel_format_t format;
	uint16_t height;
	uint16_t width;
	void* pImg;
}img_t;
#include <stdio.h>
#define FIL FILE
#else
#include"sc_camera.h"
#endif // ON_WINDOWS

#pragma  pack(1)
typedef struct tagBITMAPFILEHEADER {
	/* bmfh 14bytes */
	uint16_t bfType;
	uint32_t bfSize;
	uint16_t bfReserved1;
	uint16_t bfReserved2;
	uint32_t bfOffBits;
} BITMAPFILEHEADER;

#pragma  pack(1)
typedef struct tagBITMAPINFOHEADER {
	/* bmih 54bytes */
	BITMAPFILEHEADER bmfh;
	uint32_t biSize;
	int32_t biWidth;
	int32_t biHeight;
	uint16_t biPlanes;
	uint16_t biBitCount;
	uint32_t biCompression;
	uint32_t biSizeImage;
	int32_t biXPelsPerMeter;
	int32_t biYPelsPerMeter;
	uint32_t biClrUsed;
	uint32_t biClrImportant;
} BITMAPINFOHEADER;

#pragma  pack(1)
typedef struct tagBITMAPGRAYHEADER {
	/* bmgh 1080bytes */
	//BITMAPINFOHEADER bmif;
	uint32_t bmColors[256];
} BITMAPGRAYHEADER;

#pragma  pack(1)
typedef struct tagBITMAPRGBHEADER {
	/* bmrh 72bytes */
	//BITMAPINFOHEADER bmif;
	uint32_t bmColors[4];
} BITMAPRGBHEADER;


int BMP_FileWrite(FIL* fp, const void* buff, uint32_t btw);
int BMP_Save(FIL* fp, img_t* img);