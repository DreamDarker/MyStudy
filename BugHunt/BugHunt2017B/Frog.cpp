#include "stdafx.h"
#include "Frog.h"
#include "Bug.h"

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

void Frog::Move(char m_idirect)
{
	switch (m_idirect)
	{
	case 'L' :
		m_rcSprite.OffsetRect(-m_nMoveStep, 0);
		break;
	case 'R' :	
		m_rcSprite.OffsetRect(m_nMoveStep, 0);
		break;
	case 'U':
		m_rcSprite.OffsetRect(0, -m_nMoveStep);
		break;
	case 'D':
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

void Frog::Move()
{
}

void Frog::Eat(Bug *pBug)
{
	if (m_rcSprite.PtInRect(pBug->GetRC().CenterPoint))
	{

	}
}
