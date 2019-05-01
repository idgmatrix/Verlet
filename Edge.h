// Rigid Body ���� ���α׷�
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// �� ���α׷��� �ҽ��� �������� ���α׷��� ���θ� �������θ� ����Ͻ� �� �ְ�
// �̿��� �ٸ� �������� ����� �� �����ϴ�. �ٸ� �������� ����ϰ��� �� ����
// �ݵ�� ���۱����� �輺�� (kaswan@hitel.net)���� ������ �ϼż� ����� �����ž� �մϴ�.  

// Edge.h: interface for the Edge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDGE_H__DFD47A23_9E80_4093_8094_E4BF37AD50FB__INCLUDED_)
#define AFX_EDGE_H__DFD47A23_9E80_4093_8094_E4BF37AD50FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "particle.h"

class Edge  
{
public:
	Edge();
	virtual ~Edge();
	void SetLength(float len);
	void CalcConstraint();

	CParticle * m_pP0;
	CParticle * m_pP1;
	float m_Length;

	//friend class Body;
};

#endif // !defined(AFX_EDGE_H__DFD47A23_9E80_4093_8094_E4BF37AD50FB__INCLUDED_)
