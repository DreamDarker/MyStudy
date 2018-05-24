#ifndef _LYM_SPRITE_INC
#define _LYM_SPRITE_INC

#pragma once
#include <atlimage.h>

#define PI 3.1415926

class Sprite
{
public:
	Sprite();
	virtual ~Sprite();

	void Draw(CDC* pDC);
	void Erase(CDC* pDC){}

	virtual void Move() = 0;

	static void SetParentWnd(CWnd* pParent)
	{
		m_pParentWnd = pParent;
	}

	const CRect GetRC();
protected:
	void LoadImage(const CString& strBitmapFile, int nRow, int nCol);
	void SetPictureIdx(int idx);
	int  GetPictureIdx()const{ return m_idxPic; }

	int  GetPictureCount()const{ return m_nRow*m_nCol; }
	CSize GetPictureDimension()const;

	BOOL AtLeftEdge()const;
	BOOL AtRightEdge()const;
	BOOL AtTopEdge()const;
	BOOL AtBottomEdge()const;

protected:
	CRect m_rcSprite;   //精灵的大小和位置
	int   m_nMoveStep;  //移动步长，单位为像素
	int   m_nStepX;     //步长在X轴上的投影
	int   m_nStepY;     //步长在y轴上的投影

	static CWnd* m_pParentWnd; //所有精灵的显示窗口
	CImage m_Bmp;       //精灵图像

private:
	int    m_nRow;      //精灵图像阵列的行数
	int    m_nCol;      //精灵图像阵列的列数
	int    m_idxPic;    //精灵当前运动方向图片的一维索引值，值范围[0, m_nRow*m_nCol)
};

#endif //_LYM_SPRITE_INC