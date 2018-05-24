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
	CRect m_rcSprite;   //����Ĵ�С��λ��
	int   m_nMoveStep;  //�ƶ���������λΪ����
	int   m_nStepX;     //������X���ϵ�ͶӰ
	int   m_nStepY;     //������y���ϵ�ͶӰ

	static CWnd* m_pParentWnd; //���о������ʾ����
	CImage m_Bmp;       //����ͼ��

private:
	int    m_nRow;      //����ͼ�����е�����
	int    m_nCol;      //����ͼ�����е�����
	int    m_idxPic;    //���鵱ǰ�˶�����ͼƬ��һά����ֵ��ֵ��Χ[0, m_nRow*m_nCol)
};

#endif //_LYM_SPRITE_INC