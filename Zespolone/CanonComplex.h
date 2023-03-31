#pragma once
#include "Complex.h"

class CanonComplex : public Complex
{
public:
	CanonComplex(const Complex&);
	friend ostream& operator << (ostream&, const CanonComplex&);

};

