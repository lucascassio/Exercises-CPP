#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
  for(auto it = lista_.begin(); it != lista_.end(); it++) {
    if(p.prioridade > it -> prioridade) {
      lista_.insert(it, p);
      return;
    }
  }
  lista_.push_back(p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string nome = lista_.front().nome;
  lista_.pop_front();
  return nome;
}

void FilaDePrioridade::Remover(string nome) {
  for(auto it = lista_.begin(); it != lista_.end(); it++) {
    if(it -> nome == nome) {
      lista_.erase(it);
      break;
    }
  }
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;
  int i = 0;
  for(auto it = lista_.begin(); it != lista_.end(); it++) {
    v.push_back(it -> nome);
  }
  return v; 
}