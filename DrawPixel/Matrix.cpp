#include "pch.h"
#include "Matrix.h"

Matrix::Matrix(const Matrix& other)
{
	mat = other.mat;
	rows = other.rows;
	cols = other.cols;
}

Matrix::Matrix(unsigned r, unsigned c)
{
	rows = r;
	cols = c;

	mat.resize(r);
	for (unsigned i = 0; i < mat.size(); i++)
	{
		mat[i].resize(c, 0);
	};
}

void Matrix::ModMatrix(int value, int ro, int co)
{
	mat[ro][co] = value;
}

Matrix& Matrix::operator=(Matrix mtx)
{
	if (&mtx == this)
		return *this;
	unsigned newRows = mtx.rows;
	unsigned newCols = mtx.cols;

	mat.resize(newRows);
	for (unsigned i = 0; i < newRows; i++)
	{
		for (unsigned j = 0; j < newCols; j++)
		{
			mat[i][j] = mtx(i, j);
		}
	}
	rows = newRows;
	cols = newCols;
	return *this;
}

Matrix Matrix::operator+ (Matrix& mtx)
{
	Matrix temp(rows, cols);
	for (unsigned i = 0; i < mat.size(); i++)
	{
		for (unsigned j = 0; j < mat[i].size(); j++)
		{
			temp.ModMatrix(mat[i][j] + mtx.operator()(i, j), i, j);
		}
	};
	return temp;
}

Matrix Matrix::operator- (Matrix& mtx)
{
	Matrix temp(rows, cols);
	for (unsigned i = 0; i < mat.size(); i++)
	{
		for (unsigned j = 0; j < mat[i].size(); j++)
		{
			temp.ModMatrix(mat[i][j] - mtx.operator()(i, j), i, j);
		}
	};
	return temp;
}

Matrix Matrix::operator* (Matrix& mtx)
{

	if (cols == mtx.rows)
	{
		Matrix temp(rows, mtx.cols);
		for (unsigned i = 0; i < rows; i++)
		{
			for (unsigned j = 0; j < mtx.cols; j++)
			{
				int total = 0;
				for (unsigned int p = 0; 0 < cols; p++)
				{
					temp.ModMatrix(total + (mat[i][p] * mtx.operator()(p, j)), i, j);
				}
			}
		}
		return temp;
	}	
	else
	{
		std::cout << "Tus matrices son de tamaños incorrectos" << std::endl;
	}
}

Matrix Matrix::transpose() 
{
	Matrix result(tempRows, tempCols);
	for (unsigned i = 0; i < tempRows; i++)
	{
		for (unsigned j = 0; j < tempCols; j++)
		{
			result(i, j) = this->mat[j][i];
		}
	}
	return result;
}

float& Matrix::operator() (const unsigned& r, const unsigned& c)
{
	return mat[r][c];
}

Matrix::~Matrix()
{
}
