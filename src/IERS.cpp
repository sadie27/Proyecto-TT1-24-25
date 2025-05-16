#include "../include/SAR_ hpp"
#include "../include/IERS.hpp"
//--------------------------------------------------------------------------
//
// IERS: Management of IERS time and polar motion data
//  
// Last modified:   2018/02/01   M. Mahooti
// 
//--------------------------------------------------------------------------
tuple<>IERS( eop, Mjd_UTC, interp){

	if (nargin == 2){
	   interp = 'n';
	}

	if (interp =='l'){
		// linear interpolation
		double mjd = (floor(Mjd_UTC));
		int i = find(mjd==eop(4,:),1,'first');
		preeop = eop(:,i);
		nexteop = eop(:,i+1);
		
		mfme = 1440*(Mjd_UTC-floor(Mjd_UTC));
		fixf = mfme/1440;
		// Setting of IERS Earth rotation parameters
		// (UT1-UTC [s], TAI-UTC [s], x ["], y ["])
		double x_pole  = preeop(5)+(nexteop(5)-preeop(5))*fixf;
		double y_pole  = preeop(6)+(nexteop(6)-preeop(6))*fixf;
		double UT1_UTC = preeop(7)+(nexteop(7)-preeop(7))*fixf;
		double LOD     = preeop(8)+(nexteop(8)-preeop(8))*fixf;
		double dpsi    = preeop(9)+(nexteop(9)-preeop(9))*fixf;
		double deps    = preeop(10)+(nexteop(10)-preeop(10))*fixf;
		double dx_pole = preeop(11)+(nexteop(11)-preeop(11))*fixf;
		double dy_pole = preeop(12)+(nexteop(12)-preeop(12))*fixf;
		double TAI_UTC = preeop(13);
		
		x_pole  = x_pole/ Arcs;  // Pole coordinate [rad]
		y_pole  = y_pole/ Arcs;  // Pole coordinate [rad]
		dpsi    = dpsi/ Arcs;
		deps    = deps/ Arcs;
		dx_pole = dx_pole/ Arcs; // Pole coordinate [rad]
		dy_pole = dy_pole/ Arcs; // Pole coordinate [rad]
	}
	else if (interp =='n'){    
		mjd = (floor(Mjd_UTC));
		i = find(mjd==eop(4,:),1,'first');
		eop = eop(:,i);
		// Setting of IERS Earth rotation parameters
		// (UT1-UTC [s], TAI-UTC [s], x ["], y ["])
		x_pole  = eop(5)/ Arcs;  // Pole coordinate [rad]
		y_pole  = eop(6)/ Arcs;  // Pole coordinate [rad]
		UT1_UTC = eop(7);             // UT1-UTC time difference [s]
		LOD     = eop(8);             // Length of day [s]
		dpsi    = eop(9)/ Arcs;
		deps    = eop(10)/ Arcs;
		dx_pole = eop(11)/ Arcs; // Pole coordinate [rad]
		dy_pole = eop(12)/ Arcs; // Pole coordinate [rad]
	TAI_UTC = eop(13);            // TAI-UTC time difference [s]
	}
	return tie(x_pole,y_pole,UT1_UTC,LOD,dpsi,deps,dx_pole,dy_pole,TAI_UTC)
}
