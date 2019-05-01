// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

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

