// bmpCreater.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"stdio.h"
#include"svbmp.h"
#include"stdlib.h"
#include"string.h"

#define RGB565(r,g,b) (uint16_t)(((r<<8)&0xF800U)|((g<<3)&0x7E0U)|((b>>3)&0x1FU))
int main()
{
	img_t a, b;
	FILE* abmp, *bbmp;

	//灰度图像测试
	a.format = PixelFormatGray;
	a.height = 120;
	a.width = 184;
	a.pImg = malloc(a.height * a.width);
	memset(a.pImg, 0, a.height * a.width);
	for (size_t i = 0; i < a.width; i++)
	{
		((uint8_t*)a.pImg)[40 * a.width + i] = 255;
		((uint8_t*)a.pImg)[39 * a.width + i] = 128;
	}

	fopen_s(&abmp, "a.bmp", "wb");
	BMP_Save(abmp, &a);
	fclose(abmp);


	//彩色图像测试
	b.format = PixelFormatRGB565;
	b.height = 240;
	b.width = 320;
	b.pImg = malloc(b.height * b.width * 2);
	memset(b.pImg, 0, b.height * b.width * 2);
	for (size_t i = 0; i < b.width; i++)
	{
		((uint16_t*)b.pImg)[38 * b.width + i] = RGB565(255,0,0);
		((uint16_t*)b.pImg)[39 * b.width + i] = RGB565(0,255,0);
		((uint16_t*)b.pImg)[40 * b.width + i] = RGB565(0,0,255);
	}

	fopen_s(&bbmp, "b.bmp", "wb");
	BMP_Save(bbmp, &b);
	fclose(bbmp);


	free(a.pImg);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
