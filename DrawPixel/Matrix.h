#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "Vector.h"
#include <iostream>


class Matrix
{
private:
	std::vector <std::vector<float>> mat;
	unsigned rows;
	unsigned cols;
	unsigned tempRows;
	unsigned tempCols;

public:
	Matrix(const Matrix& other);
	Matrix(unsigned r, unsigned c);

	void ModMatrix(float value, int rows, int cols);
	//Matrix(Matrix&);

	//Matrix
	Matrix& operator= (Matrix);
	Matrix operator+ (Matrix&);
	Matrix operator- (Matrix&);
	Matrix operator* (Matrix&);
	//Matrix operator* (Matrix&);
	
	//Vector
	//Vector operator* (Vector&);

	Matrix transpose();

	float& operator() (const unsigned&, const unsigned&);

	virtual ~Matrix();
};

#endif // !MATRIX_H
