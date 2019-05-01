// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

#include "stdafx.h"
#include "assert.h"

#ifndef PI
#define PI 3.1415926535f
#endif

struct {					// 기본적인 직사각형 충돌범위
	float xmin, xmax;
	float ymin, ymax;
	float zmin, zmax;
} Bounding;

int harray[100];			// 곡선의 높이 값을 저장하는 배열

void SetCollisionBound(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);
int GetHeight(int x);

void SetCollisionBound(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax)
{
	Bounding.xmin = xmin;
	Bounding.xmax = xmax;
	Bounding.ymin = ymin;
	Bounding.ymax = ymax;
	Bounding.zmin = zmin;
	Bounding.zmax = zmax;

	for ( int i = 0; i <= 50; i += 1)
	{
		harray[i] = (int)(-cos((float)i * 10.0 * PI / 180.0) * 100 + 350);
	}
}

// harray[]에 x축으로 15픽셀 단위로 저장된 곡선의 높이 값을 기준으로 
// 그 사이의 높이값을 가중평균으로 구하는 함수
int GetHeight(int x)
{
	//PutNumber(0,0,x);
	assert(x >= 0 && x < 640);
	int i = x / 15;
	int r = x % 15;

	if (i >= 0)
	{ 
		return (int)((float)(15 - r)/15.0f * (float)harray[i] + (float)r / 15.0f * (float)harray[i + 1]);
	}
	else return 480;
}

