// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

// Vector3.cpp: implementation of the CVector3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Vector3.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CVector3::CVector3()
{
	x = y = z = 0;
}

CVector3::CVector3(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

CVector3::~CVector3()
{

}

CVector3 CVector3::operator*(float const &rhv) const
{
	CVector3 temp;

	temp.x = x * rhv;
	temp.y = y * rhv;
	temp.z = z * rhv;

	return temp;
}

CVector3 CVector3::operator+=(CVector3 const &rhv)
{
	x += rhv.x;
	y += rhv.y;
	z += rhv.z;

	return *this;
}

CVector3 CVector3::operator-=(CVector3 const &rhv)
{
	x -= rhv.x;
	y -= rhv.y;
	z -= rhv.z;

	return *this;
}

CVector3 operator+(CVector3 const &lhv, CVector3 const &rhv)
{
	CVector3 temp;

	temp.x = lhv.x + rhv.x;
	temp.y = lhv.y + rhv.y;
	temp.z = lhv.z + rhv.z;

	return temp;
}

CVector3 operator-(CVector3 const &lhv, CVector3 const &rhv)
{
	CVector3 temp;

	temp.x = lhv.x - rhv.x;
	temp.y = lhv.y - rhv.y;
	temp.z = lhv.z - rhv.z;

	return temp;
}

float operator*(CVector3 const &lhv, CVector3 const &rhv)
{
	return (lhv.x * rhv.x + lhv.y * rhv.y + lhv.z * rhv.z);
}

CVector3 operator*(float const &lhv, CVector3 const &rhv)
{
	return (rhv * lhv);
}
