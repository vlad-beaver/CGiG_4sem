
// MFC_Lab1.h: основной файл заголовка для приложения MFC_Lab1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCLab1App:
// Сведения о реализации этого класса: MFC_Lab1.cpp
//

class CMFCLab1App : public CWinApp
{
public:
	CMFCLab1App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCLab1App theApp;
