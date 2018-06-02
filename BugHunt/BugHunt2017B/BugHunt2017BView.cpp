
// BugHunt2017BView.cpp : CBugHunt2017BView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "BugHunt2017B.h"
#endif

#include "BugHunt2017BDoc.h"
#include "BugHunt2017BView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBugHunt2017BView

IMPLEMENT_DYNCREATE(CBugHunt2017BView, CView)

BEGIN_MESSAGE_MAP(CBugHunt2017BView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_CREATE()
ON_WM_LBUTTONDOWN()
ON_WM_KEYDOWN()
//ON_WM_ACTIVATE()
ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CBugHunt2017BView 构造/析构

CBugHunt2017BView::CBugHunt2017BView()
{
	// TODO: 在此处添加构造代码

}

CBugHunt2017BView::~CBugHunt2017BView()
{
}

BOOL CBugHunt2017BView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBugHunt2017BView 绘制

void CBugHunt2017BView::OnDraw(CDC* pDC)
{
	CBugHunt2017BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	// 绘制背景青蛙
	CRect clientRect;
	GetClientRect(&clientRect);

	int cx = pDoc->m_bmpBackgrang.GetWidth();
	int cy = pDoc->m_bmpBackgrang.GetHeight();

	float bmpAspect = float(cy) / cx;

	cx = clientRect.Width()* 0.9;
	cy = cx*bmpAspect;
	int x = (clientRect.Width() - cx)/2;
	int y = (clientRect.Height()- cy)/2;

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap memBmp;
	memBmp.CreateCompatibleBitmap(pDC, clientRect.Width(), clientRect.Height());
	memDC.SelectObject(&memBmp);
	memDC.FillSolidRect(0, 0, clientRect.Width(), clientRect.Height(), RGB(255, 255, 255));
	
	// BGD绘制
	pDoc->m_bmpBackgrang.StretchBlt(
		memDC.GetSafeHdc(),
		x, y, cx, cy
	);

	// 绘制虫子
	for each(auto pBug in pDoc->m_listBug)
		if (pBug)
			pBug->Draw(&memDC);

	// 绘制青蛙
	for each(auto pFrog in pDoc->m_listFrog)
		if (pFrog)
			pFrog->Draw(&memDC);

	pDC->BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memDC, 0 ,0, SRCCOPY);

	// 介绍
	CString intro;
	intro = "按Z吃虫, 方向键上下左右进行操作, 空格无双";
	pDC->TextOutW(2, 2, intro);

}


// CBugHunt2017BView 打印

BOOL CBugHunt2017BView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBugHunt2017BView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBugHunt2017BView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CBugHunt2017BView 诊断

#ifdef _DEBUG
void CBugHunt2017BView::AssertValid() const
{
	CView::AssertValid();
}

void CBugHunt2017BView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBugHunt2017BDoc* CBugHunt2017BView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBugHunt2017BDoc)));
	return (CBugHunt2017BDoc*)m_pDocument;
}
#endif //_DEBUG


// CBugHunt2017BView 消息处理程序


int CBugHunt2017BView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	Bug::SetParentWnd(this);
	
	Frog::SetParentWnd(this);	// I DON'T KNOW

	SetTimer(1, 50, NULL);
	return 0;
}


void CBugHunt2017BView::OnTimer(UINT_PTR nIDEvent)
{
	CBugHunt2017BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
		case 1:
			for each(auto pBug in pDoc->m_listBug)
				if (pBug)
					pBug->Move();
			Invalidate();
			break;

		case 2:
			for each(auto pFrog in pDoc->m_listFrog)
				if (pFrog)
				{
					CRect now_RC = pFrog->GetRC();
					pDoc->m_listFrog.pop_back();
					Frog* pFrog = new Frog(_T(".\\res\\FrogRed.bmp"), 1, 2, 40 ,10);
					pFrog->SetRC(now_RC);
					pDoc->m_listFrog.push_back(pFrog);
					break;
				}
			KillTimer(2);
			break;
			 
		case 3:
			for each(auto pFrog in pDoc->m_listFrog)
				if (pFrog)
				{
					CRect now_RC = pFrog->GetRC();
					pDoc->m_listFrog.pop_back();
					Frog* pFrog = new Frog(_T(".\\res\\FrogBlue.bmp"), 1, 2, 20, 4);
					pFrog->SetRC(now_RC);
					pDoc->m_listFrog.push_back(pFrog);
					break;
				}
			KillTimer(3);
			break;
	}

	// Frog吃Bug

	// MFrog吃Bug

	CView::OnTimer(nIDEvent);
}


BOOL CBugHunt2017BView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	// return CView::OnEraseBkgnd(pDC);
	return TRUE;
}


void CBugHunt2017BView::OnLButtonDown(UINT nFlags, CPoint point)
{

	CBugHunt2017BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	// 鼠标点杀Bug
	//for (size_t i = 0; i < pDoc->m_listBug.size(); ++i)
	//{
	//	if (pDoc->m_listBug[i] == NULL)
	//		continue;


	//	pDoc->m_listBug[i]->IsHit(point);
	//	if (pDoc->m_listBug[i]->IsDying())
	//	{
	//		delete pDoc->m_listBug[i];
	//		pDoc->m_listBug[i] = NULL;				// 没有指向对象的指针必须置为空
	//	}
	//}

	// Frog鼠标控制
		for (size_t i = 0; i < pDoc->m_listFrog.size(); ++i)
		{
			if (pDoc->m_listFrog[i] == NULL)
				continue;
			pDoc->m_listFrog[i]->Move(point);
		}
	CView::OnLButtonDown(nFlags, point);
}


void CBugHunt2017BView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CBugHunt2017BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此添加消息处理程序代码和/或调用默认值

	// 键盘控制Frog
	for each(auto pFrog in pDoc->m_listFrog)
		if (pFrog)
		{
			pFrog->Move(nChar);
		}

	switch (nChar)
	{
	case 'z':
	case 'Z':
		for (size_t i = 0; i < pDoc->m_listFrog.size(); ++i)
		{
			if (pDoc->m_listFrog[i] == NULL)
				continue;

			for (size_t j = 0; j < pDoc->m_listBug.size(); ++j)
			{
				if (pDoc->m_listBug[j] == NULL)
					continue;

				if (pDoc->m_listFrog[i]->GetRC().PtInRect(pDoc->m_listBug[j]->GetRC().CenterPoint()))
				{
					pDoc->m_listBug[j]->Eaten(pDoc->m_listFrog[i]->GetAP());
				}

				if (pDoc->m_listBug[j]->IsDying())
				{
					delete pDoc->m_listBug[j];
					pDoc->m_listBug[j] = NULL;				// 没有指向对象的指针必须置为空
					break;
				}
			}
		}
		break;
	case 0x20:
		SetTimer(2, 100, NULL);
		SetTimer(3, 1000 * 4, NULL);

		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


//void CBugHunt2017BView::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
//{
//	CView::OnActivate(nState, pWndOther, bMinimized);
//
//	// TODO: 在此处添加消息处理程序代码
//}


void CBugHunt2017BView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
}
