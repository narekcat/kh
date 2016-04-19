// khDoc.h : interface of the CKhDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KHDOC_H__3C1337E7_0EF4_4A75_B39D_E769509E3503__INCLUDED_)
#define AFX_KHDOC_H__3C1337E7_0EF4_4A75_B39D_E769509E3503__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "metod.h"
 
class CKhDoc : public CDocument
{
protected: // create from serialization only
	CKhDoc();
	DECLARE_DYNCREATE(CKhDoc)

// Attributes
public:
	int r,c;
	long int fixedcol,col,bkgcol,selcol;
	bool fixedcol_mod,col_mod,bkgcol_mod,selcol_mod;
	metod m;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKhDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKhDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKhDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KHDOC_H__3C1337E7_0EF4_4A75_B39D_E769509E3503__INCLUDED_)
