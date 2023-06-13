#include "dicionario.h"


Dicionario::Dicionario() {
}

int Dicionario::tamanho() {
    elementos_.size();
}

bool Dicionario::pertence(string chave) {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it -> chave == chave) {
            return true;
        }
    }
    return false;
}

string Dicionario::menor() {

    if (elementos_.empty()) {
        DicionarioVazio x;
        throw x;
    }

    string aux = elementos_.back().chave;
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

    ChaveInexistente x;
    x.chave = chave;
    throw x;
}

void Dicionario::Inserir(string chave, string valor) {

    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it -> chave == chave) {
            ChaveRepetida x;
            x.chave = chave;
            throw x;
            return;
        }
    }

    Elemento novo{chave, valor};
    elementos_.push_back(novo);
}

void Dicionario::Remover(string chave) {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it -> chave == chave) {
            elementos_.erase(it);
            return;
        }
    }

    ChaveInexistente x;
    x.chave = chave;
    throw x;
}

void Dicionario::Alterar(string chave, string valor) {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++) {
        if(it -> chave == chave) {
            it -> valor = valor;
            return;
        }
    }

    ChaveInexistente x;
    x.chave = chave;
    throw x;
}

Dicionario::~Dicionario() {
    elementos_.clear();
}