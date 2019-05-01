// Strip.h: interface for the CStrip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRIP_H__781D3F32_85FB_409C_95B6_EEE7F3BB278D__INCLUDED_)
#define AFX_STRIP_H__781D3F32_85FB_409C_95B6_EEE7F3BB278D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Body.h"

class CStrip : public Body  
{
public:
	CStrip();
	CStrip(int NumParticle, int NumEdge): Body(NumParticle, NumEdge){}
	//CStrip(const CStrip &str): Body(str){}
	
	virtual ~CStrip();

	void Init();

};

#endif // !defined(AFX_STRIP_H__781D3F32_85FB_409C_95B6_EEE7F3BB278D__INCLUDED_)
