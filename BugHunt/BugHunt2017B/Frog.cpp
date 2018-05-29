#include "stdafx.h"
#include "Frog.h"
#include "Bug.h"
#include <WinUser.h>
#include <math.h>

Frog::Frog(const CString & strBitmapFile, int nRow, int nCol, int nMoveStep)
{
	LoadImage(strBitmapFile, nRow, nCol);

	m_nMoveStep = nMoveStep;

	m_iCurrentDir = 0;
}

Frog::~Frog()
{

}

void Frog::ChangeDirection(int idx)
{
	SetPictureIdx(idx);
}

void Frog::Move(UINT nChar)				// ¼üÅÌMove
{
	switch (nChar)
	{
	case 0x25 :
		ChangeDirection(1);
		m_rcSprite.OffsetRect(-m_nMoveStep, 0);
		break;
	case 0x27 :	
		ChangeDirection(0);
		m_rcSprite.OffsetRect(m_nMoveStep, 0);
		break;
	case 0x26 :
		m_rcSprite.OffsetRect(0, -m_nMoveStep);
		break;
	case 0x28 :
		m_rcSprite.OffsetRect(0, m_nMoveStep);
		break;
	}

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
}

void Frog::Move(CPoint point)			// Êó±êMove
{
	int x_del = point.x - m_rcSprite.CenterPoint().x;
	int y_del = point.y - m_rcSprite.CenterPoint().y;

	if (x_del > 0) ChangeDirection(0);
	else ChangeDirection(1);

	int x_off = m_nMoveStep * x_del / sqrt(x_del*x_del + y_del*y_del);
	int y_off = m_nMoveStep * y_del / sqrt(y_del*y_del + y_del*y_del);
	m_rcSprite.OffsetRect(x_off, y_off);
}

void Frog::Move()
{
	m_rcSprite.OffsetRect(m_nStepX, m_nStepY);
}

void Frog::Eat(Bug *pBug)
{

	POINT center = pBug->GetRC().CenterPoint();

	if (m_rcSprite.PtInRect(center))
	{
		pBug->Eaten();
	}
}
