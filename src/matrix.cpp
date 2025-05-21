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
Matrix::Matrix(const int n) {
    if (n <= 0) {
        cout << "Matrix create: error in n\n";
        exit(EXIT_FAILURE);
    }

    this->n_row = n;
    this->n_column = n;
    this->data = (double **) malloc(n*sizeof(double *));

    if (this->data == NULL) {
        cout << "Matrix create: error in data\n";
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < n_row; i++) {
        this->data[i] = (double *) malloc(n*sizeof(double));
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
Matrix& eye(const int n) {
    if (n <= 0) {
        cout << "eye: error in dimension n\n";
        exit(EXIT_FAILURE);
    }

    Matrix *m_aux = new Matrix(n, n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            (*m_aux)(i,j) = (i == j) ? 1.0 : 0.0;
        }
    }

    return *m_aux;
}
Matrix& transpose(Matrix &m) {
    Matrix *m_aux = new Matrix(m.n_column, m.n_row);  // Dimensiones invertidas

    for(int i = 1; i <= m.n_row; i++) {
        for(int j = 1; j <= m.n_column; j++) {
            (*m_aux)(j, i) = m(i, j);  // Intercambia filas por columnas
        }
    }

    return *m_aux;
}
Matrix& inv(Matrix &m) {
    if (m.n_row != m.n_column) {
        cout << "Matrix inversion: matrix must be square\n";
        exit(EXIT_FAILURE);
    }

    int n = m.n_row;
    Matrix *inv = &eye(n);  // Usamos la función eye() para la matriz identidad
    Matrix temp = m;        // Copia de trabajo de la matriz original

    // Eliminación gaussiana
    for (int col = 1; col <= n; col++) {
        // Pivoteo parcial
        double max_val = abs(temp(col, col));
        int max_row = col;
        for (int row = col + 1; row <= n; row++) {
            if (abs(temp(row, col)) > max_val) {
                max_val = abs(temp(row, col));
                max_row = row;
            }
        }

        // Intercambiar filas si es necesario
        if (max_row != col) {
            for (int j = 1; j <= n; j++) {
                swap(temp(col, j), temp(max_row, j));
                swap((*inv)(col, j), (*inv)(max_row, j));
            }
        }

        // Verificar si la matriz es singular
        if (temp(col, col) == 0.0) {
            cout << "Matrix inversion: matrix is singular\n";
            exit(EXIT_FAILURE);
        }

        // Normalizar la fila del pivote
        double pivot = temp(col, col);
        for (int j = 1; j <= n; j++) {
            temp(col, j) /= pivot;
            (*inv)(col, j) /= pivot;
        }

        // Eliminación hacia adelante
        for (int row = 1; row <= n; row++) {
            if (row != col && temp(row, col) != 0.0) {
                double factor = temp(row, col);
                for (int j = 1; j <= n; j++) {
                    temp(row, j) -= temp(col, j) * factor;
                    (*inv)(row, j) -= (*inv)(col, j) * factor;
                }
            }
        }
    }

    return *inv;
}

Matrix& Matrix::operator + (double entrada) {
    Matrix *m_aux = new Matrix(this->n_row, this->n_column);

    for(int i = 1; i <= this->n_row; i++) {
        for(int j = 1; j <= this->n_column; j++) {
            (*m_aux)(i,j) = (*this)(i,j) + entrada;
        }
    }

    return *m_aux;
}

Matrix& Matrix::operator - (double entrada) {
    Matrix *m_aux = new Matrix(this->n_row, this->n_column);

    for(int i = 1; i <= this->n_row; i++) {
        for(int j = 1; j <= this->n_column; j++) {
            (*m_aux)(i,j) = (*this)(i,j) - entrada;
        }
    }

    return *m_aux;
}

Matrix& Matrix::operator * (double entrada) {
    Matrix *m_aux = new Matrix(this->n_row, this->n_column);

    for(int i = 1; i <= this->n_row; i++) {
        for(int j = 1; j <= this->n_column; j++) {
            (*m_aux)(i,j) = (*this)(i,j) * entrada;
        }
    }

    return *m_aux;
}

Matrix& Matrix::operator / (double entrada) {
    if (entrada == 0.0) {
        cout << "Matrix division: division by zero\n";
        exit(EXIT_FAILURE);
    }

    Matrix *m_aux = new Matrix(this->n_row, this->n_column);

    for(int i = 1; i <= this->n_row; i++) {
        for(int j = 1; j <= this->n_column; j++) {
            (*m_aux)(i,j) = (*this)(i,j) / entrada;
        }
    }

    return *m_aux;
}