// khView.cpp : implementation of the CKhView class
//

#include "stdafx.h"
#include "kh.h"

#include "khDoc.h"
#include "khView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKhView

const short int num0=static_cast<short int>('0');

IMPLEMENT_DYNCREATE(CKhView, CFormView)

BEGIN_MESSAGE_MAP(CKhView, CFormView)
	//{{AFX_MSG_MAP(CKhView)
	ON_COMMAND(ID_TOOLS_COMPLETE, OnToolsComplete)
	ON_COMMAND(ID_TOOLS_RUN, OnToolsRun)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_RUN, OnUpdateToolsRun)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKhView construction/destruction

CKhView::CKhView()
	: CFormView(CKhView::IDD)
{
	//{{AFX_DATA_INIT(CKhView)
	m_W = _T("");
	m_S = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CKhView::~CKhView()
{
}

void CKhView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKhView)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_MSFLEXGRID2, m_fg);
	DDX_Text(pDX, IDC_EDIT1, m_W);
	DDX_Text(pDX, IDC_EDIT2, m_S);
	//}}AFX_DATA_MAP
}

BOOL CKhView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CKhView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	m_progress.SetRange(1,10);//<-----------
	CKhDoc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	m_fg.SetRows(pDoc->r+2);
	m_fg.SetCols(pDoc->c+3);
	if(pDoc->col_mod)
		m_fg.SetBackColor(pDoc->col);
	if(pDoc->bkgcol_mod)
		m_fg.SetBackColorBkg(pDoc->bkgcol);
	if(pDoc->fixedcol_mod)
		m_fg.SetBackColorFixed(pDoc->fixedcol);
	if(pDoc->selcol_mod)
		m_fg.SetBackColorSel(pDoc->selcol);
	run_flag=!pDoc->m.isnot_lriv;
//	OnUpdateToolRun();
	CString s="";
	s.Format("%u",pDoc->m.isnot_lriv);
	m_fg.SetTextMatrix(0,0,s);
	for(int i=1;i<pDoc->c+1;i++)
	{
		s.Format("Expen %u",i);
		m_fg.SetTextMatrix(0,i,s);
	}
	m_fg.SetTextMatrix(0,pDoc->c+1,"Sum");
	m_fg.SetTextMatrix(0,pDoc->c+2,"New class");
	for(i=1;i<pDoc->r+1;i++)
	{
		s.Format("Object %u",i);
		m_fg.SetTextMatrix(i,0,s);
	}
	m_fg.SetTextMatrix(pDoc->r+1,0,"tij");
	int j;
	for(i=0;i<pDoc->m.k+1;i++)
		for(j=0;j<pDoc->m.n+2;j++)
		{
			if(pDoc->m.mat[i][j]/*p[i*(pDoc->m.n+2)+j]*/!=0)
			{
				s.Format("%u",pDoc->m.mat[i][j]/*p[i*(pDoc->m.n+2)+j]*/);
				m_fg.SetTextMatrix(i+1,j+1,s);
			}
		}
	is_run=false;
//	pDoc->SetModifiedFlag();
}

/////////////////////////////////////////////////////////////////////////////
// CKhView printing

BOOL CKhView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKhView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKhView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CKhView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CKhView diagnostics

#ifdef _DEBUG
void CKhView::AssertValid() const
{
	CFormView::AssertValid();
}

void CKhView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CKhDoc* CKhView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKhDoc)));
	return (CKhDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKhView message handlers

void CKhView::OnToolsComplete() 
{
	CKhDoc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->m.isnot_lriv)
	{
		CString s="";
		int i,j;
		for(j=0;j<pDoc->m.n;j++)
			for(i=0;i<pDoc->m.k;i++)
				if(pDoc->m.mat[i][j]/*p[i*(pDoc->m.n+2)+j]*/==0)
				{
					pDoc->m.mat[i][j]/*p[i*(pDoc->m.n+2)+j]*/=rand()%pDoc->m.k+1;
					s.Format("%u",pDoc->m.mat[i][j]);
					m_fg.SetTextMatrix(i+1,j+1,s);
				}
	pDoc->UpdateAllViews(this,0L,NULL);
	pDoc->SetModifiedFlag();
	pDoc->m.isnot_lriv=0;
	run_flag=true;
	m_fg.SetTextMatrix(0,0,"0");
	}
}

