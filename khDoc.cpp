// khDoc.cpp : implementation of the CKhDoc class
//

#include "stdafx.h"
#include "kh.h"

#include "khDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKhDoc

#include "transfer.h"

extern transfer tr;

IMPLEMENT_DYNCREATE(CKhDoc, CDocument)

BEGIN_MESSAGE_MAP(CKhDoc, CDocument)
	//{{AFX_MSG_MAP(CKhDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKhDoc construction/destruction

CKhDoc::CKhDoc()
{
	r=tr.K;
	c=tr.N;
	fixedcol_mod=tr.fc_mod;
	col_mod=tr.c_mod;
	bkgcol_mod=tr.bc_mod;
	selcol_mod=tr.sc_mod;
	if(fixedcol_mod)
		fixedcol=tr.fc;
	if(col_mod)
		col=tr.c;
	if(bkgcol_mod)
		bkgcol=tr.bc;
	if(selcol_mod)
		selcol=tr.sc;
	m.setparams(c,r);
}

CKhDoc::~CKhDoc()
{
}

BOOL CKhDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	SetModifiedFlag();
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKhDoc serialization

void CKhDoc::Serialize(CArchive& ar)
{
	m.Serialize(ar);
	if (ar.IsStoring())
	{
		char i;
		ar<<c;
		ar<<r;
		ar<<fixedcol;
		ar<<col;
		ar<<selcol;
		ar<<bkgcol;
		i=fixedcol_mod;
		ar<<i;
		i=col_mod;
		ar<<i;
		i=bkgcol_mod;
		ar<<i;
		i=selcol_mod;
		ar<<i;
		// TODO: add storing code here
	}
	else
	{
		char i;
		ar>>c;
		ar>>r;
		ar>>fixedcol;
		ar>>col;
		ar>>selcol;
		ar>>bkgcol;
		ar>>i;
		fixedcol_mod=(i!=0);
		ar>>i;
		col_mod=(i!=0);
		ar>>i;
		bkgcol_mod=(i!=0);
		ar>>i;
		selcol_mod=(i!=0);
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CKhDoc diagnostics

#ifdef _DEBUG
void CKhDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKhDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKhDoc commands
