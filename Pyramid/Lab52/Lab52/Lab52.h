
// Lab52.h: основной файл заголовка для приложения Lab52
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CLab52App:
// Сведения о реализации этого класса: Lab52.cpp
//

class CLab52App : public CWinApp
{
public:
	CLab52App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab52App theApp;
