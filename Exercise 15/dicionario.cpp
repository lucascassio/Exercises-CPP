#include "dicionario.h"


Dicionario::Dicionario() {
}

int Dicionario::tamanho() {
    int aux = 0;
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        aux++;
    }
    
    return aux;
}

bool Dicionario::pertence(string chave) {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it -> chave == chave) {
            return true;
        } else {
            return false;
        }
    }
}

string Dicionario::menor() {
    string aux = elementos_.front().chave();
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(aux > it -> chave) {
            aux = it -> chave;
        }
    }
    return aux;
}

string Dicionario::valor(string chave) {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it -> chave == chave) {
            return it -> valor;
        }
    }
}

void Dicionario::Inserir(string chave, string valor) {
    Elemento novo{chave, valor};
    
    elementos_.push_back(novo);
}

void Dicionario::Remover(string chave) {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it -> chave == chave) {
            elementos_.erase(it);
            break;
        }
    }
}

void Dicionario::Alterar(string chave, string valor) {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it -> chave == chave) {
            it -> valor = valor;
        }
    }
}

Dicionario::~Dicionario() {
    elementos_.clear();
}