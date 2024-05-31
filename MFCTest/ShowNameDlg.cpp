// ShowNameDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCTest.h"
#include "afxdialogex.h"
#include "ShowNameDlg.h"


// ShowNameDlg 对话框

IMPLEMENT_DYNAMIC(ShowNameDlg, CDialogEx)

ShowNameDlg::ShowNameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ShowNameDlg, pParent)
	, m_x(0)
	, m_y(0)
{

}

ShowNameDlg::~ShowNameDlg()
{
}

void ShowNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
}


BEGIN_MESSAGE_MAP(ShowNameDlg, CDialogEx)
END_MESSAGE_MAP()


// ShowNameDlg 消息处理程序
