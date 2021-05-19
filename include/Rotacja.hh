#ifndef ROTACJA_HH
#define ROTACJA_HH

#include "Macierz3x3.hh"
#include <iostream>
class Rotacja
{
private:
    char os;
    double kat;

public:
    Macierz3x3 Rotuj_X(double kat);
    Macierz3x3 Roruj_Y(double kat);
    Macierz3x3 Rotuj_Z(double kat);

    Macierz3x3 Sekwencja(char os, double kat);
};

#endif