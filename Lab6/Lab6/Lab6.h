
// Lab6.h: основной файл заголовка для приложения Lab6
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CLab6App:
// Сведения о реализации этого класса: Lab6.cpp
//

class CLab6App : public CWinApp
{
public:
	CLab6App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab6App theApp;
