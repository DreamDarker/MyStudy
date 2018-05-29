#pragma once
#include "Sprite.h"
#include "Bug.h"

class Frog: public Sprite
{
public:
	Frog(const CString& strBitmapFile, int nRow, int nCol, int nMoveStep);		// 图片源，行，列，步长

	virtual ~Frog();

	void ChangeDirection(int idx);		// [0-1]
	void Move(UINT nChar);
	void Move(CPoint point);
	void Move();
	void Eat(Bug * pBug);

private:
	int m_iCurrentDir;      // 现在的方向
	int nMoveStep;			// 步长
};