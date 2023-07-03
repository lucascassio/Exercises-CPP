#include <string>
#include <iostream>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  estoque_[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  for(auto it = estoque_.begin(); it != estoque_.end(); it++) {
    if(mercadoria == it->first) {
      if(qtd > it->second) {
        cout << it->first << " inexistente" << endl;
      } else {
        it->second -= qtd;
      }
  }
  for(auto it = estoque_.begin(); it != estoque_.end(); it++) {
    if(estoque_.find(mercadoria) == estoque_.end()) {
      cout << it->first << " inexistente" << endl;
    }
  }
}

}
unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
    for(auto it = estoque_.begin(); it != estoque_.end(); it++) {
    if(mercadoria == it -> first) {
      return it->second;
    }
  }
  return 0;
}

void Estoque::imprime_estoque() const {
  for(auto it = estoque_.begin(); it != estoque_.end(); it++) {
    cout << it->first << ", " << it->second << endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  for(auto it = rhs.estoque_.begin(); it != rhs.estoque_.end(); it++) {
    add_mercadoria(it->first, it->second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for(auto it = rhs.estoque_.begin(); it != rhs.estoque_.end(); it++) {
    sub_mercadoria(it->first, it->second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
    for (auto it = lhs.estoque_.begin(); it != lhs.estoque_.end(); it++) {
      auto aux = rhs.estoque_.find(it->first);
      if (aux == rhs.estoque_.end() || it->second >= aux->second) {
        return false;
      }
    }
    return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
    for (auto it = rhs.estoque_.begin(); it != rhs.estoque_.end(); it++) {
      auto aux = lhs.estoque_.find(it->first);
      if (aux == lhs.estoque_.end() || it->second >= aux->second) {
        return false;
      }
    }
    return true;
}