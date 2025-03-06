

#include <windows.h>
#include <stdio.h>      

#include "io.h"
#include "convert.h"





void main()
{
	int x, y;
	long s, s2;
	char* input = "test.bmp";
	char* output = "output.bmp";
	BYTE* a = LoadBMP(&x, &y, &s, input);
	BYTE* b = ConvertBMPToRGBBuffer(a, x, y);
	BYTE* c = ConvertRGBToBMPBuffer(b, x, y, &s2);
	SaveBMP(c, x, y, s2, output);
	free(a);
	free(b);
	free(c);
}