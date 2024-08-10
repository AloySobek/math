#include "polynomial.hpp"

namespace polynomial {

Term::Term(std::string str) {
    coefficient = std::stod(str.substr(0, str.find("*") - 1));
    exponent = std::stoi(str.substr(str.find("^") + 1, str.length()));
}

Term::Term(double coefficient, unsigned int exponent)
    : coefficient{coefficient}, exponent{exponent} {}

Term::Term(const Term &another) {
    coefficient = another.coefficient;
    exponent = another.exponent;
}

Term &Term::operator=(const Term &another) {
    if (&another != this) {
        coefficient = another.coefficient;
        exponent = another.exponent;
    }

    return *this;
}

Term &Term::operator+=(const Term &another) {
    assert(exponent == another.exponent && "Only terms with same degree can be added");

    coefficient += another.coefficient;

    return *this;
}

Term &Term::operator-=(const Term &another) {
    assert(exponent == another.exponent && "Only terms with same degree can be subtracted");

    coefficient -= another.coefficient;

    return *this;
}

Term &Term::operator*=(const Term &another) {
    coefficient *= another.coefficient;
    exponent += another.exponent;

    return *this;
}

Term Term::operator+(const Term &another) const {
    assert(exponent == another.exponent && "Only terms with same degree can be added");

    return Term(coefficient + another.coefficient, exponent);
}

Term Term::operator-(const Term &another) const {
    assert(exponent == another.exponent && "Only terms with same degree can be subtracted");

    return Term(coefficient - another.coefficient, exponent);
}

Term Term::operator*(const Term &another) const {
    return Term(coefficient * another.coefficient, exponent + another.exponent);
}

Term Term::operator-() const { return Term(-coefficient, exponent); }

std::string Term::str() const {
    return ((std::ostringstream()) << coefficient).str() + " * X^" +
           ((std::ostringstream()) << exponent).str();
}

double Term::get_coefficient() const { return coefficient; }
unsigned int Term::get_exponent() const { return exponent; }

std::ostream &operator<<(std::ostream &out, const Term &term) { return (out << term.str()); }

Term::~Term() {}

Polynomial::Polynomial(std::string str) {
    std::map<unsigned int, Term> terms;

    construct(terms, preprocess(str));

    for (auto &i : terms) {
        this->terms.push_back(i.second);
    }
}

Polynomial::Polynomial(std::initializer_list<Term> args) {
    std::map<unsigned int, Term> terms;

    for (auto &arg : args) {
        if (terms.contains(arg.get_exponent())) {
            terms[arg.get_exponent()] += arg;
        } else {
            terms.emplace(arg.get_exponent(), arg);
        }
    }
}

Polynomial::Polynomial(const Polynomial &another) : terms{another.terms} {}

Polynomial &Polynomial::operator=(const Polynomial &another) {
    if (&another != this) {
        terms.clear();

        for (auto &term : another.terms) {
            terms.push_back(term);
        }
    }

    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &another) {
    for (int i = 0; i < another.terms.size(); ++i) {
        if (i < terms.size()) {
            terms[i] += another.terms[i];
        } else {
            terms.push_back(another.terms[i]);
        }
    }

    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &another) {
    for (int i = 0; i < another.terms.size(); ++i) {
        if (i < terms.size()) {
            terms[i] -= another.terms[i];
        } else {
            terms.push_back(-another.terms[i]);
        }
    }

    return *this;
}

std::string Polynomial::str() {
    std::string result;

    for (int i = 0; i < terms.size(); ++i) {
        result += terms[i].str();

        if (i + 1 < terms.size()) {
            result += " + ";
        }
    }

    return result;
}

Polynomial::~Polynomial() {}

// Replace all ' - ' with ' + -'
std::string Polynomial::preprocess(std::string str) {
    std::string result;

    for (size_t minus = str.find("- "); minus != std::string::npos; minus = str.find("- ")) {
        result += str.substr(0, minus - 1) + " + -";
        str = str.substr(minus + 2, str.length());
    }

    result += str;

    return result;
}

void Polynomial::construct(std::map<unsigned int, Term> &terms, std::string str) {
    auto plus = str.find("+");

    if (plus != std::string::npos) {
        Term term(str.substr(0, plus - 1));

        if (terms.contains(term.get_exponent())) {
            terms[term.get_exponent()] += term;
        } else {
            terms.emplace(term.get_exponent(), term);
        }

        construct(terms, str.substr(plus + 2, str.length()));
    } else {
        Term term(str);

        if (terms.contains(term.get_exponent())) {
            terms[term.get_exponent()] += term;
        } else {
            terms.emplace(term.get_exponent(), term);
        }
    }
}

} // namespace polynomial
