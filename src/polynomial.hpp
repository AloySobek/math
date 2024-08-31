#include <cassert>
#include <iostream>
#include <map>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

namespace polynomial {

class Term {
  public:
    Term(std::string str);
    Term(double coefficient = 0.0f, unsigned int exponent = 0);
    Term(const Term &another);

    Term &operator=(const Term &another);

    Term &operator+=(const Term &another);
    Term &operator-=(const Term &another);
    Term &operator*=(const Term &another);

    Term operator+(const Term &another) const;
    Term operator-(const Term &another) const;
    Term operator*(const Term &another) const;

    Term operator-() const;

    bool operator==(const Term &another) const;

    friend std::ostream &operator<<(std::ostream &out, const Term &term);

    // [-]C * X^E
    std::string str() const;

    double get_coefficient() const;
    unsigned int get_exponent() const;

    ~Term();

  private:
    double coefficient;
    unsigned int exponent;
};

class Polynomial {
  public:
    Polynomial(std::string str);
    Polynomial(std::vector<Term> terms);
    Polynomial(const Polynomial &another);

    Polynomial &operator=(const Polynomial &another);

    Polynomial &operator+=(const Polynomial &another);
    Polynomial &operator-=(const Polynomial &another);
    Polynomial &operator*=(const Polynomial &another);

    Polynomial operator+(const Polynomial &another) const;
    Polynomial operator-(const Polynomial &another) const;
    Polynomial operator*(const Polynomial &another) const;

    Polynomial operator-() const;

    friend std::ostream &operator<<(std::ostream &out, const Polynomial &polynomial);

    // Term + Term + Term ...
    std::string str();

    ~Polynomial();

  private:
    std::vector<Term> terms;

    std::string preprocess(std::string str);
    void construct(std::map<unsigned int, Term> &terms, std::string str);
};

} // namespace polynomial
