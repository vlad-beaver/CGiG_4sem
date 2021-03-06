
// ChildView.cpp: реализация класса CChildView
//

#include "stdafx.h"
#include "Planets.h"
#include "ChildView.h"
#include "CMatrix.H"
#include "LibChart2D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_DRAW, &CChildView::OnDraw)
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
	if (Start)
	{
		SolarSystem.getRectWorld(RectWorld);
		RectWindow = SolarSystem.getRectWindow();
		setMode(dc, RectWindow, RectWorld);
		SolarSystem.draw(dc);
		dc.SetMapMode(MM_ANISOTROPIC);
	}
}
void CChildView::OnDraw()
{
	SolarSystem.setDt(0);
	SolarSystem.setCoords();
	SolarSystem.setDt(0.1);
	DtTimer = 30;
	Start = true;
	Invalidate();
}
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	SolarSystem.setCoords();
	Invalidate();
}
void CChildView::OnLButtonDown(UINT flags, CPoint point)
{
	SetTimer(1, DtTimer, NULL);
}

void CChildView::OnRButtonDown(UINT flags, CPoint point)
{
	KillTimer(1);
}