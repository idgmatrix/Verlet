// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct CURRENTCOLOR{
	BYTE r;
	BYTE g;
	BYTE b;
} CurrentColor;

extern HDC		hScreenDC;
extern HDC		hMemoryDC;
extern HBITMAP hDefaultBitmap;

extern BOOL	bIsActive;
//extern UINT	frameCounter;
//extern LARGE_INTEGER Frequency;
//extern LARGE_INTEGER StartCounter, EndCounter;
	
extern int DIBSectionWidth, DIBSectionHeight;
extern BYTE	*Bits;
extern UINT	scanline;
extern float fps;
extern CurrentColor color;

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


#endif