// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

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
