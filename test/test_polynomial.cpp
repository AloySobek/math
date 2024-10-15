#include <cstdlib>
#include <doctest.h>

#include "polynomial.hpp"

TEST_CASE("Random terms addition") {
    double c1 = (double)((rand() % 10000) - (rand() % 10000)),
           c2 = (double)((rand() % 10000) - (rand() % 10000));
    unsigned int e = rand() % 1000;

    polynomial::Term term1(c1, e);
    polynomial::Term term2(c2, e);

    CHECK((term1 + term2) == polynomial::Term(c1 + c2, e));

    polynomial::Term result = term1 + term2;

    CHECK(result.get_coefficient() == c1 + c2);
    CHECK(result.get_exponent() == e);
}

TEST_CASE("3 * X^2 + 7 * X^2") {
    polynomial::Term term1("3 * X^2");
    polynomial::Term term2("7 * X^2");

    CHECK((term1 + term2) == polynomial::Term("10 * X^2"));

    polynomial::Term result = term1 + term2;

    CHECK(result.get_coefficient() == 10.0f);
    CHECK(result.get_exponent() == 2);
}

TEST_CASE("Random terms subtraction") {
    double c1 = (double)((rand() % 10000) - (rand() % 10000)),
           c2 = (double)((rand() % 10000) - (rand() % 10000));
    unsigned int e = rand() % 1000;

    polynomial::Term term1(c1, e);
    polynomial::Term term2(c2, e);

    CHECK((term1 - term2) == polynomial::Term(c1 - c2, e));

    polynomial::Term result = term1 - term2;

    CHECK(result.get_coefficient() == c1 - c2);
    CHECK(result.get_exponent() == e);
}

TEST_CASE("10 * X^2 - 12 * X^2") {
    polynomial::Term term1("10 * X^2");
    polynomial::Term term2("12 * X^2");

    CHECK((term1 - term2) == polynomial::Term("-2 * X^2"));

    polynomial::Term result = term1 - term2;

    CHECK(result.get_coefficient() == -2.0f);
    CHECK(result.get_exponent() == 2);
}

TEST_CASE("Random terms multiplication") {
    double c1 = (double)((rand() % 10000) - (rand() % 10000)),
           c2 = (double)((rand() % 10000) - (rand() % 10000));
    unsigned int e1 = rand() % 1000, e2 = rand() % 1000;

    polynomial::Term term1(c1, e1);
    polynomial::Term term2(c2, e2);

    CHECK((term1 * term2) == polynomial::Term(c1 * c2, e1 + e2));

    polynomial::Term result = term1 * term2;

    CHECK(result.get_coefficient() == c1 * c2);
    CHECK(result.get_exponent() == e1 + e2);
}

TEST_CASE("Polynomial") {
    polynomial::Polynomial polynomial1("-1 * X^3 + 5 * X^1 + 1 * X^0");
    polynomial::Polynomial polynomial2("92 * X^3 − 3 * X^2 − 4 * X^1 + 9 * X^0");
}
