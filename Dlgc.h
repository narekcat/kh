//{{AFX_INCLUDES()
#include "colortab.h"
#include "colorbox.h"
#include "colorrec.h"
//}}AFX_INCLUDES
#if !defined(AFX_DLGC_H__AC992A39_8244_4ACC_84BC_BBCF84522C7B__INCLUDED_)
#define AFX_DLGC_H__AC992A39_8244_4ACC_84BC_BBCF84522C7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlgc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgc dialog

class CDlgc : public CDialog
{
// Construction
public:
	long int v;
	CDlgc(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgc)
	enum { IDD = IDD_DIALOG2 };
	CColortab	m_coltab;
	short	m_y;
	short	m_x;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgc)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgc)
	afx_msg void OnClickColortabctrl1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGC_H__AC992A39_8244_4ACC_84BC_BBCF84522C7B__INCLUDED_)
