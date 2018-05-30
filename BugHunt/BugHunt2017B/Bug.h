#pragma once
#include "Sprite.h"

class Bug : public Sprite
{
public:
	Bug(const CString& strBitmapFile, int nRow, int nCol,
		int nMoveStep, int nSpeed, int nHitsRequared,
		int nDirChangeProb);		// (图片源， 行， 列， 步子大小， 速度， 命（打击次数）， 改变方向概率）
	virtual ~Bug();

	BOOL IsEat();		// ADDITION

	BOOL IsHit(const CPoint& ptMouse);
	BOOL IsDying()const { return m_iHitsTaken >= m_nHitsRequared; }
	void Kill(CDC* pDC) { ; }

	void ChangeDirection();
	virtual void Move() = 0;

	void Eaten(int n);

protected:
	int  GetCurrDir()const{ return m_iCurrentDir; }
	void SetCurrDir(int iDirection){ m_iCurrentDir = iDirection; }
	int  GetDirChangeProb()const{ return m_nDirChangeProb; }

protected:
	int m_nHitsRequared;    //the requared hit number to kill the bug
	int m_iHitsTaken;       //the hit number that bug has be taken
	int m_nDirChangeProb;   //the probs of the bug changing direction
	int m_iCurrentDir;      //the current moving direction
	int m_nSpeed;           //the moving speed of bug (the time to refresh, Unite: ms) 
};

class FastBug : public Bug
{
public:
	FastBug(const CString& strBitmapFile, int nRow, int nCol,
		int nMoveStep, int nSpeed, int nHitsRequared,
		int nDirChangeProb) :
		Bug(strBitmapFile, nRow, nCol, nMoveStep, nSpeed, nHitsRequared, nDirChangeProb){}

	~FastBug(){}

	virtual void Move();
};

class SlowBug : public Bug
{
public:
	SlowBug(const CString& strBitmapFile, int nRow, int nCol,
		int nMoveStep, int nSpeed, int nHitsRequared,
		int nDirChangeProb):
		Bug(strBitmapFile, nRow, nCol, nMoveStep, nSpeed, nHitsRequared, nDirChangeProb){}

	~SlowBug(){}

	virtual void Move();
};