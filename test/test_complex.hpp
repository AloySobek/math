#include <doctest.h>
#include <iostream>
#include <random>

#include "complex.hpp"

TEST_CASE("Complex number initialization") {
    Complex<int> c = Complex<int>(3, 5);

    bool check = c == Complex<int>(3, 5) && c.a() == 3 && c.b() == 5;

    CHECK(check);

    Complex<Complex<int>> cc = Complex<Complex<int>>(Complex<int>(3, 5), Complex<int>(7, 15));

    check = cc == Complex<Complex<int>>(Complex<int>(3, 5), Complex<int>(7, 15)) &&
            cc.a() == Complex<int>(3, 5) && cc.b() == Complex<int>(7, 15);

    CHECK(check);
}

TEST_CASE("Complex number addition") {
    Complex<int> sum = Complex<int>(3, 5) + Complex<int>(7, 15);

    bool check = sum == Complex<int>(10, 20) && sum.a() == 10 && sum.b() == 20;

    CHECK(check);

    sum = Complex<int>(0, 0) + Complex<int>(0, 0);

    check = sum == Complex<int>(0, 0) && sum.a() == 0 && sum.b() == 0;

    CHECK(check);

    sum = Complex<int>(-3, -5) + Complex<int>(-7, -15);

    check = sum == Complex<int>(-10, -20) && sum.a() == -10 && sum.b() == -20;

    CHECK(check);
}

TEST_CASE("Complex number multiplication") {
    Complex<int> product = Complex<int>(3, 7) * Complex<int>(11, 17);

    bool check = product == Complex<int>(-86, 128) && product.a() == -86 && product.b() == 128;

    CHECK(check);

    product = Complex<int>(0, 0) * Complex<int>(0, 0);

    check = product == Complex<int>(0, 0) && product.a() == 0 && product.b() == 0;

    CHECK(check);

    product = Complex<int>(-3, -7) * Complex<int>(-11, -17);

    check = product == Complex<int>(-86, 128) && product.a() == -86 && product.b() == 128;

    CHECK(check);
}

TEST_CASE("Complex number multiplication") {
    Complex<int> product = Complex<int>(3, 7) * Complex<int>(11, 17);

    bool check = product == Complex<int>(-86, 128) && product.a() == -86 && product.b() == 128;

    CHECK(check);

    product = Complex<int>(0, 0) * Complex<int>(0, 0);

    check = product == Complex<int>(0, 0) && product.a() == 0 && product.b() == 0;

    CHECK(check);

    product = Complex<int>(-3, -7) * Complex<int>(-11, -17);

    check = product == Complex<int>(-86, 128) && product.a() == -86 && product.b() == 128;

    CHECK(check);
}

TEST_CASE("Random complex number addition") {
    std::random_device rd;

    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-100, 100);

    for (int i = 0; i < 10; ++i) {
        int a = distr(gen);
        int b = distr(gen);
        int c = distr(gen);
        int d = distr(gen);

        Complex<int> alpha = Complex<int>(a, b);
        Complex<int> beta = Complex<int>(c, d);

        Complex<int> sum = alpha + beta;

        bool check = sum.a() == a + c && sum.b() == b + d;

        CHECK(check);
    }
}

TEST_CASE("Random complex number multiplication") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-100, 100);

    for (int i = 0; i < 10; ++i) {
        int a = distr(gen);
        int b = distr(gen);
        int c = distr(gen);
        int d = distr(gen);

        Complex<int> alpha = Complex<int>(a, b);
        Complex<int> beta = Complex<int>(c, d);

        Complex<int> product = alpha * beta;

        bool check = product.a() == (a * c - b * d) && product.b() == (a * d + b * c);

        CHECK(check);
    }
}
