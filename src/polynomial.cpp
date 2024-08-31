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

bool Term::operator==(const Term &another) const {
    return coefficient == another.coefficient && exponent == another.exponent;
}

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

Polynomial::Polynomial(std::vector<Term> input_terms) {
    std::map<unsigned int, Term> grouped_terms;

    for (Term &term : input_terms) {
        if (grouped_terms.contains(term.get_exponent())) {
            grouped_terms[term.get_exponent()] += term;
        } else {
            grouped_terms.emplace(term.get_exponent(), term);
        }
    }

    for (std::pair pair : grouped_terms) {
        terms.push_back(pair.second);
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

// (3X^2 + x + 1)(7X^2 + 2x + 3) = 21x^4 + 6x^3 + 3x^2 + 7x^3 + 2x^2 +x

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

Polynomial &Polynomial::operator*=(const Polynomial &another) {
    std::map<unsigned int, Term> t;

    for (auto &i : terms) {
        for (auto &j : another.terms) {
            Term result = i + j;

            if (t.contains(result.get_exponent())) {
                t[result.get_exponent()] += result;
            } else {
                t.emplace(result.get_exponent(), result);
            }
        }
    }

    terms.clear();

    for (auto &i : t) {
        terms.push_back(i.second);
    }

    return *this;
}

Polynomial Polynomial::operator*(const Polynomial &another) const {
    std::map<unsigned int, Term> t;

    for (auto &i : terms) {
        for (auto &j : another.terms) {
            Term result = i + j;

            if (t.contains(result.get_exponent())) {
                t[result.get_exponent()] += result;
            } else {
                t.emplace(result.get_exponent(), result);
            }
        }
    }

    auto values = std::views::values(t);

    std::vector<Term> test{values.begin(), values.end()};

    std::initializer_list<Term> args;

    return Polynomial(test);
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
