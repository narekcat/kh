#if !defined(AFX_COLORREC_H__F7081FAF_1454_480F_B7BE_4615791EB809__INCLUDED_)
#define AFX_COLORREC_H__F7081FAF_1454_480F_B7BE_4615791EB809__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CColorrec wrapper class

class CColorrec : public CWnd
{
protected:
	DECLARE_DYNCREATE(CColorrec)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x9fb6346e, 0x60a4, 0x4efe, { 0xad, 0x74, 0x53, 0xdb, 0x3d, 0x2e, 0xb5, 0x7d } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	long GetBrnum();
	void SetBrnum(long);

// Operations
public:
	void AboutBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORREC_H__F7081FAF_1454_480F_B7BE_4615791EB809__INCLUDED_)
