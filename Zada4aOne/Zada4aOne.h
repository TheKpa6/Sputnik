
// Zada4aOne.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CZada4aOneApp:
// � ���������� ������� ������ ��. Zada4aOne.cpp
//

class CZada4aOneApp : public CWinApp
{
public:
	CZada4aOneApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CZada4aOneApp theApp;