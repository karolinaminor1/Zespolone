#pragma once
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double Re = 0, double Im = 0);
	Complex(const Complex& c);
	virtual ~Complex();

	Complex& operator = (const Complex&);

	Complex& operator -= ( const Complex&);
	Complex& operator += (const Complex&);

	friend const Complex operator + (const Complex&, const Complex&);
	friend const Complex operator - (const Complex&, const Complex&);

	Complex& operator *= (const Complex&);
	friend const Complex operator * (const Complex&, const Complex&);

	Complex& operator /= (const Complex&);
	friend const Complex operator / (const Complex&, const Complex&);

	friend const Complex operator - (const Complex&);  //minus unarny

	friend istream& operator >> (istream& in, Complex&);
	friend ostream& operator << (ostream& out, const Complex&);

	friend bool operator !=(const Complex&, const Complex&);
	friend bool operator ==(const Complex&, const Complex&);

	inline double Module();
	inline Complex& Coupled();

	operator double () const { return m_Re; }  //operator rzutowania
	operator int () const { return (int)m_Re; }  //operator rzutowania

	inline void setRe(double newRe);
	inline void setIm(double newIm);

	inline double getRe() const;
	inline double getIm() const;

	void SetComplex(double, double);
	void SetComplex(const Complex&);

private:
	inline double sqr() const; //re^2 + im^2 
private:

	double m_Re;
	double m_Im;

};

inline double Complex::sqr() const{
	double res;
	return res = getRe() * getRe() + getIm() * getIm();
}
