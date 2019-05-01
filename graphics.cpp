// Particle ȿ�� ���� ���α׷�
// Copyright (c) 1999 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

// DIBSection �� �̿��� �⺻���� �׷��� ó�� �Լ����Դϴ�
#include "stdafx.h"
#include "graphics.h"
#include "render.h"

HDC		hScreenDC;
HDC		hMemoryDC;
HBITMAP hDefaultBitmap;
HBITMAP hDIBitmap;

BOOL	bIsActive;
UINT	frameCounter;
LARGE_INTEGER Frequency;
LARGE_INTEGER StartCounter, EndCounter;
	
int		DIBSectionWidth, DIBSectionHeight;
BYTE	*Bits;
UINT	scanline;
float	fps;
CurrentColor color;

void	InitGraphics(HWND hWnd, int width, int height);
void	DeinitGraphics(HWND hWnd);
HBITMAP MakeDIBSection(int width, int height, BYTE **pBits);
void	UpdateFrame(void);
void	DisplayFPS(void);
void	PutNumber(int x, int y, int number);
void	PutNumber(int x, int y, UINT number);
void	PutNumber(int x, int y, float number);
void	ResetFrameCounter(void);
void	SetColorRGB(BYTE r, BYTE g, BYTE b);
void	ClearDIBSection(BYTE r, BYTE g, BYTE b);

void PutPixel(int x, int y);
void DrawHLine(int x1, int x2, int y);
void DrawVLine(int x, int y1, int y2);
void DrawBox(int x1, int y1, int x2, int y2);
void FillBox(int x1, int y1, int x2, int y2);
void DrawLine(int x1, int y1, int x2, int y2);

void InitGraphics(HWND hWnd, int width, int height)
{
	hScreenDC = GetDC(hWnd);
	hMemoryDC = CreateCompatibleDC(hScreenDC);

	HBITMAP hDIBitmap = MakeDIBSection(width, height, &Bits);
	hDefaultBitmap = (HBITMAP)SelectObject(hMemoryDC, hDIBitmap);

	DIBSectionWidth = width;
	DIBSectionHeight = height;
	scanline= ((DIBSectionWidth * 3) + 3) &~3;

	QueryPerformanceFrequency(&Frequency);

	bIsActive = TRUE;
}

void DeinitGraphics(HWND hWnd)
{
	bIsActive = FALSE;

	SelectObject(hMemoryDC, hDefaultBitmap);
	DeleteObject(hDIBitmap);
	DeleteDC(hMemoryDC);
	ReleaseDC(hWnd, hScreenDC);
}

HBITMAP MakeDIBSection(int width, int height, BYTE **pBits)
{
	BITMAPINFO BMInfo;

	BMInfo.bmiHeader.biSize				= sizeof(BITMAPINFOHEADER);
	BMInfo.bmiHeader.biWidth			= width;
	BMInfo.bmiHeader.biHeight			= -height;
	BMInfo.bmiHeader.biPlanes			= 1;
	BMInfo.bmiHeader.biBitCount			= 24;
	BMInfo.bmiHeader.biCompression		= BI_RGB;
	BMInfo.bmiHeader.biSizeImage		= 0;
	BMInfo.bmiHeader.biXPelsPerMeter	= 0;
	BMInfo.bmiHeader.biYPelsPerMeter	= 0;
	BMInfo.bmiHeader.biClrUsed			= 0;
	BMInfo.bmiHeader.biClrImportant		= 0;

	return( CreateDIBSection(hScreenDC, (BITMAPINFO *)&BMInfo, DIB_RGB_COLORS, (VOID **)pBits, NULL, 0) );
}

void UpdateFrame(void)
{
	static float frametime;

	frameCounter++;
	ClearDIBSection(10, 10, 100);
	
	RenderScene();
	DisplayFPS();

	BitBlt(hScreenDC, 0, 0, 639, 479, hMemoryDC, 0, 0, SRCCOPY);

	QueryPerformanceCounter(&EndCounter);
	frametime = (float)(EndCounter.LowPart - StartCounter.LowPart) / (float)Frequency.LowPart;
	StartCounter.LowPart = EndCounter.LowPart;
	fps = 1 / frametime;
}

void ResetFrameCounter(void)
{
	frameCounter = 0;
}

void DisplayFPS(void)
{
	char string[20];

	sprintf(string, "FPS: %f", fps);
	TextOut(hMemoryDC, 250, 0, string, strlen(string));
}

