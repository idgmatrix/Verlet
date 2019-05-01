// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

// Body.cpp: implementation of the Body class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "graphics.h"
#include "particle.h"
#include "Body.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
#endif

#pragma warning (disable: 4244)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Body::Body()
{
	m_NumParticle = 0;
	m_NumEdge = 0;

	m_ParticleList = NULL;
	m_EdgeList = NULL;
}

Body::Body(int NumParticle, int NumEdge)
{
	m_NumParticle = NumParticle;
	m_NumEdge = NumEdge;

	m_ParticleList = new CParticle[NumParticle];
	m_EdgeList = new Edge[NumEdge];

	//Init();
}

Body::~Body()
{
	m_NumParticle = 0;
	m_NumEdge = 0;

	if (m_ParticleList)	
	{	
		delete[] m_ParticleList;
		m_ParticleList = NULL;
	}
	if (m_EdgeList) 
	{
		delete[] m_EdgeList;
		m_EdgeList = NULL;
	}
}

void Body::Reset()
{
	Init();
}

void Body::Init()
{
	int speed = rand() % 30;

	m_ParticleList[0].m_oldpos = CVector3(100, 100, 50);
	m_ParticleList[0].m_pos = CVector3(100 + speed, 100, 50);
	
	m_ParticleList[1].m_oldpos = CVector3(130, 100, 0);
	m_ParticleList[1].m_pos = CVector3(130 + speed, 100, 0);
	
	m_ParticleList[2].m_oldpos = CVector3(130, 130 + speed, 0);
	m_ParticleList[2].m_pos = CVector3(130 + speed, 130, 0);
	
	m_ParticleList[3].m_oldpos = CVector3(100, 130, 10);
	m_ParticleList[3].m_pos = CVector3(100 + speed, 130, 0);

	m_EdgeList[0].m_pP0 = &m_ParticleList[0];
	m_EdgeList[0].m_pP1 = &m_ParticleList[1];
	m_EdgeList[0].SetLength(CLENGTH);

	m_EdgeList[1].m_pP0 = &m_ParticleList[1];
	m_EdgeList[1].m_pP1 = &m_ParticleList[2];
	m_EdgeList[1].SetLength(CLENGTH);

	m_EdgeList[2].m_pP0 = &m_ParticleList[2];
	m_EdgeList[2].m_pP1 = &m_ParticleList[3];
	m_EdgeList[2].SetLength(CLENGTH);

	m_EdgeList[3].m_pP0 = &m_ParticleList[3];
	m_EdgeList[3].m_pP1 = &m_ParticleList[0];
	m_EdgeList[3].SetLength(CLENGTH);

	m_EdgeList[4].m_pP0 = &m_ParticleList[0];
	m_EdgeList[4].m_pP1 = &m_ParticleList[2];
	m_EdgeList[4].SetLength(CLENGTH);

	m_EdgeList[5].m_pP0 = &m_ParticleList[1];
	m_EdgeList[5].m_pP1 = &m_ParticleList[3];
	m_EdgeList[5].SetLength(CLENGTH);
}

void Body::Update()
{
	for(int i = 0; i< m_NumParticle; i++)
	{
		m_ParticleList[i].UpdatePosition();
	}

	for(int i = 0; i< m_NumEdge; i++)
	{
		m_EdgeList[i].CalcConstraint();
	}

	for(int i = 0; i< m_NumParticle; i++)
	{
		m_ParticleList[i].Collision();
	}
}

void Body::Draw()
{
	for (int i = 0; i < m_NumParticle; i++)
	{
		PutPixel((int)m_ParticleList[i].m_pos.x, (int)m_ParticleList[i].m_pos.y);
	}
	
	for (int i = 0; i < m_NumEdge; i++)
	{
		DrawLine((int)m_EdgeList[i].m_pP0->m_pos.x, 
				(int)m_EdgeList[i].m_pP0->m_pos.y,
				(int)m_EdgeList[i].m_pP1->m_pos.x, 
				(int)m_EdgeList[i].m_pP1->m_pos.y);
	}
}