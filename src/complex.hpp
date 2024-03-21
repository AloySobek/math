#include <type_traits>
// A complex number is an ordered pair (a,b) where a and b ∈ R
// The set of all complex numbers is denoted as C
template <typename T> class Complex {
  public:
    Complex(T a, T b) : _a(a), _b(b) {}
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

        return this;
    }

    bool operator==(const Complex<T> &other) const { return _a == other._a && _b == other._b; }

    // Let a be a complex number (x, y) or (x + yi)
    // Let b be a complex number (z, w) or (z + wi)
    // Then addition of complex is defined by:
    // (x + yi) + (z + wi) = (x + z) + (y + w)i
    // Notice how the resulting addition is by itself a complex number:
    // Let λ be a complex number (x + z, y + w) or ((x + z) + (y + w)i)
    // let n = x + z and m = y + w, then λ = (n, m) or (n + mi)
    Complex<T> operator+(const Complex<T> &b) const { return Complex<T>(_a + b._a, _b + b._b); }

    T a() const { return _a; }
    T b() const { return _b; }

    ~Complex() {}

  private:
    T _a; // a ∈ R
    T _b; // b ∈ R
};
