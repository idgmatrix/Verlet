// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

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

