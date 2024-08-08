#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace polynomial {

class Term {
  public:
    Term(double coefficient = 0.0f, int exponent = 0);

    Term(std::string str);

    Term(const Term &another);

    void from_str(std::string str);

    std::string to_str() const;

    int get_exponent() const;

    Term &operator=(const Term &another);

    Term operator+(const Term &another);

    Term operator-(const Term &another);

    Term operator-() const;

    friend std::ostream &operator<<(std::ostream &out, const Term &term);

    ~Term();

  private:
    double coefficient;
    int exponent;
};

class Polynomial {
  public:
    Polynomial();

    Polynomial(std::string str);

    Polynomial(const Polynomial &another);

    void from_str(std::string str);

    std::string to_str();

    void simplify();

    Polynomial &operator=(const Polynomial &another);

    ~Polynomial();

  private:
    std::vector<Term> terms;

    std::string preprocess(std::string str);
    void construct(std::string str);
    Term sum(std::vector<Term> summands);
};

} // namespace polynomial
