
// jisuanqi.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CjisuanqiApp: 
// �йش����ʵ�֣������ jisuanqi.cpp
//

class CjisuanqiApp : public CWinApp
{
public:
	CjisuanqiApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CjisuanqiApp theApp;