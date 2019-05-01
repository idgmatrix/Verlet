// Strip.cpp: implementation of the CStrip class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "particle.h"
#include "Edge.h"
#include "body.h"
#include "Strip.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#pragma warning (disable:4244)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStrip::CStrip()
{
	
}

CStrip::~CStrip()
{
	//m_NumParticle = 0;
	//m_NumEdge = 0;

	//delete[] m_ParticleList;
	//delete[] m_EdgeList;
}

void CStrip::Init()
{
	int speed = 10;

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
}