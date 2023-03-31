
#include <iostream>
#include "CanonComplex.h"
using namespace std;

int main()
{
    Complex z;
    cout << "Wprowadz Re i Im liczby zespolonej: " << endl;
    cin >> z;
    cout << "Wczytana liczba zespolona z : " << endl;
    cout << z << endl;
    

    Complex g = Complex(7, 9);
    Complex h = Complex(6, 8);
    Complex t = Complex(10, -10.9);
    cout << "Wczytana liczba zespolona t : " << endl;
    cout << t << endl;

    bool b = g != h;
    cout << b << endl;
    cout << "liczby z i t w postaci kanonicznej : " << endl;
    CanonComplex Z = z;
    CanonComplex T = t;
    cout << Z << endl;
    cout << T << endl;

  
}
