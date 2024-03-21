#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>

#include "complex.hpp"

TEST_CASE("testing the factorial function") {
    CHECK(Complex<int>(3, 5).a() == 3);
    CHECK(Complex<int>(3, 5).b() == 5);
    CHECK((Complex<int>(3, 5) + Complex<int>(7, 5)).a() == 10);
    CHECK((Complex<int>(3, 5) + Complex<int>(7, 15)).b() == 20);
    CHECK(Complex<int>(3, 5) + Complex<int>(7, 15) == Complex<int>(10, 20));
    CHECK(Complex<Complex<int>>(Complex<int>(3, 5), Complex<int>(7, 15)).a() == Complex<int>(3, 5));
    CHECK(Complex<Complex<int>>(Complex<int>(3, 5), Complex<int>(7, 15)).b() ==
          Complex<int>(7, 15));
}
