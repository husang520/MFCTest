
// MFCTestView.cpp: CMFCTestView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCTest.h"
#endif

#include "MFCTestDoc.h"
#include "MFCTestView.h"

#include "ShowNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTestView

IMPLEMENT_DYNCREATE(CMFCTestView, CView)

BEGIN_MESSAGE_MAP(CMFCTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_CHAR()
	ON_COMMAND(ID_32771, &CMFCTestView::OnText)
	ON_COMMAND(ID_32772, &CMFCTestView::OnPicture)
	ON_COMMAND(ID_32773, &CMFCTestView::OnOpen)
	ON_COMMAND(ID_32774, &CMFCTestView::OnShow)
	ON_COMMAND(ID_32775, &CMFCTestView::OnShowName)
END_MESSAGE_MAP()

// CMFCTestView 构造/析构

CMFCTestView::CMFCTestView() noexcept
{
	// TODO: 在此处添加构造代码
	m_nLeft = 0;
	m_nRight = 0;
}

CMFCTestView::~CMFCTestView()
{
}

BOOL CMFCTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCTestView 绘图

void CMFCTestView::OnDraw(CDC* pDC)
{
	CMFCTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	pDC->TextOut(0, 0, "胡");

	// 设置字体
	CFont font;
	font.CreatePointFont(200, _T("Arial"));
	CFont* pOldFont = pDC->SelectObject(&font);

	// 设置颜色和画笔
	CPen pen1(PS_DOT, 1, RGB(255, 0, 0)); // 红色画笔
	CPen pen2(PS_SOLID, 1, RGB(0, 255, 0)); // 绿色画笔
	CPen pen3(PS_SOLID, 1, RGB(0, 0, 255)); // 蓝色画笔

	// 绘制姓名
	CString name = _T("Your Name");
	pDC->SetTextColor(RGB(255, 0, 0)); // 红色
	pDC->SelectObject(&pen1);
	pDC->TextOut(50, 50, name);

	pDC->SetTextColor(RGB(0, 255, 0)); // 绿色
	pDC->SelectObject(&pen2);
	pDC->TextOut(50, 100, name);

	pDC->SetTextColor(RGB(0, 0, 255)); // 蓝色
	pDC->SelectObject(&pen3);
	pDC->TextOut(50, 150, name);

	// 恢复原始字体和画笔
	pDC->SelectObject(pOldFont);

	CBrush* BrushOld, BrushNew;//创建画刷
	COLORREF BrushClr[] = { RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255) };//给画刷上色
	for (int i = 0; i < 3; i++)
	{
		BrushNew.CreateSolidBrush(BrushClr[i]);//创建画刷
		BrushOld = pDC->SelectObject(&BrushNew);//选用画刷
		pDC->Ellipse(0 + 25 * i, 0 + 25 * i, 500 + 25 * i, 500 + 25 * i);
		pDC->SelectObject(BrushOld);//还原画刷
		BrushNew.DeleteObject();//释放画刷
	}


}


// CMFCTestView 打印

BOOL CMFCTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCTestView 诊断

#ifdef _DEBUG
void CMFCTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTestDoc* CMFCTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTestDoc)));
	return (CMFCTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTestView 消息处理程序


void CMFCTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nLeft++;
	CString strOutput; // 产生用于输出的格式化字符串
	strOutput.Format("鼠标左键按下的次数: %d", m_nLeft);
	MessageBox(strOutput); // 弹出提示信息框

	CView::OnLButtonDown(nFlags, point);
}


void CMFCTestView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nRight++;
	CString strOutput; // 产生用于输出的格式化字符串
	strOutput.Format("鼠标右键按下的次数: %d", m_nRight);
	MessageBox(strOutput); // 弹出提示信息框
	CView::OnRButtonDown(nFlags, point);
}


void CMFCTestView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == 'X') {
		MessageBox("您的学号为：Y30221028");
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCTestView::OnText()
{
	// TODO: 在此添加命令处理程序代码

	CClientDC dc(this);
	dc.TextOutA(500, 30, "菜单设计程序");//直接输出文本
	dc.TextOutA(600, 30, "三毛是猪猪精！笑死人，哈哈哈！");//直接输出文本
}


void CMFCTestView::OnPicture()
{
	// TODO: 在此添加命令处理程序代码

	CBrush* BrushOld, BrushNew;

	CDC* pDC = GetDC();	// 获取设备上下文
	BrushNew.CreateSolidBrush(RGB(255, 0, 0));
	BrushOld = pDC->SelectObject(&BrushNew);
	pDC->Rectangle(200, 200, 500, 300);
	pDC->SelectObject(BrushOld);
	BrushNew.DeleteObject();

}


void CMFCTestView::OnOpen()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("打开");
}


void CMFCTestView::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("工具栏设计程序");
}


void CMFCTestView::OnShowName()
{
	// TODO: 在此添加命令处理程序代码
	ShowNameDlg dlg;
	if (dlg.DoModal() == IDOK) {
		CDC* pDC = GetDC();	// 获取设备上下文
		//pdc->textouta(dlg.m_x, dlg.m_y, "husang");

		// 设置字体
		CFont font;
		font.CreatePointFont(200, _T("Arial"));
		CFont* pOldFont = pDC->SelectObject(&font);

		// 设置颜色
		pDC->SetTextColor(RGB(0, 0, 255)); // 蓝色

		// 绘制姓名在指定坐标 (100, 100)
		CString name = _T("Husang");
		pDC->TextOut(dlg.m_x, dlg.m_y, name);

		// 恢复原始字体
		pDC->SelectObject(pOldFont);

		// 释放设备上下文
		ReleaseDC(pDC);
	}

}
