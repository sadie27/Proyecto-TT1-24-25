#include "..\include\matrix.h"
#include <cstdio>
#include <cmath>

int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)


//Test de Matrix
int m_equals(Matrix A, Matrix B, double p) {
	if (A.n_row != B.n_row || A.n_column != B.n_column)
		return 0;
	else
		for(int i = 1; i <= A.n_row; i++)
			for(int j = 1; j <= A.n_column; j++)
				if(fabs(A(i,j)-B(i,j)) > p) {
					printf("%2.20lf %2.20lf\n",A(i,j),B(i,j));
					return 0;
				}
	
	return 1;
}

int m_sum_01() {
    int f = 3;
    int c = 4;
	
	Matrix A(f, c);
	A(1,1) = 0; A(1,2) =  2; A(1,3) = 8; A(1,4) = 0;
	A(2,1) = 1; A(2,2) = -1; A(2,3) = 0; A(2,4) = 0;
	A(3,1) = 0; A(3,2) =  1; A(3,3) = 0; A(3,4) = 5;
	
	Matrix B(f, c);
	B(1,1) = 2; B(1,2) =  0; B(1,3) = 0; B(1,4) = 0;
	B(2,1) = 7; B(2,2) = -2; B(2,3) = 1; B(2,4) = 0;
	B(3,1) = 0; B(3,2) = -3; B(3,3) = 0; B(3,4) = 2;
	
	Matrix C(f, c);
	C(1,1) = 2; C(1,2) =  2; C(1,3) = 8; C(1,4) = 0;
	C(2,1) = 8; C(2,2) = -3; C(2,3) = 1; C(2,4) = 0;
	C(3,1) = 0; C(3,2) = -2; C(3,3) = 0; C(3,4) = 7;
	
	Matrix R = A + B;
    
    _assert(m_equals(C, R, 1e-10));
    
    return 0;
}

int m_sub_01() {
    int f = 3;
    int c = 4;
	
	Matrix A(f, c);
	A(1,1) = 0; A(1,2) = 2; A(1,3) = 8; A(1,4) = 0;
	A(2,1) = 1; A(2,2) = -1; A(2,3) = 0; A(2,4) = 0;
	A(3,1) = 0; A(3,2) = 1; A(3,3) = 0; A(3,4) = 5;
	
	Matrix B(f, c);
	B(1,1) = 2; B(1,2) = 0; B(1,3) = 0; B(1,4) = 0;
	B(2,1) = 7; B(2,2) = -2; B(2,3) = 1; B(2,4) = 0;
	B(3,1) = 0; B(3,2) = -3; B(3,3) = 0; B(3,4) = 2;
	
	Matrix C(f, c);
	C(1,1) = -2; C(1,2) = 2; C(1,3) = 8; C(1,4) = 0;
	C(2,1) = -6; C(2,2) = 1; C(2,3) = -1; C(2,4) = 0;
	C(3,1) = 0; C(3,2) = 4; C(3,3) = 0; C(3,4) = 3;
	
	Matrix R = A - B;
    
    _assert(m_equals(C, R, 1e-10));
    
    return 0;
}
int m_mult_01() {
    int f1 = 2, c1 = 3;
    int f2 = 3, c2 = 2;

    Matrix A(f1, c1);
    A(1,1) = 1; A(1,2) = 2; A(1,3) = 3;
    A(2,1) = 4; A(2,2) = 5; A(2,3) = 6;

    Matrix B(f2, c2);
    B(1,1) = 7; B(1,2) = 8;
    B(2,1) = 9; B(2,2) = 10;
    B(3,1) = 11; B(3,2) = 12;

    Matrix C(f1, c2);
    C(1,1) = 58;  C(1,2) = 64;
    C(2,1) = 139; C(2,2) = 154;

    Matrix R = A * B;

    _assert(m_equals(C, R, 1e-10));

    return 0;
}
int m_div_01() {
    int f = 2, c = 2;

    Matrix A(f, c);
    A(1,1) = 4; A(1,2) = 6;
    A(2,1) = 8; A(2,2) = 10;

    Matrix B(f, c);
    B(1,1) = 2; B(1,2) = 3;
    B(2,1) = 4; B(2,2) = 5;

    Matrix C(f, c);
    C(1,1) = 2; C(1,2) = 2;
    C(2,1) = 2; C(2,2) = 2;

    Matrix R = A / B;

    _assert(m_equals(C, R, 1e-10));

    return 0;
}
int m_zeros_01() {
    int f = 3;
    int c = 4;
	
	Matrix A(f, c);
	A(1,1) = 0; A(1,2) = 0; A(1,3) = 0; A(1,4) = 0;
	A(2,1) = 0; A(2,2) = 0; A(2,3) = 0; A(2,4) = 0;
	A(3,1) = 0; A(3,2) = 0; A(3,3) = 0; A(3,4) = 0;
	
	Matrix B = zeros(3, 4);
    
    _assert(m_equals(A, B, 1e-10));
    
    return 0;
}
int m_assign_01() {
    int f = 2, c = 2; // Dimensions of matrices (2x2)

    Matrix A(f, c);
    A(1,1) = 1; A(1,2) = 2;
    A(2,1) = 3; A(2,2) = 4;

    Matrix B(f, c);
    B = A; // Assignment

    Matrix C(f, c);
    C(1,1) = 1; C(1,2) = 2;
    C(2,1) = 3; C(2,2) = 4;

    _assert(m_equals(C, B, 1e-10));

    return 0;
}
int m_assign_self_01() {
    int f = 2, c = 2;

    Matrix A(f, c);
    A(1,1) = 1; A(1,2) = 2;
    A(2,1) = 3; A(2,2) = 4;

    A = A; // Self-assignment

    Matrix C(f, c);
    C(1,1) = 1; C(1,2) = 2;
    C(2,1) = 3; C(2,2) = 4;

    _assert(m_equals(C, A, 1e-10));

    return 0;
}

