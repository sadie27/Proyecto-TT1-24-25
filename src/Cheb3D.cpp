//--------------------------------------------------------------------------
//
// Chebyshev approximation of 3-dimensional vectors
//
// Inputs:
//     N       Number of coefficients
//     Ta      Begin interval
//     Tb      End interval
//     Cx      Coefficients of Chebyshev polyomial (x-coordinate)
//     Cy      Coefficients of Chebyshev polyomial (y-coordinate)
//     Cz      Coefficients of Chebyshev polyomial (z-coordinate)
//
// Last modified:   2018/01/27   M. Mahooti
// 
//--------------------------------------------------------------------------
function ChebApp = Cheb3D(double t,double N,double Ta,double Tb,vector Cx,vector Cy,vector Cz)

// Check validity
if ( (t<Ta) || (Tb<t) ){
    throw std::invalid_argument("t<Ta and Tb<t");
}

// Clenshaw algorithm
double tau = (2*t-Ta-Tb)/(Tb-Ta);  

vector f1 = zeros(1,3);
vector f2 = zeros(1,3);

 for (int i=N; 2<=N; i--){
    old_f1 = f1;
    f1 = 2*tau*f1-f2+[Cx(i),Cy(i),Cz(i)];
    f2 = old_f1;
 }

ChebApp = tau*f1-f2+[Cx(1),Cy(1),Cz(1)];

