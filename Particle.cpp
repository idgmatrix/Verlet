// Rigid Body 데모 프로그램
// Copyright (c) 2002 Kim Seong Wan
// all rights reserved
// 이 프로그램의 소스는 개인적인 프로그래밍 공부를 목적으로만 사용하실 수 있고
// 이외의 다른 목적으로 사용할 수 없습니다. 다른 목적으로 사용하고자 할 경우는
// 반드시 저작권자인 김성완 (kaswan@hitel.net)에게 연락을 하셔서 허락을 받으셔야 합니다.  

// Particle.cpp: implementation of the CParticle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "graphics.h"
#include "Particle.h"
#include "background.h"

#define MAX_ITERATION 2
#define GRAVITY 1.0f

#pragma warning (disable: 4244)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CParticle::CParticle()
{
	m_a = CVector3(0, GRAVITY, 0);
	m_delta = 0.1f;
}

CParticle::~CParticle()
{

}

// Verlet integrator
void CParticle::UpdatePosition()
{
	CVector3 temp;

	temp = m_pos;
	m_pos += m_pos - m_oldpos + m_a * m_delta * m_delta;
	m_oldpos = temp;
}

void CParticle::Collision()
{
	////////////////////////////////////////////
	// Check Rectangular Boundary
	// left
	if (m_pos.x < 0) 
	{
		m_oldpos.x += 2 * (0.0f - m_oldpos.x);
		m_pos.x -= 2 * (m_pos.x - 0.0f);
	}
	// right
	if (m_pos.x > 540) 
	{
		m_oldpos.x += 2 * (540.0f - m_oldpos.x);
		m_pos.x -= 2 * (m_pos.x - 540.0f);
	}
	// top
	if (m_pos.y < 0) 
	{
		m_oldpos.y += 2 * (0.0f - m_oldpos.y);
		m_pos.y -= 2 * (m_pos.y - 0.0f);
	}
	// bottom
	if (m_pos.y > 480) 
	{
		m_oldpos.y += 2 * (480.0f - m_oldpos.y);
		m_pos.y -= 2 * (m_pos.y - 480.0f);
	}

	//////////////////////////////////////////////
	//check curved suface
	float height = (float)GetHeight((int)m_pos.x);
	if (m_pos.y > height )
	{
		// calc surface segment end positions after collision 
		//  
		int xleft = (int)m_pos.x / 15 * 15;
		int xright = (int)m_pos.x / 15 * 15 + 15;
		float yleft = GetHeight(xleft);
		float yright = GetHeight(xright);
		
		CVector3 Rleft = CVector3(xleft, yleft, 0);
		CVector3 Rright = CVector3(xright, yright, 0); 

		// calc surface segment end positions before collision 
		//  
		int xoldleft = (int)m_oldpos.x / 15 * 15;
		int xoldright = (int)m_oldpos.x / 15 * 15 + 15;
		float yoldleft = GetHeight(xoldleft);
		float yoldright = GetHeight(xoldright);

		// Set Segment End Positions Vectors
		CVector3 Segleft = CVector3(xoldleft, yoldleft, 0);
		CVector3 Segright = CVector3(xoldright, yoldright, 0); 
		
		CVector3 Segment = Segright - Segleft;
		CVector3 New_m_x;
		CVector3 New_m_oldx;
		Segment = Segright - Segleft;
		Segment.Normalize();
		float length = Segment * (m_pos - m_oldpos);

		New_m_x = Segment * length + m_oldpos;
		New_m_oldx = m_pos - Segment * length;

		//error correction
		float error = (float)GetHeight((int)New_m_x.x) - New_m_x.y;
		if (error)
		{
			New_m_x.y += error;
			New_m_oldx.y += error;
		}
		
		m_pos = New_m_x;
		m_oldpos = New_m_oldx;
	}
}
