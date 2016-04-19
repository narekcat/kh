#if !defined(AFX_DLGCOLOR_H__04A2C2AE_567B_49B1_9687_099F25CF7913__INCLUDED_)
#define AFX_DLGCOLOR_H__04A2C2AE_567B_49B1_9687_099F25CF7913__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgColor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgColor dialog

class CDlgColor : public CDialog
{
// Construction
public:
	CDlgColor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgColor)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgColor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgColor)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCOLOR_H__04A2C2AE_567B_49B1_9687_099F25CF7913__INCLUDED_)
