#include "stdafx.h"
#include "Bug.h"

Bug::Bug(const CString& strBitmapFile, int nRow, int nCol,
	int nMoveStep, int nSpeed, int nHitsRequared,
	int nDirChangeProb)
{
	LoadImage(strBitmapFile, nRow, nCol);

	m_nMoveStep = nMoveStep;
	m_nSpeed = nSpeed;
	m_nHitsRequared = nHitsRequared;
	m_nDirChangeProb = nDirChangeProb;

	m_iHitsTaken = 0;
	m_iCurrentDir = 0;
}

Bug::~Bug()
{

}

BOOL Bug::IsEat()
{
	return 0;
}

BOOL Bug::IsHit(const CPoint& ptMouse)
{
	if (m_rcSprite.PtInRect(ptMouse))
	{
		int x = ptMouse.x - m_rcSprite.left;
		int y = ptMouse.y - m_rcSprite.top;

		BOOL bHit = m_Bmp.GetPixel(x, y) != m_Bmp.GetPixel(0, 0);
		if (bHit)
			++m_iHitsTaken;

		return bHit;
	}

	return FALSE;
}

void Bug::ChangeDirection()
{
	int nProb = rand() % 100;
	if (nProb < m_nDirChangeProb)
	{
		m_iCurrentDir = rand() % GetPictureCount();
		SetPictureIdx(m_iCurrentDir);
	}
}

void Bug::Eaten()
{
	m_iHitsTaken = 10;		// 吃一次的伤害量
}

///////////////////////////////////////////////
//SlowBug

void SlowBug::Move()
{
	ChangeDirection();
	m_rcSprite.OffsetRect(m_nStepX, m_nStepY);

	if (AtLeftEdge() || AtTopEdge() || AtRightEdge() || AtBottomEdge())
	{
		int nDirs = GetPictureCount();
		m_iCurrentDir += nDirs / 2;
		if (m_iCurrentDir > nDirs)
			m_iCurrentDir -= nDirs;

		SetPictureIdx(m_iCurrentDir);
	}
}

/////////////////////////////////////////////////////
//FastBug
void FastBug::Move()
{
	ChangeDirection();

	m_rcSprite.OffsetRect(m_nStepX, m_nStepY);

	CRect rectClient;
	m_pParentWnd->GetClientRect(rectClient);
	
	int xOff = rectClient.Width() - m_rcSprite.Width() - 1;
	int yOff = rectClient.Height() - m_rcSprite.Height() - 1;

	if (AtLeftEdge())
	{
		m_rcSprite.OffsetRect(xOff, 0);
	}
	if (AtTopEdge())
	{
		m_rcSprite.OffsetRect(0, yOff);
	}
	if (AtRightEdge())
	{
		m_rcSprite.OffsetRect(-xOff, 0);
	}
	if (AtBottomEdge())
	{
		m_rcSprite.OffsetRect(0, -yOff);
	}

	SetPictureIdx(m_iCurrentDir);
}



