
// BugHunt2017BDoc.cpp : CBugHunt2017BDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CBugHunt2017BDoc 构造/析构

CBugHunt2017BDoc::CBugHunt2017BDoc()
{
	// TODO: 在此添加一次性构造代码

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

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CBugHunt2017BDoc 序列化

void CBugHunt2017BDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CBugHunt2017BDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CBugHunt2017BDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CBugHunt2017BDoc 诊断

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


// CBugHunt2017BDoc 命令
