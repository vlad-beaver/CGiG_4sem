#include "stdafx.h"
#include <stdlib.h>
#include "CMatrix.h"

CMatrix::CMatrix()
{
	n_rows = 1;
	n_cols = 1;
	array = new double*[n_rows];
	for (int i = 0; i < n_rows; i++) array[i] = new double[n_cols];
	for (int i = 0; i < n_rows; i++)
		for (int j = 0; j < n_cols; j++) array[i][j] = 0;
}

//-------------------------------------------------------------------------------
CMatrix::CMatrix(int Nrow, int Ncol)
// Nrow - ����� �����
// Ncol - ����� ��������
{
	n_rows = Nrow;
	n_cols = Ncol;
	array = new double*[n_rows];
	for (int i = 0; i < n_rows; i++) array[i] = new double[n_cols];
	for (int i = 0; i < n_rows; i++)
		for (int j = 0; j < n_cols; j++) array[i][j] = 0;
}

//---------------------------------------------------------------------------------
CMatrix::CMatrix(int Nrow)  //������
// Nrow - ����� �����
{
	n_rows = Nrow;
	n_cols = 1;
	array = new double*[n_rows];
	for (int i = 0; i < n_rows; i++) array[i] = new double[n_cols];
	for (int i = 0; i < n_rows; i++)
		for (int j = 0; j < n_cols; j++) array[i][j] = 0;
}
//---------------------------------------------------------------------------------
CMatrix::~CMatrix()
{
	for (int i = 0; i < n_rows; i++) delete array[i];
	delete array;
}

//---------------------------------------------------------------------------------
double &CMatrix::operator()(int i, int j)
// i - ����� ������
// j - ����� �������
{
	if ((i > n_rows - 1) || (j > n_cols - 1)) throw("out of range");    //  �������� ������ �� ��������a
	return array[i][j];
}

//---------------------------------------------------------------------------------
double &CMatrix::operator()(int i)
// i - ����� ������ ��� �������
{
	if (n_cols > 1) throw("not a vector");    //  ����� �������� ������ ������
	if (i > n_rows - 1)  throw("out of range");   //  �������� ������ �� ��������
	return array[i][0];
}
//---------------------------------------------------------------------------------
CMatrix CMatrix::operator-()
// �������� -M
{
	CMatrix Temp(n_rows, n_cols);
	for (int i = 0; i < n_rows; i++)
		for (int j = 0; j < n_cols; j++) Temp(i, j) = -array[i][j];
	return Temp;
}

//---------------------------------------------------------------------------------
CMatrix CMatrix::operator+(CMatrix& M)
// �������� M1+M2
{
	int bb = (n_rows == M.rows()) && (n_cols == M.cols());
	if (!bb) throw("different sizes");
	CMatrix Temp(*this);
	for (int i = 0; i < n_rows; i++)
		for (int j = 0; j < n_cols; j++) Temp(i, j) += M(i, j);
	return Temp;
}

//---------------------------------------------------------------------------------
CMatrix CMatrix::operator-(CMatrix& M)
// �������� M1-M2
{
	int bb = (n_rows == M.rows()) && (n_cols == M.cols());
	if (!bb) throw("different sizes");
	CMatrix Temp(*this);
	for (int i = 0; i < n_rows; i++)
		for (int j = 0; j < n_cols; j++) Temp(i, j) -= M(i, j);
	return Temp;
}
//---------------------------------------------------------------------------------
CMatrix CMatrix::operator*(CMatrix& M)
// ��������� �� ������� M
{
	double sum;
	int nn = M.rows();
	int mm = M.cols();
	CMatrix Temp(n_rows, mm);
	if (n_cols == nn)
	{
		for (int i = 0; i < n_rows; i++)
			for (int j = 0; j < mm; j++)
			{
				sum = 0;
				for (int k = 0; k < n_cols; k++) sum += (*this)(i, k)*M(k, j);
				Temp(i, j) = sum;
			}
	}
	else throw("different sizes");
	return Temp;
}

//---------------------------------------------------------------------------------
CMatrix CMatrix::operator=(const CMatrix& M)
// �������� ������������ M1=M
{
	if (this == &M) return *this;
	int nn = M.rows();
	int mm = M.cols();
	if ((n_rows == nn) && (n_cols == mm))
	{
		for (int i = 0; i < n_rows; i++)
			for (int j = 0; j < n_cols; j++) array[i][j] = M.array[i][j];
	}
	else throw("different sizes");  // ��� ������ ������������
	return *this;
}

//---------------------------------------------------------------------------------
CMatrix::CMatrix(const CMatrix &M) // ����������� �����������
{
	n_rows = M.n_rows;
	n_cols = M.n_cols;
	array = new double*[n_rows];
	for (int i = 0; i < n_rows; i++) array[i] = new double[n_cols];
	for (int i = 0; i < n_rows; i++)
		for (int j = 0; j < n_cols; j++) array[i][j] = M.array[i][j];
}

//---------------------------------------------------------------------------------
CMatrix CMatrix::Transp()
// ���������� �������,����������������� � (*this)
{
	CMatrix Temp(n_cols, n_rows);
	for (int i = 0; i < n_cols; i++)
		for (int j = 0; j < n_rows; j++) Temp(i, j) = array[j][i];
	return Temp;
}
//---------------------------------------------------------------------------------
CMatrix CMatrix::GetRow(int k)
// ���������� ������ ������� �� ������ k
{
	if (k > n_rows - 1) throw("out of range");
	CMatrix M(1, n_cols);
	for (int i = 0; i < n_cols; i++)M(0, i) = (*this)(k, i);
	return M;
}
//---------------------------------------------------------------------------------
CMatrix CMatrix::GetCol(int k)
// ���������� ������� ������� �� ������ k
{
	if (k > n_cols - 1) throw("out of range");
	CMatrix M(n_rows, 1);
	for (int i = 0; i < n_rows; i++)M(i, 0) = (*this)(i, k);
	return M;
}
//----------------------------------------------------------------------------------
double CMatrix::MaxElement()
// ������������ �������� ��������� �������
{
	double max = (*this)(0, 0);
	for (int i = 0; i < (this->rows()); i++)
		for (int j = 0; j < (this->cols()); j++) if ((*this)(i, j) > max) max = (*this)(i, j);
	return max;
}

//----------------------------------------------------------------------------------
double CMatrix::MinElement()
// ����������� �������� ��������� �������
{
	double min = (*this)(0, 0);
	for (int i = 0; i < (this->rows()); i++)
		for (int j = 0; j < (this->cols()); j++) if ((*this)(i, j) < min) min = (*this)(i, j);
	return min;
}