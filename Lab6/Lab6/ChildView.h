
// ChildView.h: интерфейс класса CChildView
//


#pragma once
#include "CMatrix.h"
#include "LibGraph.h"
#include "LibSurface.h"

// Окно CChildView

class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
public:
	double r, fi, q; // Сферические координаты точки наблюдения в МСК
	//CRectD SRect;	// Область изменеия функции f(x,y) в МСК 
	//CRect  WRect;	// Область в окне для рисования
	CRect WRect;
	int Index;	// Индикатор для OnPaint
	CPlot3D  Graph1, Graph2, Graph3;
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
	afx_msg void OnCPlot3DDef();
	afx_msg void OnCplot3dFunc1();
	afx_msg void OnCplot3dFunc2();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
};

