#pragma once
#include "afxdialogex.h"


// ShowNameDlg 对话框

class ShowNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowNameDlg)

public:
	ShowNameDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ShowNameDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ShowNameDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_x;
	int m_y;
};