//Tests de la 1era Iteración

int i1_R_x_01(){
	
	Matrix B= R_x(4);
	Matrix A(3,3);
	A(1,1) = 1; A(1,2) =  0; 					A(1,3) = 0; 
	A(2,1) = 0; A(2,2) = -0.653643620863612; 	A(2,3) = -0.756802495307928; 
	A(3,1) = 0; A(3,2) =  0.756802495307928; 	A(3,3) = -0.653643620863612;
	
	_assert(m_equals(A, B, 1e-10));
	
}
int i1_R_y_01(){
	
	Matrix B= R_y(4);
	Matrix A(3,3);
	A(1,1) = -0.653643620863612; 	A(1,2) = 0; A(1,3) = 0.756802495307928; 
	A(2,1) = 0; 					A(2,2) = 1; A(2,3) = 0; 
	A(3,1) =  -0.756802495307928; 	A(3,2) = 0; A(3,3) = -0.653643620863612;
	
	_assert(m_equals(A, B, 1e-10));
	
}
int i1_R_z_01(){
	
	Matrix B= R_z(4);
	Matrix A(3,3);
	A(1,1) = -0.653643620863612; 	A(1,2) = -0.756802495307928 ; 	A(1,3) = 0; 
	A(2,1) = 0.756802495307928; 	A(2,2) = -0.653643620863612; 	A(2,3) = 0; 
	A(3,1) = 0; 					A(3,2) = 0; 					A(3,3) = 1;
	
	_assert(m_equals(A, B, 1e-10));
	
}
int m_eye_01() {
    int n = 3;

    Matrix A(n, n);
    A(1,1) = 1; A(1,2) = 0; A(1,3) = 0;
    A(2,1) = 0; A(2,2) = 1; A(2,3) = 0;
    A(3,1) = 0; A(3,2) = 0; A(3,3) = 1;

    Matrix B = eye(n);

    _assert(m_equals(A, B, 1e-10));

    return 0;
}
int m_transpose_01() {
    int f = 2, c = 3;

    Matrix A(f, c);
    A(1,1) = 1; A(1,2) = 2; A(1,3) = 3;
    A(2,1) = 4; A(2,2) = 5; A(2,3) = 6;

    Matrix B(c, f);
    B(1,1) = 1; B(1,2) = 4;
    B(2,1) = 2; B(2,2) = 5;
    B(3,1) = 3; B(3,2) = 6;

    Matrix R = transpose(A);

    _assert(m_equals(B, R, 1e-10));

    return 0;
}
int m_inv_01() {
    int n = 3;

    Matrix A(n, n);
    A(1,1) = 1; A(1,2) = 2; A(1,3) = 3;
    A(2,1) = 0; A(2,2) = 1; A(2,3) = 4;
    A(3,1) = 5; A(3,2) = 6; A(3,3) = 0;

    Matrix B(n, n);
    B(1,1) = -24; B(1,2) = 18; B(1,3) = 5;
    B(2,1) = 20;  B(2,2) = -15; B(2,3) = -4;
    B(3,1) = -5;  B(3,2) = 4;   B(3,3) = 1;

    Matrix R = inv(A);

    _assert(m_equals(B, R, 1e-10));

    return 0;
}

// Añadir estas pruebas a la función all_tests()
int all_tests()
{
    // Tests existentes...
    _verify(m_sum_01);
    _verify(m_sub_01);
    _verify(m_zeros_01);
    _verify(m_mult_01);
    _verify(m_div_01);
    _verify(m_assign_01);
    _verify(m_assign_self_01);

    _verify(i1_R_x_01);
    _verify(i1_R_y_01);
    _verify(i1_R_z_01);

    _verify(m_eye_01);
    _verify(m_transpose_01);
    _verify(m_inv_01);


    return 0;
}


int main()
{
    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
