// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

#include "stdafx.h"
#include "assert.h"

#ifndef PI
#define PI 3.1415926535f
#endif

struct {					// �⺻���� ���簢�� �浹����
	float xmin, xmax;
	float ymin, ymax;
	float zmin, zmax;
} Bounding;

int harray[100];			// ��� ���� ���� �����ϴ� �迭

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

// harray[]�� x������ 15�ȼ� ������ ����� ��� ���� ���� �������� 
// �� ������ ���̰��� ����������� ���ϴ� �Լ�
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