void CKhView::OnToolsRun() 
{
	int i;
	CKhDoc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
//	if(!pDoc->m.isnot_lriv)
//	{
		pDoc->m.run();
		CString s="";
		for(i=1;i<pDoc->m.n+1;i++)
		{
			s.Format("%u",pDoc->m.mat[pDoc->m.k][i-1]/*p[pDoc->m.k*(pDoc->m.n+2)+i]*/);
			m_fg.SetTextMatrix(pDoc->m.k+1,i,s);
		}
		for(i=1;i<pDoc->m.k+1;i++)
		{
			s.Format("%u",pDoc->m.mat[i-1][pDoc->m.n]/*p[(pDoc->m.n+2)*i-2]*/);
			m_fg.SetTextMatrix(i,pDoc->m.n+1,s);
		}
//		s.Format("%u",pDoc->m.p[6]);
//		m_fg.SetTextMatrix(0,0,s);
		for(i=1;i<pDoc->m.k+1;i++)
		{
			s.Format("%u",pDoc->m.mat[i-1][pDoc->m.n+1]/*p[(pDoc->m.n+2)*i-1]*/);
			m_fg.SetTextMatrix(i,pDoc->m.n+2,s);
		}
		for(i=1;i<10;i++)
		m_progress.SetPos(i);
		is_run=true;
		m_S.Format("%.3f",pDoc->m.S);
		m_W.Format("%.3f",pDoc->m.W);
		UpdateData(false);
//	}
}

BEGIN_EVENTSINK_MAP(CKhView, CFormView)
    //{{AFX_EVENTSINK_MAP(CKhView)
	ON_EVENT(CKhView, IDC_MSFLEXGRID2, -603 /* KeyPress */, OnKeyPressMsflexgrid2, VTS_PI2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CKhView::OnKeyPressMsflexgrid2(short FAR* KeyAscii) 
{
	CKhDoc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	int r=m_fg.GetRow(),c=m_fg.GetCol();
	if(r>0 && r<pDoc->m.k+1 && c>0 && c<pDoc->m.n+1)
	{
		CString s="";
		char nChar=static_cast<char>(*KeyAscii);
		if(nChar>='0' && nChar<='9')
		{
			if(m_fg.GetTextMatrix(r,c)=="" && nChar!='0')
			{
				if(pDoc->m.mat[r-1][c-1]/*p[(r-1)*(pDoc->m.n+2)+c-1]*/*10+
					*KeyAscii-num0<=pDoc->m.k)
				{
					pDoc->m.mat[r-1][c-1]/*p[(r-1)*(pDoc->m.n+2)+c-1]*/=
						pDoc->m.mat[r-1][c-1]/*p[(r-1)*(pDoc->m.n+2)+c-1]*/*10+*KeyAscii-num0;
					s=m_fg.GetTextMatrix(r,c)+CString(nChar);
					m_fg.SetTextMatrix(r,c,s);
					pDoc->m.isnot_lriv--;
					s.Format("%u",pDoc->m.isnot_lriv);
					m_fg.SetTextMatrix(0,0,s);
				}
			}
			else
			if(m_fg.GetTextMatrix(r,c)!="")
				if(pDoc->m.mat[r-1][c-1]/*p[(r-1)*(pDoc->m.n+2)+c-1]*/*10+
					*KeyAscii-num0<=pDoc->m.k)
				{
					pDoc->m.mat[r-1][c-1]/*p[(r-1)*(pDoc->m.n+2)+c-1]*/=
						pDoc->m.mat[r-1][c-1]/*p[(r-1)*(pDoc->m.n+2)+c-1]*/*10+*KeyAscii-num0;
					s=m_fg.GetTextMatrix(r,c)+CString(nChar);
					m_fg.SetTextMatrix(r,c,s);
				}
		}
		else
			if(*KeyAscii==8)
			{
				s=m_fg.GetTextMatrix(r,c);
				if(s.GetLength()>=1)
				{
					s.Delete(s.GetLength()-1);
					m_fg.SetTextMatrix(r,c,s);
					pDoc->m.mat[r-1][c-1]/*p[(r-1)*(pDoc->m.n+2)+c-1]*//=10;
					if(pDoc->m.mat[r-1][c-1]/*p[(r-1)*(pDoc->m.n+2)+c-1]*/==0)
						pDoc->m.isnot_lriv++;
					s.Format("%u",pDoc->m.isnot_lriv);
					m_fg.SetTextMatrix(0,0,s);
				}
			}
		run_flag=!pDoc->m.isnot_lriv;
		pDoc->UpdateAllViews(this,0L,NULL);
		pDoc->SetModifiedFlag();
		if(is_run)
		{
			m_progress.SetPos(1);
			m_S="";
			m_W="";
			UpdateData(false);
		}
	}
}

void CKhView::OnUpdateToolsRun(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(run_flag);	
}
