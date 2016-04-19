// Dlgc.cpp : implementation file
//

#include "stdafx.h"
#include "kh.h"
#include "Dlgc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgc dialog


CDlgc::CDlgc(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgc::IDD, pParent),v(RGB(0,0,64))
{
	//{{AFX_DATA_INIT(CDlgc)
	m_y = 1;
	m_x = 1;
	//}}AFX_DATA_INIT
}


void CDlgc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgc)
	DDX_Control(pDX, IDC_COLORTABCTRL1, m_coltab);
	DDX_Text(pDX, IDC_EDIT1, m_y);
	DDX_Text(pDX, IDC_EDIT2, m_x);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgc, CDialog)
	//{{AFX_MSG_MAP(CDlgc)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgc message handlers

BEGIN_EVENTSINK_MAP(CDlgc, CDialog)
    //{{AFX_EVENTSINK_MAP(CDlgc)
	ON_EVENT(CDlgc, IDC_COLORTABCTRL1, -600 /* Click */, OnClickColortabctrl1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDlgc::OnClickColortabctrl1() 
{
	m_y=m_coltab.GetY();
	m_x=m_coltab.GetX();
	UpdateData(false);
	v=m_coltab.GetChoocecolor();
}
