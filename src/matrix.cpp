#include "..\include\matrix.h"

Matrix::Matrix(const int n_row, const int n_column) {
    if (n_row <= 0 || n_column <= 0) {
		cout << "Matrix create: error in n_row/n_column\n";
        exit(EXIT_FAILURE);
	}
	
	this->n_row = n_row;
	this->n_column = n_column;
	this->data = (double **) malloc(n_row*sizeof(double *));
    if (this->data == NULL) {
		cout << "Matrix create: error in data\n";
        exit(EXIT_FAILURE);
	}
	
	for(int i = 0; i < n_row; i++) {
		this->data[i] = (double *) malloc(n_column*sizeof(double));
	}
}

double& Matrix::operator () (const int row, const int column) {
	if (row <= 0 || row > this->n_row || column <= 0 || column > this->n_column) {
		cout << "Matrix get: error in row/column\n";
        exit(EXIT_FAILURE);
	}
	
	return this->data[row - 1][column - 1];
}

Matrix& Matrix::operator + (Matrix &m) {
	if (this->n_row != m.n_row || this->n_column != m.n_column) {
		cout << "Matrix sum: error in n_row/n_column\n";
        exit(EXIT_FAILURE);
	}
	
	Matrix *m_aux = new Matrix(this->n_row, this->n_column);
	
    for(int i = 1; i <= this->n_row; i++) {
        for(int j = 1; j <= this->n_column; j++) {
			(*m_aux)(i,j) = (*this)(i,j) + m(i,j);
		}
	}
	
	return *m_aux;
}

Matrix& Matrix::operator - (Matrix &m) {
	if (this->n_row != m.n_row || this->n_column != m.n_column) {
		cout << "Matrix sub: error in n_row/n_column\n";
        exit(EXIT_FAILURE);
	}
	
	Matrix *m_aux = new Matrix(this->n_row, this->n_column);
	
    for(int i = 1; i <= this->n_row; i++) {
        for(int j = 1; j <= this->n_column; j++) {
			(*m_aux)(i,j) = (*this)(i,j) - m(i,j);
		}
	}
	
	return *m_aux;
}
Matrix& Matrix::operator * (Matrix &m) {
    if (this->n_column != m.n_row) {
        cout << "Matrix multiplication: error in dimensions\n";
        exit(EXIT_FAILURE);
    }

    Matrix *m_aux = new Matrix(this->n_row, m.n_column);

    for(int i = 1; i <= this->n_row; i++) {
        for(int j = 1; j <= m.n_column; j++) {
            double sum = 0;
            for(int k = 1; k <= this->n_column; k++) {
                sum += (*this)(i, k) * m(k, j);
            }
            (*m_aux)(i, j) = sum;
        }
    }

    return *m_aux;
}
Matrix& Matrix::operator / (Matrix &m) {
    if (this->n_row != m.n_row || this->n_column != m.n_column) {
        cout << "Matrix division: error in dimensions\n";
        exit(EXIT_FAILURE);
    }

    Matrix *m_aux = new Matrix(this->n_row, this->n_column);

    for(int i = 1; i <= this->n_row; i++) {
        for(int j = 1; j <= this->n_column; j++) {
            if (m(i, j) == 0) {
                cout << "Matrix division: division by zero\n";
                exit(EXIT_FAILURE);
            }
            (*m_aux)(i, j) = (*this)(i, j) / m(i, j);
        }
    }

    return *m_aux;
}
Matrix& Matrix::operator = (const Matrix &m) {
    if (this == &m) {return *this;}
    this->n_row = m.n_row;
    this->n_column = m.n_column;
    this->data = (double **)malloc(m.n_row * sizeof(double *));
    if (this->data == NULL) {
        cout << "Matrix assignment: error in data allocation\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < m.n_row; i++) {
        this->data[i] = (double *)malloc(m.n_column * sizeof(double));
        if (this->data[i] == NULL) {
            cout << "Matrix assignment: error in row allocation\n";
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < m.n_row; i++) {
        for (int j = 0; j < m.n_column; j++) {
            this->data[i][j] = m.data[i][j];
        }
    }

    return *this;
}
ostream& operator << (ostream &o, Matrix &m) {
	for (int i = 1; i <= m.n_row; i++) {
        for (int j = 1; j <= m.n_column; j++)
			printf("%5.20lf ", m(i,j));
        o << "\n";
    }
	
    return o;
}

Matrix& zeros(const int n_row, const int n_column) {
	Matrix *m_aux = new Matrix(n_row, n_column);
	
	for(int i = 1; i <= n_row; i++) {
		for(int j = 1; j <= n_column; j++) {
			(*m_aux)(i,j) = 0;
		}
	}
	
	return (*m_aux);
}