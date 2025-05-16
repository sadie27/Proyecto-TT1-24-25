//--------------------------------------------------------------------------
//
// SAT_Const: Definition of astronomical and mathematical constants
//
// Last modified:   2019/11/03   Meysam Mahooti
//
//--------------------------------------------------------------------------

// Mathematical constants

static double const pi        =3.14159265358979323846264338327950288419716939937510582;

static double const pi2       = 2*pi;                // 2pi
static double const Rad       = pi/180;              // Radians per degree
static double const Deg       = 180/pi;              // Degrees per radian
static double const Arcs      = 3600*180/pi;         // Arcseconds per radian

// General
static double const MJD_J2000 = 51544.5;             // Modified Julian Date of J2000
static double const T_B1950   = -0.500002108;        // Epoch B1950
static double const c_light   = 299792458.000000000; // Speed of light  [m/s]; DE430
static double const AU        = 149597870700.000000; // Astronomical unit [m]; DE430

// Physical parameters of the Earth, Sun and Moon

// Equatorial radius and flattening
static double const R_Earth   = 6378.1363e3;      // Earth's radius [m]; DE430
static double const f_Earth   = 1/298.257223563;  // Flattening; WGS-84
static double const R_Sun     = 696000e3;         // Sun's radius [m]; DE430
static double const R_Moon    = 1738e3;           // Moon's radius [m]; DE430

// Earth rotation (derivative of GMST at J2000; differs from inertial period by precession)
static double const omega_Earth = 15.04106717866910/3600*Rad;   // [rad/s]; WGS-84

// Gravitational coefficients
static double const GM_Earth    = 398600.435436e9;                  // [m^3/s^2]; DE430
static double const GM_Sun      = 132712440041.939400e9;            // [m^3/s^2]; DE430
static double const GM_Moon     = GM_Earth/81.30056907419062; // [m^3/s^2]; DE430
static double const GM_Mercury  = 22031.780000e9;                   // [m^3/s^2]; DE430
static double const GM_Venus    = 324858.592000e9;                  // [m^3/s^2]; DE430
static double const GM_Mars     = 42828.375214e9;                   // [m^3/s^2]; DE430
static double const GM_Jupiter  = 126712764.800000e9;               // [m^3/s^2]; DE430
static double const GM_Saturn   = 37940585.200000e9;                // [m^3/s^2]; DE430
static double const GM_Uranus   = 5794548.600000e9;                 // [m^3/s^2]; DE430
static double const GM_Neptune  = 6836527.100580e9;                 // [m^3/s^2]; DE430
static double const GM_Pluto    = 977.0000000000009e9;              // [m^3/s^2]; DE430

// Solar radiation pressure at 1 AU 
static double const P_Sol       = 1367/c_light; // [N/m^2] (~1367 W/m^2); IERS 96

