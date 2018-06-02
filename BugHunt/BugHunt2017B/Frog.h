#pragma once
#include "Sprite.h"
#include "Bug.h"

class Frog: public Sprite
{
public:
	Frog(const CString strBitmapFile, int nRow, int nCol, int nMoveStep, int attack_power);		// 图片源，行，列，步长, 攻击力

	virtual ~Frog();

	void ChangeDirection(int idx);		// [0-1]
	void Move(UINT nChar);
	void Move(CPoint point);
	void Move();

	void Eat(Bug * pBug);
	int GetAP();
	void SetAP(int n);
	// void ChangePic(CString PicFile, int n_row, int n_col);

private:
	// CString m_nstrBmpFile;	// 图片路径
	int m_iCurrentDir;      // 现在的方向
	int m_nMoveStep;		// 步长
	int m_nattack_power;	// 攻击力
};