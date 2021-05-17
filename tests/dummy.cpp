#include "../tests/doctest/doctest.h"
#include "example.h"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "Prostopadloscian.hh"
#define DL_BOKU 50
#define SZ_BOKU 60
#define WYSOKOSC_BOKU 30

#define SIZE 3
// Tests that don't naturally fit in the headers/.cpp files directly
// can be placed in a tests/*.cpp file. Integration tests are a good example.

/*Testy klasy Matrix*/
TEST_CASE("Konstruktor prametryczny")
{
    double m1[][SIZE] = {{3, 2, 4}, {1, 5, 6}};
    double m2[][SIZE] = {{3, 5, 7}, {6, 7, 5}};

    Macierz3x3 ma(m1);

    CHECK(ma == Matrix(m1));
    CHECK(ma != Matrix(m2));
}
TEST_CASE("Konstruktor bezparametryczny")
{
    double mat[][SIZE] = {{0, 0, 0},
                          {0, 0, 0},
                          {0, 0, 0}};
    Macierz3x3 ma1;
    Macierz3x3 ma2(mat);
    CHECK_EQ(ma1, ma2);
}
TEST_CASE("Operator *,test 1")
{
    double w1[] = {19, 19, 32};
    double w2[] = {1, 2, 4};
    double m1[][SIZE] = {{3, 2, 3}, {1, 5, 2}, {2, 3, 6}};

    Macierz3x3 ma1(m1);

    Vector3D we1(w2);
    Vector3D we2;
    Vector3D we3(w1);

    we2 = ma1 * we1;

    CHECK_EQ(we2, we3);
}
TEST_CASE("Operator *,test 2")
{
    double w1[] = {-19, -19, -32};
    double w2[] = {-1, -2, -4};
    double m1[][SIZE] = {{3, 2, 3}, {1, 5, 2}, {2, 3, 6}};

    Macierz3x3 ma1(m1);

    Vector3D we1(w2);
    Vector3D we2;
    Vector3D we3(w1);

    we2 = ma1 * we1;

    CHECK_EQ(we2, we3);
}

/*Testy dla klasy Cuboid*/
TEST_CASE("Konsturktor bezparametryczny")
{
    int dl = 0;
    int sz = 0;
    int wys = 0;
    double we[] = {0, 0, 0};
    Vector3D ve(we);
    Cuboid cub2(ve, dl, sz, wys);
    Cuboid cub1;
    CHECK_EQ(cub1, cub2);
}
TEST_CASE("Konstruktor parametryczny")
{
    double w1[] = {3, 4, 6};
    double w2[] = {8, 9, 7};

    Vector3D we1(w1);
    Vector3D we2(w2);

    Cuboid cub1(we1, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);
    Cuboid cub2(we2, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);

    CHECK_EQ(cub1, cub1);
}
TEST_CASE("Translacja,test 1")
{
    double w1[] = {3, 4, 5};
    double w2[] = {8, 9, 8};
    double w3[] = {11, 13, 13};

    Vector3D we1(w1);
    Vector3D we2(w2);
    Vector3D we3(w3);

    Cuboid cub1(we1, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);
    Cuboid cub2(we3, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);

    std::cout << cub1 << std::endl;
    std::cout << std::endl;
    std::cout << cub2 << std::endl;
    std::cout << std::endl;
    cub1.translation(we2);
    std::cout << cub1 << std::endl;
    std::cout << std::endl;
    CHECK_EQ(cub1, cub2);
}
TEST_CASE("Translacja,test 2")
{
    double w1[] = {3, 4, 5};
    double w2[] = {-8, -9, -11};
    double w3[] = {-5, -5, -6};

    Vector3D we1(w1);
    Vector3D we2(w2);
    Vector3D we3(w3);

    Cuboid cub1(we1, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);
    Cuboid cub2(we3, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);

    std::cout << cub1 << std::endl;
    std::cout << std::endl;
    std::cout << cub2 << std::endl;
    std::cout << std::endl;
    cub1.translation(we2);
    std::cout << cub1 << std::endl;
    std::cout << std::endl;

    CHECK_EQ(cub1, cub2);
}
TEST_CASE("Translacja,test 3")
{
    double w1[] = {3, 4, 6};
    double w2[] = {0, -9, -7};
    double w3[] = {3, -5, -1};

    Vector3D we1(w1);
    Vector3D we2(w2);
    Vector3D we3(w3);

    Cuboid cub1(we1, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);
    Cuboid cub2(we3, WYSOKOSC_BOKU, SZ_BOKU, DL_BOKU);

    std::cout << cub1 << std::endl;
    std::cout << std::endl;
    std::cout << cub2 << std::endl;
    std::cout << std::endl;
    cub1.translation(we2);
    std::cout << cub1 << std::endl;
    std::cout << std::endl;
    CHECK_EQ(cub1, cub2);
}
// TEST_CASE("Rotacja,test 1")
// {
//     double w1[] = {3, 4};
//     double w2[] = {3, 4};

//     Vector3D we1(w1);
//     Vector3D we2(w2);

//     Cuboid re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);
//     Cuboid re2(we2, DL_KROTKI_BOK, DL_DLUGI_BOK);

//     Macierz3x3 ma;

//     ma.Calculate(90);

//     re1 = ma * re1;
//     re2 = ma * re2;

//     CHECK_EQ(re1, re2);
// }
// TEST_CASE("Rotacja,test 2")
// {
//     double w1[] = {3, 4};
//     double w2[] = {3, 4};

//     Vector3D we1(w1);
//     Vector3D we2(w2);

//     Cuboid re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);
//     Cuboid re2(we2, DL_KROTKI_BOK, DL_DLUGI_BOK);

//     Macierz3x3 ma;

//     ma.Calculate(-90);

//     re1 = ma * re1;
//     re2 = ma * re2;

//     CHECK_EQ(re1, re2);
// }
// TEST_CASE("Długość boków")
// {
//     double w1[] = {3, 4, 5};

//     Vector3D we1(w1);

//     Cuboid re1(we1, DL_KROTKI_BOK, DL_DLUGI_BOK);

//     re1.length();

//     CHECK_EQ(re1, re1);
// }

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.