#include "venda.hpp"

#include <iomanip>
#include <string>

using namespace std;

Venda::~Venda() {
  for (auto i : m_pedidos) {
    delete i;
  }
}

void Venda::adicionaPedido(Pedido* p) {
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  int totalPedidos = m_pedidos.size();
  float totalVenda = 0.00f;

  int numPedido = 1;
  for (auto pedido : m_pedidos) {
    std::cout << "Pedido " << numPedido << std::endl;
    std::cout << pedido->resumo() << std::endl;

    totalVenda += pedido -> calculaTotal();
    numPedido++;
  }
  std::cout << "Relatorio de Vendas" << endl;
  std::cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2) << totalVenda << std::endl;
  std::cout << "Total de pedidos: " << totalPedidos << endl;
}
