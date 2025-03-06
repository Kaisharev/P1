#ifndef IO_H
#define IO_H

#define bool int
#define true TRUE
#define false FALSE

#include <windows.h>
#include <stdio.h>

bool SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile);
BYTE* LoadBMP(int* width, int* height, long* size, const char* bmpfile);
#endif