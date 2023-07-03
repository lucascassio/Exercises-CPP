#ifndef VETOR_H_
#define VETOR_H_

#include <iostream> 
using namespace std;


#include <string>

using std::string;

// Define um vetor cujos índices variam em
// qualquer intervalo, inclusive negativos.
template<typename Tipo>
class Vetor {
  public:
    // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
    // O valor associado aos índices é indefinido.
    // PRECONDIÇÃO: fim >= inicio.
    Vetor(int inicio, int fim) : inicio_(inicio), fim_(fim) {
      elementos_ = new Tipo[fim - inicio + 1];
    }

    // Redimensiona o vetor de forma que os índices passam a variar
    // de 'inicio2' até 'fim2'.
    // O valor associado aos índices que estão na interseção de
    // [inicio_, fim_] e [inicio2, fim2], não se alteram.
    // Já o valor dos demais índices é indefinido.  
    // PRECONDIÇÃO: fim2 >= inicio2.
    void Redimensionar(int inicio2, int fim2) {
      Tipo* novos_elementos = new Tipo[fim2 - inicio2 + 1];
      int inicio_intersecao = max(inicio_, inicio2);
      int fim_intersecao = min(fim_, fim2);
      int tamanho_intersecao = fim_intersecao - inicio_intersecao + 1;
      for (int i = inicio_intersecao; i <= fim_intersecao; i++) {
         novos_elementos[i - inicio2] = elementos_[i - inicio_];
      }

      delete[] elementos_;
      elementos_ = novos_elementos;
      inicio_ = inicio2;
      fim_ = fim2;
    }

    // Retorna uma referência a variável correspondente ao índice i.
    // Pode ser utilizado tanto para atribuir quanto para acessar valores.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    Tipo& operator[](int i) { 
      for(int j = inicio_; j <= fim_; j++) {
        if(i == j) {
          return elementos_[j - inicio_];
        }
      }
    }

    // Desaloca a memória reservada para os elementos do vetor.
    ~Vetor() {
      delete [] elementos_;
    }
  private:
    int inicio_;  // Primeiro índice válido do vetor.
    int fim_;  // Último índice válido do vetor.
    Tipo* elementos_;  // Elementos do vetor.
};

#endif