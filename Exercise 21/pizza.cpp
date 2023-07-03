#include "pizza.hpp"

#include <string>

using namespace std;

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
  string descricao = to_string(m_qtd) + "X" + " Pizza " + sabor_ + ", " + to_string(pedacos_) + " pedacos e " + borda_recheada_ + ".";
  return descricao;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  sabor_ = sabor;
  pedacos_ = pedacos;
  if(borda_recheada == true) {
    borda_recheada_ = "borda recheada";
  } else {
    borda_recheada_ = "sem borda recheada";
  }
  m_valor_unitario = valor_unitario;
  m_qtd = qtd;
}