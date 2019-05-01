// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

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