#pragma once
#include "Sprite.h"

class Frog: public Sprite
{
public:
	Frog(const CString& strBitmapFile, int nRow, int nCol, int nMoveStep);		// ͼƬԴ���У��У�����

	virtual ~Frog();

	void ChangeDirection(int idx);		// [0-1]
	void Move(char m_idirect);
	void Move();
	void Eat(Bug *pBug);

private:
	int m_iCurrentDir;      // ���ڵķ���
	int nMoveStep;			// ����
};