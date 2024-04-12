#include <doctest.h>
#include <iostream>
#include <random>

#include "vector.hpp"

TEST_CASE("Vectors") {
    Vec<double, 4> v1;
    Vec<double, 4> v2{1.0f};
    Vec<double, 4> v3{2.0f, 2.0f};
    Vec<double, 4> v4{3.0f, 3.0f, 3.0f};
    Vec<double, 4> v5{4.0f, 4.0f, 4.0f, 4.0f};

    CHECK(v1.at(0).value() == 0.0f);
}