void PutNumber(int x, int y, int number)
{
	char string[20];

	sprintf(string, "%d    ", number);
	TextOut(hMemoryDC, x, y, string, strlen(string));
}

void PutNumber(int x, int y, UINT number)
{
	char string[20];

	sprintf(string, "%u", number);
	TextOut(hMemoryDC, x, y, string, strlen(string));
}

void PutNumber(int x, int y, float number)
{
	char string[20];

	sprintf(string, "%f", number);
	TextOut(hMemoryDC, x, y, string, strlen(string));
}

void SetColorRGB(BYTE r, BYTE g, BYTE b)
{
	color.r = r;
	color.g = g;	
	color.b = b;
}

void ClearDIBSection(BYTE r, BYTE g, BYTE b)
{
	UINT BytesPerScanline = (DIBSectionWidth * 3 + 3) & ~3;
	UINT offset = 0;

	while ( offset < BytesPerScanline )
	{
			*(Bits + offset + 0) = b;
			*(Bits + offset + 1) = g;
			*(Bits + offset + 2) = r;
			offset += 3;
	}
	offset = BytesPerScanline;

	for (INT i = 0; i < DIBSectionHeight - 1; i++)
	{
		memcpy(Bits + offset, Bits, BytesPerScanline);
		offset += BytesPerScanline;
	}

}

void PutPixel(int x, int y)//, BYTE r, BYTE g, BYTE b)
{
	UINT offset;

	offset = scanline * y + x * 3;
	if ( offset > scanline * 479 + 639 * 3 ) return;
	*(Bits + offset + 0) = color.b;
	*(Bits + offset + 1) = color.g;
	*(Bits + offset + 2) = color.r;
}

void DrawHLine(int x1, int x2, int y) 
{
	UINT offset;

	offset = scanline * y + x1 * 3;

	for(int i = x1; i <= x2; i++)
	{
		*(Bits + offset + 0) = color.b;
		*(Bits + offset + 1) = color.g;
		*(Bits + offset + 2) = color.r;
		offset += 3;
	}
}

void DrawVLine(int x, int y1, int y2)
{
	UINT offset, offsetend;

	offset = scanline * y1 + x * 3;
	offsetend = scanline * y2 + x * 3;

	while(offset <= offsetend) 
	{
		*(Bits + offset + 0) = color.b;
		*(Bits + offset + 1) = color.g;
		*(Bits + offset + 2) = color.r;
		offset += scanline;
	}
}

void DrawBox(int x1, int y1, int x2, int y2)
{
	DrawVLine(x1, y1, y2);
	DrawVLine(x2, y1, y2);
	DrawHLine(x1, x2, y1);
	DrawHLine(x1, x2, y2);
}

void FillBox(int x1, int y1, int x2, int y2)
{
	UINT offset;

	offset = scanline * y1 +  x1 * 3;
	UINT nextline = scanline - (x2 - x1) * 3 - 3;

	for(int i = y1; i <= y2; i++)
	{
		for(int j = x1; j <= x2; j++)
		{
			*(Bits + offset + 0) = color.b;
			*(Bits + offset + 1) = color.g;
			*(Bits + offset + 2) = color.r;
			offset += 3;
		}
		offset += nextline;
	}
}

void DrawLine(int x1, int y1, int x2, int y2)
{
	int y, yd;
	int temp, i;
	int delta_x, delta_y;

	if ( (x1 == x2) && (y1 == y2) ) return;

	if ( x1 > x2 )
	{
		temp = x1;
		x1 = x2;
		x2 = temp;

		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	delta_x = x2 - x1;
	delta_y = y2 - y1;

	if ( delta_x < abs(delta_y) )
	{
		temp = x1;
		x1 = y1;
		y1 = temp;

		temp = x2;
		x2 = y2;
		y2 = temp;

		if ( x1 > x2 )
		{
			temp = x1;
			x1 = x2;
			x2 = temp;

			temp = y1;
			y1 = y2;
			y2 = temp;
		}

		delta_x = x2 - x1;
		delta_y = y2 - y1;

		y = y1 << 16;

		delta_y <<= 16;
		yd = delta_y / delta_x;

		for ( i = x1; i <= x2; i++ )
		{
			PutPixel(y>>16, i);
			y += yd;
		}
	}
	else
	{
		y = y1 << 16;

		delta_y <<= 16;
		yd = delta_y / delta_x;

		for ( i = x1; i <= x2; i++ )
		{
			PutPixel(i, y>>16);
			y += yd;
		}
	}
}

