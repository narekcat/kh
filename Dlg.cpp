// Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "kh.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg dialog

#include "Dlgc.h"
#include "transfer.h"
extern transfer tr;

CDlg::CDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg)
	m_N = 0;
	m_K = 0;
	//}}AFX_DATA_INIT
}


void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg)
	DDX_Text(pDX, IDC_EDIT1, m_N);
	DDV_MinMaxInt(pDX, m_N, 1, 400);
	DDX_Text(pDX, IDC_EDIT2, m_K);
	DDV_MinMaxInt(pDX, m_K, 1, 400);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg, CDialog)
	//{{AFX_MSG_MAP(CDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg message handlers

void CDlg::OnButton1() 
{
	CDlgc dlgc;
	int result=dlgc.DoModal();
	if(IDOK==result)
	{
		tr.fc_mod=true;
		tr.fc=dlgc.v;
	}
}

void CDlg::OnButton2() 
{
	CDlgc dlgc;
	int result=dlgc.DoModal();
	if(IDOK==result)
	{
		tr.c_mod=true;
		tr.c=dlgc.v;
	}	
}

void CDlg::OnButton3() 
{
	CDlgc dlgc;
	int result=dlgc.DoModal();
	if(IDOK==result)
	{
		tr.bc_mod=true;
		tr.bc=dlgc.v;
	}
}

void CDlg::OnButton4() 
{
	CDlgc dlgc;
	int result=dlgc.DoModal();
	if(IDOK==result)
	{
		tr.sc_mod=true;
		tr.sc=dlgc.v;
	}
}
