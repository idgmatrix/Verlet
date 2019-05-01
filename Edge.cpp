// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

// Edge.cpp: implementation of the Edge class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "particle.h"
#include "Edge.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Edge::Edge()
{
	m_pP0 = m_pP1 = NULL;
	m_Length = 0;
}

Edge::~Edge()
{

}

void Edge::SetLength(float len)
{
	m_Length = len;
}

void Edge::CalcConstraint(void)
{
	CVector3 vdelta = m_pP1->m_pos - m_pP0->m_pos;
	float deltalength = (float)sqrt(vdelta * vdelta);
	float diff = (deltalength - m_Length) / deltalength;
	m_pP0->m_pos += vdelta * 0.5f * diff;
	m_pP1->m_pos -= vdelta * 0.5f * diff;
}
