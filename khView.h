// khView.h : interface of the CKhView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_KHVIEW_H__6898169F_2A97_4096_94BF_0B629511C082__INCLUDED_)
#define AFX_KHVIEW_H__6898169F_2A97_4096_94BF_0B629511C082__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKhView : public CFormView
{
protected: // create from serialization only
	CKhView();
	DECLARE_DYNCREATE(CKhView)

public:
	//{{AFX_DATA(CKhView)
	enum { IDD = IDD_KH_FORM };
	CProgressCtrl	m_progress;
	CMSFlexGrid	m_fg;
	CString	m_W;
	CString	m_S;
	//}}AFX_DATA

// Attributes
public:
	CKhDoc* GetDocument();
	bool run_flag,is_run;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKhView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKhView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKhView)
	afx_msg void OnToolsComplete();
	afx_msg void OnToolsRun();
	afx_msg void OnKeyPressMsflexgrid2(short FAR* KeyAscii);
	afx_msg void OnUpdateToolsRun(CCmdUI* pCmdUI);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in khView.cpp
inline CKhDoc* CKhView::GetDocument()
   { return (CKhDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KHVIEW_H__6898169F_2A97_4096_94BF_0B629511C082__INCLUDED_)
