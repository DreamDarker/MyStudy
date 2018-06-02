#pragma once
#include "Sprite.h"
#include "Bug.h"

class Frog: public Sprite
{
public:
	Frog(const CString strBitmapFile, int nRow, int nCol, int nMoveStep, int attack_power);		// ͼƬԴ���У��У�����, ������

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
	// CString m_nstrBmpFile;	// ͼƬ·��
	int m_iCurrentDir;      // ���ڵķ���
	int m_nMoveStep;		// ����
	int m_nattack_power;	// ������
};