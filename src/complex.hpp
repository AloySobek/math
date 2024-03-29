#include <type_traits>

// A complex number is an ordered pair (a,b) where a and b ∈ R
// The set of all complex numbers is denoted as C
template <typename T> class Complex {
  public:
    Complex() : _a{0}, _b{0} {}
    Complex(T a, T b) : _a{a}, _b{b} {}
    Complex(const Complex<T> &other) {
        if (&other != this) {
            _a = other._a;
            _b = other._b;
        }
    }

    Complex<T> &operator=(const Complex<T> &other) {
        if (&other != this) {
            _a = other._a;
            _b = other._b;
        }

        return *this;
    }

    // A = B -> (a + bi) = (c + di) -> a = c and b = d
    bool operator==(const Complex<T> &b) const { return _a == b._a && _b == b._b; }
    // A + B = (a + bi) + (c + di) = (a + c) + (bi + di) = (a + c) + (b + d)i
    Complex<T> operator+(const Complex<T> &b) const { return Complex<T>(_a + b._a, _b + b._b); }
    // A * B = (a + bi)(c + di) = ac + (ad + bc)i - bd = (ac - bd) + (ad + bc)i; i^2 = -1
    Complex<T> operator*(const Complex<T> &b) const {
        return Complex<T>((_a * b._a - _b * b._b), (_a * b._b + _b * b._a));
    }

    T a() const { return _a; }
    T b() const { return _b; }

    ~Complex() {}

  private:
    T _a; // a ∈ R
    T _b; // b ∈ R
};
