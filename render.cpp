// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

#include "stdafx.h"
#include "graphics.h"
#include "background.h"
#include "particle.h"
#include "body.h"
#include "Strip.h"

#define MAX 5

Body Tetra[MAX];
CStrip Str = CStrip(4, 3);

char *FileOpenDlg(HINSTANCE hInst, HWND hWnd);

void OnRestart(void)
{
	for (int i = 0; i < MAX; i++)
	{
		Tetra[i] = Body(4, 6);
		Tetra[i].Init();
	}
	Str.Init();
}

// 에니메이션 시키는 함수
void RenderScene(void)
{
	SetColorRGB(50,255,50);	
	
	SetCollisionBound(0, 540, 0, 480, 0, 0);

	// draw background
	DrawVLine(542, 0, 250);
	for (int i = 0; i <= 35; i ++)
		DrawLine(i * 15, harray[i], i * 15 + 15, harray[i+1]);

	SetColorRGB(255,250,250);	

	for (int i = 0; i < MAX; i++)
	{
		Tetra[i].Update();
		Tetra[i].Draw();
	}
	Str.Update();
	Str.Draw();
}

void OnLoadBMP(HINSTANCE hInst, HWND hWnd)
{
	FileOpenDlg(hInst, hWnd);
}

char *FileOpenDlg(HINSTANCE hInst, HWND hWnd)
{
	OPENFILENAME ofn;
	
	ofn.lStructSize; 
    ofn.hwndOwner; 
    ofn.hInstance; 
    ofn.lpstrFilter; 
    ofn.lpstrCustomFilter; 
    ofn.nMaxCustFilter; 
    ofn.nFilterIndex; 
    ofn.lpstrFile; 
    ofn.nMaxFile; 
    ofn.lpstrFileTitle; 
    ofn.nMaxFileTitle; 
    ofn.lpstrInitialDir; 
    ofn.lpstrTitle; 
    ofn.Flags; 
    ofn.nFileOffset; 
    ofn.nFileExtension; 
    ofn.lpstrDefExt; 
    ofn.lCustData; 
    ofn.lpfnHook; 
    ofn.lpTemplateName; 
	
	GetOpenFileName(&ofn);

	return ofn.lpstrFileTitle;
}