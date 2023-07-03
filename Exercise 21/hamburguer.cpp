#include "hamburguer.hpp"
#include <string>

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  tipo_ = tipo;
  if (artesanal) {
    artesanal_ = "artesanal";
  } else {
    artesanal_ = "simples";
  }
  m_valor_unitario = valor_unitario;
  m_qtd = qtd;
}

std::string Hamburguer::descricao() const {
  std::string descricao = std::to_string(m_qtd) + "X Hamburguer " + tipo_ + " " + artesanal_ + ".";
  return descricao;
}
