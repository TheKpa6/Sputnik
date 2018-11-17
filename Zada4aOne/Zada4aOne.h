
// Zada4aOne.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CZada4aOneApp:
// О реализации данного класса см. Zada4aOne.cpp
//

class CZada4aOneApp : public CWinApp
{
public:
	CZada4aOneApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CZada4aOneApp theApp;