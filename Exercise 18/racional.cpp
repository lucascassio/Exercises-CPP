#include "racional.h"
#include <cmath>
#include <algorithm>

using namespace std;

void Racional::Simplificar() {
  int mdc = std::abs(std::__gcd(numerador_, denominador_));
  numerador_ /= mdc;
  denominador_ /= mdc;
}

Racional::Racional() {
    numerador_ = 0;
    denominador_ = 1;
}

Racional::Racional(int n)  {
    numerador_ = n;
    denominador_ = 1;
}


Racional::Racional(int n, int d) {
        numerador_ = n;
        denominador_ = d;
        Simplificar();
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::operator-() const {
  if(numerador_ == 0) {
    return numerador_;
  }
  return Racional(-numerador_, denominador_);
}

Racional Racional::operator+(Racional k) const {
  int n = (numerador_ * k.denominador() + denominador_ * k.numerador());
  int d = denominador_ * k.denominador();
  return Racional(n, d);
}

Racional Racional::operator-(Racional k) const {
  int n = ((numerador_ * k.denominador()) - (denominador_ * k.numerador()));
  int d = denominador_ * k.denominador();
  return Racional(n, d);
}

Racional Racional::operator*(Racional k) const {
  int n = numerador_ * k.numerador();
  int d = denominador_ * k.denominador();
  return Racional(n, d);
}

Racional Racional::operator/(Racional k) const {
  int n = numerador_ * k.denominador();
  int d = denominador_ * k.numerador();
  return Racional(n, d);
}

Racional::operator float() const {
    float f = numerador_;
    return f / denominador_;
}

Racional::operator string() const {
    return  to_string(numerador_) + "/" + to_string(denominador_);
}

ostream& operator<<(ostream& out, Racional r) {
    out << r.numerador() << "/" << r.denominador();
    return out;
}

istream& operator>>(istream& in, Racional& r) {
    int numerador, denominador;
    in >> numerador >> denominador;
    r = Racional(numerador, denominador);
    return in;
}

