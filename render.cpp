// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

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

// ���ϸ��̼� ��Ű�� �Լ�
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