#include "../include/IERS.hpp"
//--------------------------------------------------------------------------
//
// IERS: Management of IERS time and polar motion data
//  
// Last modified:   2018/02/01   M. Mahooti
// 
//--------------------------------------------------------------------------

tuple<double, double, double, double, double, double, double, double, double>IERS(const Matrix& eop, double Mjd_UTC, char interp){ 
	
	if (nargin == 2){
		interp = 'n';
		}
	
	if (interp == 'l') {
        if (i + 1 >= static_cast<int>(eop[0].size())) {
            throw runtime_error("No hay datos suficientes para interpolación lineal");
        }

        double mfme = 1440.0 * (Mjd_UTC - floor(Mjd_UTC));
        double fixf = mfme / 1440.0;

        // linear interpolation
		double mjd = floor(Mjd_UTC);
        double x_pole  = eop[4][i] + (eop[4][i + 1] - eop[4][i]) * fixf;
        double y_pole  = eop[5][i] + (eop[5][i + 1] - eop[5][i]) * fixf;
        double UT1_UTC = eop[6][i] + (eop[6][i + 1] - eop[6][i]) * fixf;
        double LOD     = eop[7][i] + (eop[7][i + 1] - eop[7][i]) * fixf;
        double dpsi    = eop[8][i] + (eop[8][i + 1] - eop[8][i]) * fixf;
        double deps    = eop[9][i] + (eop[9][i + 1] - eop[9][i]) * fixf;
        double dx_pole = eop[10][i] + (eop[10][i + 1] - eop[10][i]) * fixf;
        double dy_pole = eop[11][i] + (eop[11][i + 1] - eop[11][i]) * fixf;
        double TAI_UTC = eop[12][i];

    } else if (interp == 'n') {
        x_pole  = eop[4][i];
        y_pole  = eop[5][i];
        UT1_UTC = eop[6][i];
        LOD     = eop[7][i];
        dpsi    = eop[8][i];
        deps    = eop[9][i];
        dx_pole = eop[10][i];
        dy_pole = eop[11][i];
        TAI_UTC = eop[12][i];

    }

    // Conversión de segundos de arco a radianes donde corresponde
    x_pole  /= Arcs;
    y_pole  /= Arcs;
    dpsi    /= Arcs;
    deps    /= Arcs;
    dx_pole /= Arcs;
    dy_pole /= Arcs;

    return tie(x_pole, y_pole, UT1_UTC, LOD, dpsi, deps, dx_pole, dy_pole, TAI_UTC);
}