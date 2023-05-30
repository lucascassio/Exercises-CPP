#include "complexo.h"
#include <cmath>


Complexo::Complexo() {
  modulo_ = 0;
  argumento_ = 0;
}


Complexo::Complexo(double a, double b) {
  modulo_ = a;
  argumento_ = b;
}

double Complexo::real() {
  return modulo_;
}

// Retorna a parte imaginária do número complexo.
double Complexo::imag() {
  return argumento_;
}


bool Complexo::igual(Complexo x) {
  return modulo_ == x.modulo_ && argumento_ == x.argumento_;
}


void Complexo::Atribuir(Complexo x) {
  modulo_ = x.modulo_;
  argumento_ = x.argumento_;
}


double Complexo::modulo() {
  return modulo_;
}

Complexo Complexo::conjugado() {
  return Complexo(modulo_, -argumento_);
}

// Retorna o simétrico do número complexo.
Complexo Complexo::simetrico() {
  return Complexo(-modulo_, -argumento_);
}

Complexo Complexo::inverso() {
  double den = modulo_*modulo_ + argumento_*argumento_;
  return Complexo(modulo_/den, -argumento_/den);
}

Complexo Complexo::somar(Complexo y) {
  double a = modulo_*std::cos(argumento_) + y.modulo_*std::cos(y.argumento_);
  double b = modulo_*std::sin(argumento_) + y.modulo_*std::sin(y.argumento_);
  return Complexo(a, b);
}

Complexo Complexo::subtrair(Complexo y) {
  double a = modulo_*std::cos(argumento_) - y.modulo_*std::cos(y.argumento_);
  double b = modulo_*std::sin(argumento_) - y.modulo_*std::sin(y.argumento_);
  return Complexo(a, b);
}

Complexo Complexo::multiplicar(Complexo y) {
  double a = modulo_*y.modulo_ - argumento_*y.argumento_;
  double b = modulo_*y.argumento_ + argumento_*y.modulo_;
  return Complexo(a, b);
}

Complexo Complexo::dividir(Complexo y) {
  double den = y.modulo_*y.modulo_ + y.argumento_*y.argumento_;
  double a = (modulo_*y.modulo_ + argumento_*y.argumento_)/den;
  double b = (argumento_*y.modulo_ - modulo_*y.argumento_)/den;
  return Complexo(a, b);
}
