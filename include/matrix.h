#ifndef _MATRIX_
#define _MATRIX_

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

class Matrix {
public:
    int n_row, n_column;
	double **data;

    // Parameterized constructor
    Matrix(const int n_row, const int n_column);
    Matrix(const int n);
	// Member operators
	double& operator () (const int row, const int column);
	Matrix& operator + (Matrix &m);
	Matrix& operator - (Matrix &m);
    Matrix& operator * (Matrix &m);
    Matrix& operator / (Matrix &m);
    Matrix& operator= (const Matrix &m);
    Matrix& Matrix::operator + (double entrada)
    Matrix& Matrix::operator - (double entrada)
    Matrix& Matrix::operator * (double entrada)
    Matrix& Matrix::operator / (double entrada)


    // Non-member operators
	friend ostream& operator << (ostream &o, Matrix &m);
};

// Operator overloading
ostream& operator << (ostream &o, Matrix &m);

// Methods
Matrix& zeros(const int n_row, const int n_column);
Matrix& eye(const int n);
Matrix& transpose(Matrix &m);
Matrix& inv(Matrix &m);

#endif