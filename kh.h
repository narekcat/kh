// kh.h : main header file for the KH application
//

#if !defined(AFX_KH_H__67726896_56E2_4172_8F3C_AC8E9A0E5BC6__INCLUDED_)
#define AFX_KH_H__67726896_56E2_4172_8F3C_AC8E9A0E5BC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKhApp:
// See kh.cpp for the implementation of this class
//

class CKhApp : public CWinApp
{
public:
	bool is_first;
	CKhApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKhApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKhApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KH_H__67726896_56E2_4172_8F3C_AC8E9A0E5BC6__INCLUDED_)
