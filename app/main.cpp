// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "../inc/lacze_do_gnuplota.hh"

using namespace std;
#define DL_BOKU 50
#define SZ_BOKU 60
#define WYSOKOSC_BOKU 30
/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

void PrzykladZapisuWspolrzednychDoStrumienia(ostream &StrmWy,
                                             Cuboid cub)
{
       //---------------------------------------------------------------
       // To tylko przyklad !!!
       // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych
       // zmiennych do reprezentowania wspolrzednych!
       //

       StrmWy << setw(16) << fixed << setprecision(10) << cub[0]
              << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[1]
              << endl;

       StrmWy << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[2]
              << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[3]
              << endl;

       StrmWy << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[4]
              << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[5]
              << endl;

       StrmWy << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[6]
              << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[7]
              << endl;

       StrmWy << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[0]
              << endl;

       StrmWy << setw(16) << fixed << setprecision(10) << cub[1]
              << endl;
       // Jeszcze raz zapisujemy pierwsze dwa wierzcholki,
       // aby gnuplot narysowal zamkniętą powierzchnie.
}

bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Cuboid cub)
{
       std::ofstream StrmPlikowy;

       StrmPlikowy.open(sNazwaPliku);
       if (!StrmPlikowy.is_open())
       {
              std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                        << ":(  nie powiodla sie." << std::endl;
              return false;
       }

       PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, cub);
       StrmPlikowy.close();
       return !StrmPlikowy.fail();
}

int main()
{
       PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji
                                   // rysunku prostokata

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       Lacze.DodajNazwePliku("prostopadloscian.dat", PzG::RR_Ciagly, 2);
       //
       //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
       //      których połowa długości boku wynosi 2.
       //
       //Lacze.DodajNazwePliku("prostopadloscian.dat", PzG::RR_Punktowy, 2);
       //
       //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy tylko x,y.
       //
       // Ustawienie zakresow poszczegolnych osi
       Lacze.UstawZakresY(-155, 155);
       Lacze.UstawZakresX(-155, 155);
       Lacze.UstawZakresZ(-155, 155);

       Lacze.ZmienTrybRys(PzG::TR_3D);

       double We[] = {10, 20, 30};
       Vector3D vector(We);
       Cuboid side(vector, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);
       char option;
       char wymiar;
      // int ile; //ile razy ma sie powturzyc obrut
       double angle;
       side.length();
       std::cout << std::endl;
       std::cout << "o - obrot prostokata o zadany kat" << std::endl;
       std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
       std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
       std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
       std::cout << "w - wyswietlanie wspolrzednych wierzcholkow" << std::endl;
       std::cout << "s - sprwadzenie dlugosci przeciwleglych bokow" << std::endl;
       std::cout << "m - wyswietl menu" << std::endl;
       std::cout << "k - koniec dzialania programu" << std::endl;
       while (option != 'k')
       {
              if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", side))
                     return 1;
              Lacze.Rysuj();
              std::cout << std::endl;
              std::cout << "Twoj wybor? (m - menu) > ";
              std::cin >> option;
              switch (option)
              {
              case 'o':
              {
                     std::cout << "Podaj wedlug ktorej osi bedziesz obracac prostopadloscian x,y lub z" << std::endl;
                     do
                     {

                            Macierz3x3 matrix;
                            matrix.Calculate(angle, wymiar);
                            side = matrix * side;
                     } while (wymiar == '.');
              }
              break;
              case 'p':
              {
                     std::cout << "Wprowadz wspolrzedne wektora translacji w postaci trzech liczb tzn. wspolrzedenj x , wspolrzednej y oraz wspolrzednej z." << std::endl;
                     std::cin >> vector;
                     side.translation(vector);
              }
              break;
              case 'w':
              {

                     std::cout << side;
              }
              break;
              case 'm':
              {
                     std::cout << "o - obrot prostokata o zadany kat" << std::endl;
                     std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
                     std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
                     std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
                     std::cout << "w - wyswietlanie wspolrzednych wierzcholkow" << std::endl;
                     std::cout << "s - sprwadzenie dlugosci przeciwleglych bokow" << std::endl;
                     std::cout << "m - wyswietl menu" << std::endl;
                     std::cout << "k - koniec dzialania programu" << std::endl;
              }
              break;
              case 't':
              {
              }
              break;
              case 'r':
              {
                     std::cout << "Wybierz os dla ktorej chcesz wyswietlic macierz rotacji x ,y lub z" << std::endl;
                     std::cin >> wymiar >> angle;
                     Macierz3x3 matrix;
                     matrix.Calculate(angle, wymiar);
                     std::cout << matrix << std::endl;
              }
              break;
              case 's':
              {
                     side.length();
              }
              break;
              }
       }
       std::cout << std::endl;
       std::cout << "Koniec dzialania programu" << std::endl;
       std::cout << std::endl;
       return 0;
}
