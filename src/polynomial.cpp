#include "polynomial.hpp"

namespace polynomial {

Term::Term(double coefficient, int exponent) : coefficient{coefficient}, exponent{exponent} {}

Term::Term(std::string str) { from_str(str); }

Term::Term(const Term &another) {
    coefficient = another.coefficient;
    exponent = another.exponent;
}

void Term::from_str(std::string str) {
    coefficient = std::stod(str.substr(0, str.find("*") - 1));
    exponent = std::stoi(str.substr(str.find("^") + 1, str.length()));
}

std::string Term::to_str() const {
    return ((std::ostringstream()) << coefficient).str() + " * X^" +
           ((std::ostringstream()) << exponent).str();
}

int Term::get_exponent() const { return exponent; }

Term &Term::operator=(const Term &another) {
    if (&another != this) {
        coefficient = another.coefficient;
        exponent = another.exponent;
    }

    return *this;
}

Term Term::operator+(const Term &another) {
    assert(exponent == another.exponent && "Only terms with same degree can be added");

    return Term(coefficient + another.coefficient, exponent);
}

Term Term::operator-(const Term &another) {
    assert(exponent == another.exponent && "Only terms with same degree can be subtracted");

    return Term(coefficient - another.coefficient, exponent);
}

Term Term::operator-() const { return Term(-coefficient, exponent); }

std::ostream &operator<<(std::ostream &out, const Term &term) {
    out << term.to_str();

    return out;
}

Term::~Term() {}

Polynomial::Polynomial() : terms{Term()} {}

Polynomial::Polynomial(std::string str) { from_str(str); }

Polynomial::Polynomial(const Polynomial &another) : terms{another.terms} {}

void Polynomial::from_str(std::string str) { construct(preprocess(str)); }

std::string Polynomial::to_str() {
    std::string result;

    for (int i = 0; i < terms.size(); ++i) {
        result += terms[i].to_str();

        if (i + 1 < terms.size()) {
            result += " + ";
        }
    }

    return result;
}

void Polynomial::simplify() {
    std::vector<Term> zeros;
    std::vector<Term> firsts;
    std::vector<Term> seconds;

    for (auto &i : terms) {
        switch (i.get_exponent()) {
        case 0: {
            zeros.push_back(i);

            break;
        }
        case 1: {
            firsts.push_back(i);

            break;
        }
        case 2: {
            seconds.push_back(i);

            break;
        }
        default: {
            break;
        }
        }
    }

    terms.clear();
    if (zeros.size() > 0)
        terms.push_back(sum(zeros));
    if (firsts.size() > 0)
        terms.push_back(sum(firsts));
    if (seconds.size() > 0)
        terms.push_back(sum(seconds));
}

Polynomial &Polynomial::operator=(const Polynomial &another) {
    if (&another != this) {
        terms.clear();
        terms.resize(another.terms.capacity());

        for (auto &i : another.terms) {
            terms.push_back(i);
        }
    }

    return *this;
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

void Polynomial::construct(std::string str) {
    auto plus = str.find("+");

    if (plus != std::string::npos) {
        terms.push_back(Term(str.substr(0, plus - 1)));

        construct(str.substr(plus + 2, str.length()));
    } else {
        terms.push_back(Term(str));
    }
}

Term Polynomial::sum(std::vector<Term> summands) {
    if (summands.size() < 1) {
        return Term();
    }

    Term result(0, summands[0].get_exponent());

    for (auto &i : summands) {
        result = result + i;
    }

    return result;
}

} // namespace polynomial
