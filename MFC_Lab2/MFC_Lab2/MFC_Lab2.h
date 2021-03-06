
// MFC_Lab2.h: основной файл заголовка для приложения MFC_Lab2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCLab2App:
// Сведения о реализации этого класса: MFC_Lab2.cpp
//

class CMFCLab2App : public CWinApp
{
public:
	CMFCLab2App() noexcept;
	int index;
	HBITMAP hBit;   // hBit - дескриптор рисунка
	HWND hwnd;      // hWnd - дескриптор окна, куда выводится изображение
	CPoint From;
	CPoint To;

// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	void LoadImageBMP(CPoint point);	// загрузка изображения
	void SaveArea();	// сохранить выделенную область окна
	DECLARE_MESSAGE_MAP()
};

extern CMFCLab2App theApp;
