#ifndef CONVERT_H
#define CONVERT_H
#include <windows.h>

BYTE* ConvertRGBToBMPBuffer(BYTE* Buffer, int width, int height, long* newsize);
BYTE* ConvertBMPToRGBBuffer(BYTE* Buffer, int width, int height);

#endif