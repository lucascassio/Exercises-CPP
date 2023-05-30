#include "racional.h"

#include <cmath>
#include <iostream>

void Racional::Simplificar() {
    int divisor = 2;
    while (divisor <= abs(numerador_) && divisor <= abs(denominador_)) {
        if (numerador_ % divisor == 0 && denominador_ % divisor == 0) {
            numerador_ /= divisor;
            denominador_ /= divisor;
        } else {
            divisor++;
        }
    }
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
    if(d != 0) { 
        numerador_ = n;
        denominador_ = d;
        Simplificar();
    }
    
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const {
  return Racional(-numerador_, denominador_);
}

Racional Racional::somar(Racional k) const {
  int n = (numerador_ * k.denominador() + denominador_ * k.numerador());
  int d = denominador_ * k.denominador();
  return Racional(n, d);
}

Racional Racional::subtrair(Racional k) const {
  int n = ((numerador_ * k.denominador()) - (denominador_ * k.numerador()));
  int d = denominador_ * k.denominador();
  return Racional(n, d);
}

Racional Racional::multiplicar(Racional k) const {
  int n = numerador_ * k.numerador();
  int d = denominador_ * k.denominador();
  return Racional(n, d);
}

Racional Racional::dividir(Racional k) const {
  int n = numerador_ * k.denominador();
  int d = denominador_ * k.numerador();
  return Racional(n, d);
}

