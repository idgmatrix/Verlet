// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

// Particle.h: interface for the CParticle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARTICLE_H__3DAEA161_34D9_11D5_B1FE_0050FC0CF471__INCLUDED_)
#define AFX_PARTICLE_H__3DAEA161_34D9_11D5_B1FE_0050FC0CF471__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vector3.h"

//#define MAX 4

class CParticle  
{
public:
	CParticle();
	virtual ~CParticle();
	void UpdatePosition();
	void Collision();

	CVector3 m_pos;
	CVector3 m_oldpos;

	CVector3 m_a;
	float m_m;
	float m_delta;
	
//	friend class Body;
//	friend class Edge;
};

#endif // !defined(AFX_PARTICLE_H__3DAEA161_34D9_11D5_B1FE_0050FC0CF471__INCLUDED_)

