// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

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
