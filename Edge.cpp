// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

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
