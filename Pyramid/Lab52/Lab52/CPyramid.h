#pragma once
#include "stdafx.h"
#include "CMatrix.h"
class CRectD
{
public:
	double left, top, right, bottom;
	CRectD() { left = top = right = bottom = 0; }
	operator CRect() { return CRect(left, top, right, bottom); }
};
class CPyramid
{
private:
	CMatrix Vertices, View;
	void GetRect(CMatrix &Vert, CRectD &RectView);
public:
	CPyramid();
	void Draw(CDC &dc, CMatrix &P, CMatrix &RW); // ��� ��������� ������
	void Draw1(CDC &dc, CMatrix &P, CMatrix &RW); // � ���������� �������
};
CMatrix CreateViewCoords(double r, double phi, double theta);