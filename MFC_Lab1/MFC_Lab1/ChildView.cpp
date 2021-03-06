
// ChildView.cpp: реализация класса CChildView
//

#include "stdafx.h"
#include "MFC_Lab1.h"
#include "ChildView.h"
#include "Funcs.h"

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
	ON_COMMAND(ID_32771, &CChildView::Mat_View)
	ON_COMMAND(ID_32772, &CChildView::Fun_View)
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
	
	// TODO: Добавьте код обработки сообщений
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}
void CChildView::Mat_View()
{
	RedrawWindow();
	CDC *dc = GetDC(); // контекст устройства для рисования
	CMatrix a(3, 3);
	CMatrix b(3, 3);
	CMatrix v1(3);
	CMatrix v2(3);
	fillMatrix(a, 8);
	fillMatrix(b, 1);
	fillMatrix(v1, 10);
	fillMatrix(v2, 16);
	printMatrix(dc, 250, 100, L"Matrix A", a);
	printMatrix(dc, 450, 100, L"Matrix B", b);
	printMatrix(dc, 850, 100, L"Vector V1", v1);
	printMatrix(dc, 1050, 100, L"Vector V2", v2);
	printMatrix(dc, 250, 400, L"A + B", a + b);
	printMatrix(dc, 450, 400, L"A * B", a * b);
	printMatrix(dc, 650, 400, L"A * V1", a * v1);
	printMatrix(dc, 850, 400, L"V1^T * V2", v1.Transp() * v2);
	printMatrix(dc, 1050, 400, L"V1^T * A * V2", v1.Transp() * a * v2);
}


void CChildView::Fun_View()
{
	RedrawWindow();
	CDC *dc = GetDC(); // контекст устройства для рисования
	CMatrix v1(3);
	CMatrix v2(3);
	CMatrix point(3);
	fillMatrix(v1, 10);
	fillMatrix(v2, 16);
	fillMatrix(point, 1);
	printMatrix(dc, 250, 50, L"Vector V1", v1);
	printMatrix(dc, 450, 50, L"Vector V2", v2);
	printMatrix(dc, 650, 50, L"Point P (sferical)", point);
	printMatrix(dc, 50, 300, L"V1 x V2", vectorProduct(v1, v2));
	printNumber(dc, 250, 300, L"V1 * V2", scalarProduct(v1, v2));
	printNumber(dc, 450, 300, L"|V1|", module(v1));
	printNumber(dc, 650, 300, L"cos(V1 /\\ V2)", cos(v1, v2));
	printMatrix(dc, 850, 300, L"Point P (rectangle)", sphericalToCartesian(point));
}
