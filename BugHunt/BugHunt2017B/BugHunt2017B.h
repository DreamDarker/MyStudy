
// BugHunt2017B.h : BugHunt2017B Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CBugHunt2017BApp:
// �йش����ʵ�֣������ BugHunt2017B.cpp
//

class CBugHunt2017BApp : public CWinApp
{
public:
	CBugHunt2017BApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBugHunt2017BApp theApp;
