#include "CanonComplex.h"

CanonComplex::CanonComplex(const Complex& z) : Complex(z)
{
	
}

ostream& operator << (ostream& out , const CanonComplex& z) {
	if(z.getIm() < 0) {
		out << z.getRe() << z.getIm() << "i" << endl;
		return out;
	}
	 
	out << z.getRe() << "+" << z.getIm() << "i" << endl;
	return out;
}