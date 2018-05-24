
// BugHunt2017BView.cpp : CBugHunt2017BView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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
END_MESSAGE_MAP()

// CBugHunt2017BView ����/����

CBugHunt2017BView::CBugHunt2017BView()
{
	// TODO: �ڴ˴���ӹ������

}

CBugHunt2017BView::~CBugHunt2017BView()
{
}

BOOL CBugHunt2017BView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CBugHunt2017BView ����

void CBugHunt2017BView::OnDraw(CDC* pDC)
{
	CBugHunt2017BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	// ���Ʊ�������
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
	
	pDoc->m_bmpBackgrang.StretchBlt(
		memDC.GetSafeHdc(),
		x, y, cx, cy
	);

	// ���Ƴ���
	for each(auto pBug in pDoc->m_listBug)
		if (pBug)
			pBug->Draw(&memDC);

	// ��������
	for each(auto pFrog in pDoc->m_listFrog)
	pFrog->Draw(&memDC);

	pDC->BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memDC, 0 ,0, SRCCOPY);


}


// CBugHunt2017BView ��ӡ

BOOL CBugHunt2017BView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CBugHunt2017BView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CBugHunt2017BView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CBugHunt2017BView ���

#ifdef _DEBUG
void CBugHunt2017BView::AssertValid() const
{
	CView::AssertValid();
}

void CBugHunt2017BView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBugHunt2017BDoc* CBugHunt2017BView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBugHunt2017BDoc)));
	return (CBugHunt2017BDoc*)m_pDocument;
}
#endif //_DEBUG


// CBugHunt2017BView ��Ϣ�������


int CBugHunt2017BView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
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

	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
		case 1:
			for each(auto pBug in pDoc->m_listBug)
				if (pBug)
					pBug->Move();
			Invalidate();
			break;
	}
	CView::OnTimer(nIDEvent);
}


BOOL CBugHunt2017BView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	// return CView::OnEraseBkgnd(pDC);
	return TRUE;
}


void CBugHunt2017BView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CBugHunt2017BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	for (size_t i = 0; i < pDoc->m_listBug.size(); ++i)
	{
		if (pDoc->m_listBug[i] == NULL)
			continue;


		pDoc->m_listBug[i]->IsHit(point);
		if (pDoc->m_listBug[i]->IsDying())
		{
			delete pDoc->m_listBug[i];
			pDoc->m_listBug[i] = NULL;				// û��ָ������ָ�������Ϊ��
		}
	}

	// Frog������ TODO


	CView::OnLButtonDown(nFlags, point);
}


void CBugHunt2017BView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CBugHunt2017BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	// ���̿���Frog
	for each(auto pFrog in pDoc->m_listFrog)
		if (pFrog)
		{
			switch (nChar)
			{
			case VK_LEFT:
				pFrog->ChangeDirection(1);
				pFrog->Move('L');
				break;
			case VK_RIGHT:
				pFrog->ChangeDirection(0);
				pFrog->Move('R');
				break;
			case VK_UP:
				pFrog->Move('U');
				break;
			case VK_DOWN:
				pFrog->Move('D');
				break;
			}
		}

	// Frog�Գ���


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
