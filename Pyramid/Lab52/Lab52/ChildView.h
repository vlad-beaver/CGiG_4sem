
// ChildView.h: интерфейс класса CChildView
//


#pragma once
#include "CPyramid.h"

// Окно CChildView

class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
private:
	bool Draw = false, DrInvis = true;
	CPyramid Pyramid;
	CMatrix P, RW;
public:

// Операции
public:

// Переопределение
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CChildView();

	// Созданные функции схемы сообщений
protected:
	afx_msg void OnPaint();
	afx_msg void OnPyramid1();
	afx_msg void OnPyramid2();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
};

