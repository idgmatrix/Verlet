#ifndef BMP_H
#define BMP_H

#include "stdafx.h"

class CBmp{
public:
	BITMAPFILEHEADER *pBMPHeader;
	BITMAPINFO *pBMPInfo;
	int BMPFileSize;
	int BMPInfoSize;
	int BMPDataSize;
	BYTE *pBMPData;

	CBmp()
	{
		pBMPHeader = NULL;
		pBMPInfo = NULL;
		pBMPData = NULL;
	}
	
	~CBmp()
	{
		if (pBMPData) free(pBMPData);
	}	

	BYTE *Load(const char * fname);
};

#endif