#include <cstdint>
#include <functional>
#include <vector>

template <typename T, uint64_t N> class V {
  public:
    V(std::initializer_list<T> args) : n_tuple{N} {
        for (uint64_t i{0}; i < args.size() && i < N; ++i) {
            n_tuple[i] = args[i];
        }
    }
    V(std::function<T(uint64_t)> m) {
        for (uint64_t i{0}; i < N; ++i) {
            n_tuple[i] = m(i);
        }
    }

    V operator+(V &b) {
        return V{[&](uint64_t i) -> T { return n_tuple[i] + b[i]; }};
    }

    V operator*(double x) {}

    ~V() {}

  private:
    std::vector<T> n_tuple;
};

template <typename T> class Vector4 {
  public:
    Vector4() {}

    Vector4 operator+(Vector4 &other) {}
    Vector4 operator*(int scalar) {}

    double dot(Vector4 &b) {}
    Vector4 cross(Vector4 &b) {}

    ~Vector4() {}

  private:
    T x;
    T y;
    T z;
    T w;
};
