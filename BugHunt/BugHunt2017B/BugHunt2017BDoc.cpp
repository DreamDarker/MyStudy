
// BugHunt2017BDoc.cpp : CBugHunt2017BDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "BugHunt2017B.h"
#endif

#include "BugHunt2017BDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBugHunt2017BDoc

IMPLEMENT_DYNCREATE(CBugHunt2017BDoc, CDocument)

BEGIN_MESSAGE_MAP(CBugHunt2017BDoc, CDocument)
END_MESSAGE_MAP()


// CBugHunt2017BDoc ����/����

CBugHunt2017BDoc::CBugHunt2017BDoc()
{
	// TODO: �ڴ����һ���Թ������

	// DID

	m_bmpBackgrang.Load(_T(".\\Bitmap\\Frog.jpg"));

	// Add 2 SlowBug objects
	for (int i = 0; i < 2; i++)
	{
		Bug* pBug = new SlowBug(_T(".\\Bitmap\\RedBug96x96.bmp"), 4, 18,  10, 2, 2, 20);
		m_listBug.push_back(pBug);
	}

	// Add 3 FastBug objs
	for (int i = 0; i < 3; i++)
	{
		Bug* pBug = new FastBug(_T(".\\Bitmap\\BlueBug36x36.bmp"), 4, 18, 10, 4, 2, 30);
		m_listBug.push_back(pBug);
	}

	for (int i = 0; i < 1; i++)
	{
		Frog* pFrog = new Frog(_T(".\\Bitmap\\FrogBlue.bmp"), 1, 2, 15);
		m_listFrog.push_back(pFrog);
	}
}

CBugHunt2017BDoc::~CBugHunt2017BDoc()
{
	for each(auto pBug in m_listBug)		// auto == 
		if (pBug)
			delete pBug;

	for each(auto pFrog in m_listFrog)
		if (pFrog)
			delete pFrog;
}

BOOL CBugHunt2017BDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CBugHunt2017BDoc ���л�

void CBugHunt2017BDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CBugHunt2017BDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CBugHunt2017BDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CBugHunt2017BDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CBugHunt2017BDoc ���

#ifdef _DEBUG
void CBugHunt2017BDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBugHunt2017BDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CBugHunt2017BDoc ����
