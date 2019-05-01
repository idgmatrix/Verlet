#include "stdafx.h"
#include "assert.h"
#include "bmp.h"

BYTE *CBmp::Load(const char * fname)
{
	FILE * fp;
	int rsize;

	fp = fopen(fname, "rb");
	if (!fp)
	{
		return NULL;
	}
	// read BMP file header
	pBMPHeader = (BITMAPFILEHEADER*)malloc(sizeof(BITMAPFILEHEADER));
	rsize = fread(pBMPHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	BMPFileSize = pBMPHeader->bfSize;
	//pBMPData = pBMPHeader->bfOffBits;
	
	// read BMP Info
	BMPInfoSize =  pBMPHeader->bfOffBits - sizeof(BITMAPFILEHEADER);
	pBMPInfo = (BITMAPINFO*)malloc(BMPInfoSize);
	rsize = fread(pBMPInfo, BMPInfoSize, 1, fp);
	assert(rsize == BMPInfoSize);
	
	// read BMP data
	BMPDataSize = BMPFileSize - pBMPHeader->bfOffBits;
	pBMPData = (BYTE*)malloc(BMPDataSize);
	rsize = fread(pBMPData, BMPDataSize, 1, fp);
	assert(rsize == BMPDataSize);
	
	fclose(fp);

	free(pBMPInfo);  
	free(pBMPHeader);
	
	return pBMPData;  
}