#ifndef _IERS_
#define _IERS_
#include "../include/matrix.hpp"
#include "../include/SAR_ hpp"
#include<cmath>

tuple<double, double, double, double, double, double, double, double, double>IERS(const Matrix& eop, double Mjd_UTC, char interp);

#endif