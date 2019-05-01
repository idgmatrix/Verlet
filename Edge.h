// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

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
