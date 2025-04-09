#include "..\include\matrix.h"
#include "../include/R_x.hpp"
#include "../include/R_y.hpp"
#include "../include/R_z.hpp"

#include <iostream>

using namespace std;

int main() {
	
	Matrix aux1 = R_x(3);
	cout<<"aux1\n"<< aux1<<"\n";
	
	Matrix aux2 = R_y(3);
	cout<<"aux2\n"<< aux2<<"\n";
	
	Matrix aux3 = R_z(3);
	cout<<"aux3\n"<< aux3<<"\n";
	
	
	Matrix v(3);
	v(2)=5;
	cout<<v;
	
    Matrix M1(3, 2);
	M1(1,1) = 5;
	
    Matrix M2(3, 2);
	M2(1,1) = -3;
	
    Matrix M3 = M1 - M2;

    cout << "M1\n" << M1 << "\n";
    cout << "M2\n" << M2 << "\n";
    cout << "M3\n" << M3 << "\n";
	
	cout << M1(1,1) << "\n";

    return 0;
}