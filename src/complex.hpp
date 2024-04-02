#include <type_traits>

// C = {a + bi : a, b ∈ R}
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
    // a * B = a(c + di) = ac + adi
    template <typename S> Complex<T> operator*(S scalar) const {
        return Complex<T>(_a * scalar, _b * scalar);
    }
    Complex<T> operator-() const { return Complex<T>(_a, _b) * -1; }

    T a() const { return _a; }
    T b() const { return _b; }

    ~Complex() {}

  private:
    T _a; // a ∈ R
    T _b; // b ∈ R
};

// Fun facts:
// i^2 = -1
// a + 0i = a ∈ R
// 0 + bi = bi ∈ C
// 0 + 1i = i ∈ C
// R ⊂ C

// Properties
// Commutativity: a + b = b + a && ab = ba for all a, b ∈ C
// Associativity: (a + b) + c = a + (b + c) && (ab)c = a(bc) for all a, b, c ∈ C
// Identities: a + 0 = a && a * 1 = a for all a ∈ C
// Additive inverse: For every a ∈ C, there exists a unique b ∈ C such that a + b = 0
// Multiplicative inverse: For every a ∈ C, there exists a unique b ∈ C such that ab = 1
// Distributive: a(b + c) = ab + ac for all a, b, c ∈ C
