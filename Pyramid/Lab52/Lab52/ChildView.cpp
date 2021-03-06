
// ChildView.cpp: реализация класса CChildView
//

#include "stdafx.h"
#include "Lab52.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	P.RedimMatrix(3);
	RW.RedimMatrix(4);
	RW(0) = 100;	// окно отображения
	RW(1) = 100;
	RW(2) = 500;
	RW(3) = 500;
	P(0) = 10;		// координаты камеры
	P(1) = 315;
	P(2) = 225;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_PYRAMID1, CChildView::OnPyramid1)
	ON_COMMAND(ID_PYRAMID2, CChildView::OnPyramid2)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// Обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	
	if (Draw)
	{
		if (DrInvis)
			Pyramid.Draw1(dc, P, RW);
		else Pyramid.Draw(dc, P, RW);
	}
	char buf[255];
}

void CChildView::OnPyramid1()
{
	Draw = true;
	DrInvis = true;
	InvalidateRect(0);
}
void CChildView::OnPyramid2()
{
	Draw = true;
	DrInvis = false;
	InvalidateRect(0);
}
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == 37) // ←
		P(1) -= 1;
	if (nChar == 38 && P(2) <= 270) // ↑
		P(2) += 1;
	if (nChar == 39) // →
		P(1) += 1;
	if (nChar == 40 && P(2) >= 90) // ↓
		P(2) -= 1;
	if (P(2) > 270)
		P(2) = 270;
	if (P(2) < 90)
		P(2) = 90;
	if (abs(P(1)) > 360)
		P(1) = (int)P(1) % 360;
	if (P(2) > 270)
		P(2) = 270;
	if (P(2) < 90)
		P(2) = 90;
	InvalidateRect(0);
}
