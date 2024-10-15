#include <algorithm>
#include <cstdint>
#include <functional>
#include <optional>
#include <vector>

class Vector {
  public:
    Vector(float x = 0.0f, float y = 0.0f) : x{x}, y{y} {}
    Vector(Vector &other) : x{other.x}, y{other.y} {}

    ~Vector() {}

  private:
    float x;
    float y;
};

template <typename T, uint64_t N> class Vec {
  public:
    Vec() : v{N, 0} {}
    Vec(std::initializer_list<T> args) : v{N, 0} {}
    Vec(const std::function<T(uint64_t)> initializer) : v{N, 0} {
        for (uint64_t i{0}; i < v.size(); ++i) {
            v[i] = initializer(i);
        }
    }

    Vec<T, N> add(const Vec<T, N> &other) const {
        return Vec<T, N>{[&](uint64_t i) -> T { return this->v[i] + other.v[i]; }};
    }

    std::optional<T> at(const uint64_t i) const {
        if (i < v.size()) {
            return v[i];
        }

        return std::nullopt;
    }

    ~Vec() {}

  private:
    const std::vector<T> v;
};

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
