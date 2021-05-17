#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "dummy.cpp"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

#include "Wektor3D.hh"
#include "Macierz3x3.hh"

TEST_CASE("Konstruktor bez parametryczny")
{
    double we[] = {0, 0, 0};

    Vector3D ve1;
    Vector3D ve2(we);
    CHECK_EQ(ve1, ve2);
}
TEST_CASE("Konstruktor parametryczny")
{
    std::stringstream in;

    double we[] = {10, 20, 30};

    Vector3D ve2;

    in << "10 20 30" << std::endl;
    in >> ve2;
    Vector3D ve1(we);
    CHECK_EQ(ve1, ve2);
}
TEST_CASE("Operator +, TEST 1")
{
    double we1[] = {10, 20, 30};
    double we2[] = {5, 10, 15};
    double we3[] = {15, 30, 45};

    Vector3D ve1(we1);
    Vector3D ve2(we2);
    Vector3D ve3(we3);

    CHECK_EQ(ve1 + ve2, ve3);
}
TEST_CASE("Operator +, TEST 2")
{
    double we1[] = {10.001, 20.001, 30.001};
    double we2[] = {5.999, 10.999, 15.999};
    double we3[] = {16, 31, 46};

    Vector3D ve1(we1);
    Vector3D ve2(we2);
    Vector3D ve3(we3);

    CHECK_EQ(ve1 + ve2, ve3);
}
TEST_CASE("Operator -, TEST 1")
{
    double we1[] = {10, 20, 30};
    double we2[] = {5, 10, 15};
    double we3[] = {5, 10, 15};

    Vector3D ve1(we1);
    Vector3D ve2(we2);
    Vector3D ve3(we3);

    CHECK_EQ(ve1 - ve2, ve3);
}
TEST_CASE("Operator -, TEST 2")
{
    double we1[] = {10.001, 20.001, 30.001};
    double we2[] = {5.999, 10.999, 15.999};
    double we3[] = {4.002, 9.002, 14.002};

    Vector3D ve1(we1);
    Vector3D ve2(we2);
    Vector3D ve3(we3);

    CHECK_EQ(ve1 - ve2, ve3);
}
TEST_CASE("Operator wczytywania >>,test 1")
{
    std::stringstream in;

    Vector3D we1;
    double w[] = {4, 1, 5};
    Vector3D we2(w);

    in << "4 1 5" << std::endl;
    in >> we1;

    CHECK_EQ(we1, we2);
}

TEST_CASE("Operator wczytywania >>,test 2")
{
    std::stringstream in;

    Vector3D we1;
    double w[] = {0, 1, 2};
    Vector3D we2(w);

    in << "0 1 2" << std::endl;
    in >> we1;

    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 3")
{
    std::stringstream in;

    Vector3D we1;
    double w[] = {0, 0, 0};
    Vector3D we2(w);

    in << "0 0 0" << std::endl;
    in >> we1;

    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 4")
{
    std::stringstream in;

    Vector3D we1;
    double w[] = {0, 0, 0};
    Vector3D we2(w);

    in << "p 1 4" << std::endl;
    in >> we1;
    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 5")
{
    std::stringstream in;

    Vector3D we1;
    double w[] = {0, 0, 0};
    Vector3D we2(w);

    in << "4 d 5" << std::endl;
    in >> we1;
    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 6")
{
    std::stringstream in;

    Vector3D we1;
    double w[] = {4.888, -3.444, 5.666};
    Vector3D we2(w);

    in << "4.888 -3.444 5.666" << std::endl;
    in >> we1;

    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 7")
{
    std::stringstream in;

    Vector3D we1;
    double w[] = {-4, 3, 5};
    Vector3D we2(w);

    in << "-4 3 5" << std::endl;
    in >> we1;
    CHECK_EQ(we1, we2);
}
TEST_CASE("Operator wczytywania >>,test 8")
{
    std::stringstream in;

    Vector3D we1;
    double w[] = {0, 0, 0};
    Vector3D we2(w);

    in << "4 1 e" << std::endl;
    in >> we1;
    CHECK_EQ(we1, we2);
}

TEST_CASE("Operator wypisywania <<,test 1")
{
    std::stringstream out;

    double w[] = {-4, 3, 6};

    Vector3D we1;
    Vector3D we2(w);

    out << we2;

    CHECK_EQ("-4 3 6", out.str());
}
TEST_CASE("Operator wypisywania <<,test 2")
{
    std::stringstream out;

    double w[] = {-4.888, 3.444, 5.666};

    Vector3D we1;
    Vector3D we2(w);

    out << we2;

    CHECK_EQ("-4.888 3.444 5.666", out.str());
}

TEST_CASE("Operator []")
{
    double w1[] = {6, 7, 5};
    double w2[] = {9, 4, 5};
    double w3[] = {34, 78, 560};

    Vector3D we1(w1);
    Vector3D we2(w2);
    Vector3D we3(w3);

    double x1, x2, x3, y1, y2, y3, z1, z2, z3;
    x1 = 6;
    x2 = 9;
    x3 = 34;
    y1 = 7;
    y2 = 4;
    y3 = 78;
    z1 = 5;
    z2 = 5;
    z3 = 560;

    CHECK(x1 == w1[0]);
    CHECK(y1 == w1[1]);
    CHECK(z1 == w1[2]);
    CHECK(x2 == w2[0]);
    CHECK(y2 == w2[1]);
    CHECK(z2 == w2[2]);
    CHECK(x3 == w3[0]);
    CHECK(y3 == w3[1]);
    CHECK(z3 == w3[2]);
}
