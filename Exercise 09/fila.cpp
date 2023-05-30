#include "fila.h"

// Cria uma fila vazia;
Fila::Fila() {
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}

// Retorna o primeiro elemento da fila.
// Precondição: a fila *não* pode estar vazia.  
string Fila::primeiro() {
    return primeiro_ -> chave;
}

// Retorna o último elemento da fila.
// Precondição: a fila *não* pode estar vazia.  
string Fila::ultimo() {
    return ultimo_ -> chave;
}

// Informa se a fila está vazia.
bool Fila::vazia() {
    if(primeiro_ == nullptr) {
        return true;
    } else {
        return false;
    }
}

// Insere um elemento no fim da fila.
void Fila::Inserir(string k) {  
    No* novoElemento = new No{k, nullptr};
    if (primeiro_ == nullptr) {
        primeiro_ = novoElemento;
        ultimo_ = novoElemento;
    } 
    else {
        ultimo_->proximo = novoElemento; 
        ultimo_ = novoElemento;
    }
}

// Remove o elemento no início da fila. 
// Precondição: a fila *não* pode estar vazia.
void Fila::Remover() {
    No* aux = primeiro_;
    primeiro_ = primeiro_ -> proximo;
    delete aux;
}

// Retorna o número de elementos na fila.
int Fila::tamanho() {
    int n = 0;  
    No* aux = primeiro_;
    while(aux != nullptr) {
        n++;
        aux = aux -> proximo;
    }

    return n;

}

// Libera toda a memória alocada para a fila.
Fila::~Fila() {
    No* aux = primeiro_;

    while(aux != nullptr) {
        aux = aux -> proximo;
        delete aux;
    }

}