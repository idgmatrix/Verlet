// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

// Vector3.h: interface for the CVector3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR3_H__3DAEA162_34D9_11D5_B1FE_0050FC0CF471__INCLUDED_)
#define AFX_VECTOR3_H__3DAEA162_34D9_11D5_B1FE_0050FC0CF471__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CVector3  
{
public:
	float x, y, z;

	CVector3();
	CVector3(float, float, float);
	virtual ~CVector3();
	
	friend CVector3 operator+(CVector3 const &, CVector3 const &);
	friend CVector3 operator-(CVector3 const &, CVector3 const &);
	friend float operator*(CVector3 const &, CVector3 const &);
	friend CVector3 operator*(float const &, CVector3 const &);
	CVector3 operator-() const
	{
		CVector3 temp;

		temp.x = -x;
		temp.y = -y;
		temp.z = -z;

		return temp;
	}

	CVector3 operator+=(CVector3 const &); 
	CVector3 operator-=(CVector3 const &); 
	CVector3 operator*(float const &) const;

	void Normalize(void)
	{
		float length = (float)sqrt(x * x + y * y + z * z);
		x /= length;
		y /= length;
		z /= length;
	}

};

#endif // !defined(AFX_VECTOR3_H__3DAEA162_34D9_11D5_B1FE_0050FC0CF471__INCLUDED_)

