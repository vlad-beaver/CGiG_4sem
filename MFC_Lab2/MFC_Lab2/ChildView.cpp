
// ChildView.cpp: реализация класса CChildView
//

#include "stdafx.h"
#include "MFC_Lab2.h"
#include "ChildView.h"
#include "BitMap.h"

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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_IMAGE_OPEN, &CChildView::OnImageOpen)
	ON_COMMAND(ID_IMAGE_OPENINPOINT, &CChildView::OnImageOpeninpoint)
	ON_COMMAND(ID_IMAGE_SAVE, &CChildView::OnImageSave)
	ON_COMMAND(ID_IMAGE_CLEAR, &CChildView::OnImageClear)
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
	if (theApp.index == 1)
		ShowBitMap(theApp.hwnd, theApp.hBit, theApp.From.x, theApp.From.y);	//вывод изображения
}



void CChildView::OnLButtonDown(UINT flags, CPoint point)
{
	theApp.From = point;
}


void CChildView::OnLButtonUp(UINT flags, CPoint point)
{
	theApp.To = point;
}

void CChildView::OnImageOpen()
{
	theApp.index = 1;
	theApp.From.x = def_X;
	theApp.From.y = def_Y;
	theApp.LoadImageBMP(theApp.From);
}


void CChildView::OnImageOpeninpoint()
{
	theApp.index = 1;
	theApp.LoadImageBMP(theApp.From);
}


void CChildView::OnImageSave()
{
	theApp.SaveArea();
}


void CChildView::OnImageClear()
{
	theApp.index = 0;
	this->Invalidate();
}
