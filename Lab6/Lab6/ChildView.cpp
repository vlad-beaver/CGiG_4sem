
// ChildView.cpp: реализация класса CChildView
//

#include "stdafx.h"
#include "Lab6.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	Index = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_CPlot3D_DEFOU, &CChildView::OnCPlot3DDef)
	ON_COMMAND(ID_CPlot3D_FUNC1, &CChildView::OnCplot3dFunc1)
	ON_COMMAND(ID_CPlot3D_FUNC2, &CChildView::OnCplot3dFunc2)
	ON_WM_SIZE()
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
	CString ss;

	if (Index == 1)Graph1.Draw(dc);
	if (Index == 2)Graph2.Draw(dc);
	if (Index == 3)Graph3.Draw(dc);
	// TODO: Добавьте код обработки сообщений
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}
void CChildView::OnCPlot3DDef()	// Функция Function1
{
	double dx = 0.25, dy = 0.25;
	//double 
	r = 50, fi = 30, q = 45;
	CRectD SpaceRect(-5, 5, 5, -5);
	CRect  WinRect;
	this->GetClientRect(WinRect);
	WinRect.SetRect(WinRect.left + 50, WinRect.top + 50, WinRect.right - 50, WinRect.bottom - 50);
	Graph1.SetFunction(Function1, SpaceRect, dx, dy);	// Function1 	
	Graph1.SetViewPoint(r, fi, q);
	Graph1.SetWinRect(WinRect);
	Index = 1;
	this->Invalidate();
}

void CChildView::OnCplot3dFunc1()//Функция Function2
{

	double dx = 0.25, dy = 0.25;
	//double r=50, fi=0, q=45;
	r = 50, fi = 30, q = 45;
	CRectD SpaceRect(-5, 5, 5, -5);
	CRect  WinRect;
	this->GetClientRect(WinRect);
	WinRect.SetRect(WinRect.left + 50, WinRect.top + 50, WinRect.right - 50, WinRect.bottom - 50);
	Graph2.SetFunction(Function2, SpaceRect, dx, dy);  // Function2 	
	Graph2.SetViewPoint(r, fi, q);
	Graph2.SetWinRect(WinRect);
	Index = 2;
	this->Invalidate();
}

void CChildView::OnCplot3dFunc2()	// Функция Function3
{


	double dx = 0.2, dy = 0.2;//шаг
	r = 50, fi = 30, q = 45;//параметры камеры
	CRectD SpaceRect(-5, 5, 5, -5);//значения диапазона по х и у (у обоих от -5 до 5)
	CRect  WinRect;
	GetClientRect(WinRect);
	WinRect.SetRect(WinRect.left + 200, WinRect.top + 100, WinRect.right - 50, WinRect.bottom - 50);
	Graph3.SetFunction(//задаем функцию
		Function3,//передаем формулу по которой будет рисовать
		SpaceRect,//передаем  значения диапазона отрисовки
		dx, dy);//шаг
	Graph3.SetViewPoint(r, fi, q);//задаем параметры камеры
	Graph3.SetWinRect(WinRect);//задаем прямоугольник в котором будем рисовать
	Index = 3;//передаем параметр отрисовки
	this->Invalidate();
}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	if ((Index == 1) || (Index == 2) || (Index == 3))
	{
		int dx = 50, dy = 50;
		if ((cx > 3 * dx) && (cy > 3 * dy))
		{
			CRect  WinRect;
			this->GetClientRect(WinRect);
			WinRect.DeflateRect(dx, dy);
			if (Index == 1)Graph1.SetWinRect(WinRect);
			if (Index == 2)Graph2.SetWinRect(WinRect);
			if (Index == 3)Graph3.SetWinRect(WinRect);
		}
	}
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CMatrix P(3);
	switch (Index)
	{//
	case 1:
	{
		P = Graph1.GetViewPoint();
		break;
	}
	case 2:
	{
		P = Graph2.GetViewPoint();
		break;
	}
	case 3:
	{
		P = Graph3.GetViewPoint();
		break;
	}
	}//

//double r=P(0), fi=P(1), q=P(2);
	r = P(0), fi = P(1), q = P(2);
	double delta_fi = 5, delta_q = 5;
	switch (nChar)
	{
	case VK_UP:
	{
		double qx = q - delta_q;
		if (qx >= 0)q = qx;
		break;
	}
	case VK_DOWN:
	{
		double qx = q + delta_q;
		if (qx <= 180)q = qx;
		break;
	}
	case VK_LEFT:
	{
		double fix = fi - delta_fi;
		if (fix >= 0)fi = fix;
		break;
	}
	case VK_RIGHT:
	{
		double fix = fi + delta_fi;
		if (fix <= 360)fi = fix;
		break;
	}
	}

	switch (Index)
	{
	case 1:
	{
		Graph1.SetViewPoint(r, fi, q);
		break;
	}

	case 2:
	{
		Graph2.SetViewPoint(r, fi, q);
		break;
	}

	case 3:
	{
		Graph3.SetViewPoint(r, fi, q);
		break;
	}
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
	this->Invalidate();
}

