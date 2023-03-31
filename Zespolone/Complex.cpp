#include "Complex.h"

//---------------------------------------------- konstruktory ----------------------------------------------

Complex::Complex(const Complex& z) {
	m_Re = 0;
	m_Im = 0;
	*this = z;
}

Complex::Complex(double newRe, double newIm) {
	m_Re = newRe;
	m_Im = newIm;
}

Complex::~Complex() {
	
}

Complex& Complex:: operator = ( const Complex& z ) {
	SetComplex( z.getRe(), z.getIm() );
	return *this;
}

//------------------------------------------------ operatory ------------------------------------------------

Complex& Complex::operator += ( const Complex& z ) {
	m_Re += z.getRe();
	m_Im += z.getIm();
	return *this;
}

Complex& Complex::operator -= ( const Complex& z ) {
	m_Re -= z.getRe();
	m_Im -= z.getIm();
	return *this;
}

const Complex operator + ( const Complex& z1, const Complex& z2 ) {
	Complex res(z1);
	return res += z2;
}

const Complex operator - ( const Complex& z1, const Complex& z2 ) {
	Complex res( z1 );
	return res -= z2;
}

Complex& Complex::operator *= ( const Complex& z ) {
	double re = m_Re;
	double im = m_Im;

	m_Re = re * z.getRe() - im * z.getIm();
	m_Im = re * z.getIm() + im * z.getRe();
	return *this;
}

const Complex operator * ( const Complex& z1, const Complex& z2 ) {
	Complex res(z1);
	return res *= z2;
 }

const Complex operator - ( const Complex& z ) {
	Complex res( z );
	res.m_Re *= ( double )(-1);
	res.m_Im *= ( double )(-1);
	return res;
}

Complex& Complex::operator /= ( const Complex& z ) {
	double re = m_Re;
	double im = m_Im;

	m_Re = ( re * z.getRe() + im * z.getIm() ) / z.sqr();
	m_Im = ( im * z.getRe() + re * z.getIm() ) / z.sqr();
	return *this;
}

const Complex operator / ( const Complex& z1, const Complex& z2 ) {
	Complex res(z1);
	return res /= z2;
}

bool operator != ( const Complex& z1, const Complex& z2 ) {
	if( z1.getRe() != z2.getRe() || z1.getIm() != z2.getIm() ) return true;
	return false;
}

bool operator == ( const Complex& z1, const Complex& z2 ) {
	if( z1 != z2 ) return false;
		return true;
}

//------------------------------------------------- metody --------------------------------------------------

inline double Complex::Module() {
	return sqrt( sqr() );
}

inline Complex& Complex::Coupled() {
	m_Im *= ( double )(-1);
	return *this;
}

//-------------------------------------------- settery i gettery --------------------------------------------

inline double Complex::getRe() const {
	return m_Re;
}

inline double Complex::getIm() const {
	return m_Im;
}

inline void Complex::setRe( double newRe ) {
	m_Re = newRe;
}

inline void Complex::setIm( double newIm ) {
	m_Im = newIm;
}

void Complex::SetComplex( double newRe, double newIm ) {
	setRe( newRe );
	setIm( newIm );
}

void Complex::SetComplex( const Complex& z ) {
	SetComplex( z.getRe(), z.getIm() );
}

//-------------------------------------------- operatory we/wy --------------------------------------------

istream& operator >> ( istream& in, Complex& z ) {
	double x;

	in >> x; z.setRe(x);
	in >> x; z.setIm(x);
	return in;
 }

ostream& operator << ( ostream& out, const Complex& z ) {
	out << "Re: " << z.getRe() << " " << "Im: " << z.getIm();
	return out;

 }