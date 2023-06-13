#include "vetor.h"

using namespace std;

Vetor::Vetor(int inicio, int fim) {
    if (fim < inicio) {
        IntervaloVazio x;
        x.inicio = inicio;
        x.fim = fim;
        throw x;
    }
    inicio_ = inicio;
    fim_ = fim;
    elementos_ = new string[fim - inicio + 1];
    init_ = vector<bool>(fim - inicio + 1);
    fill(init_.begin(), init_.end(), false);
}

void Vetor::atribuir(int i, std::string valor) {
    if (i < inicio_ || i > fim_) {
        IndiceInvalido x;
        x.indice = i;
        x.inicio = inicio_;
        x.fim = fim_;
        throw x;
    }
    elementos_[i - inicio_] = valor;
    init_[i - inicio_] = true;
}

string Vetor::valor(int i) const {
    if (i < inicio_ || i > fim_) {
        IndiceInvalido x;
        x.indice = i;
        x.inicio = inicio_;
        x.fim = fim_;
        throw x;
    }
    if(init_[i - inicio_] == false) {
        IndiceNaoInicializado x;
        x.indice = i;
        throw x;
    }
    return elementos_[i - inicio_];
}

Vetor::~Vetor() { 
    delete[] elementos_;
}
