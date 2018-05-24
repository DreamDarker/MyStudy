#include "stdafx.h"
#include "Sprite.h"

CWnd* Sprite::m_pParentWnd = 0;

Sprite::Sprite()
{
	m_nMoveStep = 0;  
	m_nStepX    = 0; 
	m_nStepY    = 0; 
	m_nRow      = 0;  
	m_nCol      = 0;  
	m_idxPic    = 0;
}
Sprite::~Sprite()
{

}

const CRect Sprite::GetRC()
{
	CRect m_i = m_rcSprite;
	return m_i;
}

void Sprite::LoadImage(const CString& strBitmapFile, int nRow, int nCol)
{ 
	ASSERT(strBitmapFile != "" && nRow > 0 && nCol > 0);

	HRESULT ret = m_Bmp.Load(strBitmapFile);
	if (ret == NOERROR)
	{
		m_nRow = nRow;
		m_nCol = nCol;

		int x = rand() % 400 + 100;
		int y = rand() % 400 + 100;
		int cx = m_Bmp.GetWidth() / nCol;
		int cy = m_Bmp.GetHeight() / nRow;
		m_rcSprite.SetRect(x, y, x+cx, y+cy);
	}
	else
	{
		CString strPrompt;
		strPrompt.Format(_T("Load image file <%s> failed!"), strBitmapFile);
		AfxMessageBox(strPrompt);
	}
}

CSize Sprite::GetPictureDimension()const
{
	int width  = m_Bmp.GetWidth();
	int height = m_Bmp.GetHeight();
	return CSize(width, height);
}

BOOL Sprite::AtLeftEdge()const
{
	if (m_pParentWnd && m_pParentWnd->IsWindowVisible())
	{
		CRect rectClient;
		m_pParentWnd->GetClientRect(rectClient);

		return m_rcSprite.left <= rectClient.left;
	}

	return FALSE;
}
BOOL Sprite::AtRightEdge()const
{
	if (m_pParentWnd && m_pParentWnd->IsWindowVisible())
	{
		CRect rectClient;
		m_pParentWnd->GetClientRect(rectClient);

		return m_rcSprite.right >= rectClient.right;
	}

	return FALSE;
}
BOOL Sprite::AtTopEdge()const
{
	if (m_pParentWnd && m_pParentWnd->IsWindowVisible())
	{
		CRect rectClient;
		m_pParentWnd->GetClientRect(rectClient);

		return m_rcSprite.top <= rectClient.top;
	}

	return FALSE;
}
BOOL Sprite::AtBottomEdge()const
{
	if (m_pParentWnd && m_pParentWnd->IsWindowVisible())
	{
		CRect rectClient;
		m_pParentWnd->GetClientRect(rectClient);

		return m_rcSprite.bottom >= rectClient.bottom;
	}

	return FALSE;
}

void Sprite::Draw(CDC* pDC)
{
	ASSERT(pDC);
	if (!pDC)
		return;

	int cx = m_rcSprite.Width();
	int cy = m_rcSprite.Height();

	int iRow = m_idxPic / m_nCol;
	int iCol = m_idxPic % m_nCol;
	int x = iCol * cx;
	int y = iRow * cy;

	COLORREF clrBknd = m_Bmp.GetPixel(0, 0);
	HDC      hDC = pDC->GetSafeHdc();

	m_Bmp.TransparentBlt(hDC, 
		                 m_rcSprite.left, m_rcSprite.top, cx, cy,
	                     x, y, cx, cy, 
		                 clrBknd);
}

void Sprite::SetPictureIdx(int idx) 
{ 
	m_idxPic = idx; 

	double deg = 0;
	if(idx > 0)
		deg = 360.0 * idx /GetPictureCount() ;

	m_nStepX =  int(m_nMoveStep*cos(deg / 180.0*PI));
	m_nStepY = -int(m_nMoveStep*sin(deg / 180.0*PI));
}

