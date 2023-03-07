#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class complex
{
public:
	double Re, Im;
	complex(double re = 0, double im = 0) {
		Re = re;
		Im = im;
	}
	complex operator +(const complex& c)const
	{
		/*cout << Re << Im << c.Re << c.Im << "  test" << endl;*/
		return complex(Re + c.Re, Im + c.Im);
	}

	complex operator -(const complex& c)const
	{
		return complex(Re - c.Re, Im - c.Im);
	}

	complex operator *(const complex& c)const
	{
		return complex(Re * c.Re - Im * c.Im, Re * c.Im + c.Re * Im);
	}

	complex operator /(const complex& c)const
	{
		return complex((Re * c.Re + Im * c.Im) / (c.Re * c.Re + c.Im * c.Im), (-Re * c.Re + Im * Re) / (c.Re * c.Re + c.Im * c.Im));
	}

	complex Conjugate() {
		if (Im != 0) {
			complex a1(Re, -Im);
			return a1;
		}
		else {
			complex a1(Re, Im);
			return a1;
		}
	}
	double Mod() {
		return sqrt(Re * Re + Im * Im);
	}
	double Arg() {
		if (Mod() == 0) {
			return 0;
		}
		else if (Re > 0) {
			return atan(Im / Re);
		}
		else if (Re < 0) {
			if (Im >= 0) {
				return acos(-1) + atan(Im / Re);
			}
			else if (Im < 0) {
				return -acos(-1) - atan(Im / Re);
			}
		}
		else {
			if (Im > 0) {
				return acos(0);
			}
			else if (Im < 0) {
				return -acos(0);
			}
		}
	}
	double get_Re() {
		return Re;
	}
	double get_Im() {
		return Im;
	}
};

inline ostream& operator << (ostream& o, const complex& c)
{
	o << '(' << c.Re << ", " << c.Im << ')';
	return o;
}
