// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

// Body.h: interface for the Body class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BODY_H__0FDB9715_297D_4394_96BF_B812616E73CD__INCLUDED_)
#define AFX_BODY_H__0FDB9715_297D_4394_96BF_B812616E73CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "edge.h"

#define CLENGTH 40.0f

class Body  
{
public:
	Body();
	Body(int NumParticle, int NumEdge);
	Body(const Body & body)
	{
		m_NumParticle = body.m_NumParticle; 
		m_NumEdge = body.m_NumEdge;
		
		m_ParticleList = new CParticle[m_NumParticle]; 
		m_EdgeList = new Edge[m_NumEdge];
		
		for (int i = 0; i < m_NumParticle; i++)
			m_ParticleList[i] = body.m_ParticleList[i];
		for (int i = 0; i < m_NumEdge; i++)
			m_EdgeList[i] = body.m_EdgeList[i];
	}
	
	virtual ~Body();

	Body & operator=(const Body & body)
	{
		m_NumParticle = body.m_NumParticle; 
		m_NumEdge = body.m_NumEdge;
		
		m_ParticleList = new CParticle[m_NumParticle]; 
		m_EdgeList = new Edge[m_NumEdge];
		
		for (int i = 0; i < m_NumParticle; i++)
			m_ParticleList[i] = body.m_ParticleList[i];
		for (int i = 0; i < m_NumEdge; i++)
			m_EdgeList[i] = body.m_EdgeList[i];

		return *this;
	}
	
	virtual void Init();
	void Update();
	void Draw();
	void Reset();
	
	int m_NumParticle;
	int m_NumEdge;

	CParticle *m_ParticleList;
	Edge *m_EdgeList;
};

#endif // !defined(AFX_BODY_H__0FDB9715_297D_4394_96BF_B812616E73CD__INCLUDED_)
