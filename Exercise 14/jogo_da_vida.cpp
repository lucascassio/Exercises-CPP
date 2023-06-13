#include "jogo_da_vida.h"

using namespace std;

JogoDaVida::JogoDaVida(int l, int c) {
    vivas_ = vector<vector<bool>>(l, vector<bool>(c, false));
}

int JogoDaVida::linhas() {
    return vivas_.size();
}

int JogoDaVida::colunas() {
    return vivas_[0].size();
}

bool JogoDaVida::viva(int i, int j) {
    if(i < 0 || j < 0 || j >= colunas() || i >= linhas()) {
        ExcecaoCelulaInvalida x;
        x.linha = i;
        x.coluna = j;
        throw x;
    }
    return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j) {
    if(i < 0 || j < 0 || j >= colunas() || i >= linhas()) {
        ExcecaoCelulaInvalida x;
        x.linha = i;
        x.coluna = j;
        throw x;
    }
    vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j) {
    if(i < 0 || j < 0 || j >= colunas() || i >= linhas()) {
        ExcecaoCelulaInvalida x;
        x.linha = i;
        x.coluna = j;
        throw x;
    }
    vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y) {
    int count = 0;
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;
            
            int nx = (x + i + linhas()) % linhas();
            int ny = (y + j + colunas()) % colunas();
            
            if (viva(nx, ny))
                count++;
        }
    }
    
    return count;
}


void JogoDaVida::ExecutarProximaIteracao() {
  std::vector<std::vector<bool>> proxIteracao = vivas_;

  for (int i = 0; i < linhas(); i++) {
    for (int j = 0; j < colunas(); j++) {
      int vizinhasVivas = NumeroDeVizinhasVivas(i, j);
      if (viva(i, j)) {
        if (vizinhasVivas < 2 || vizinhasVivas > 3) {
          proxIteracao[i][j] = false;
        }
      } else if(vizinhasVivas == 3){
          proxIteracao[i][j] = true;
       }
      }
    }
    vivas_ = proxIteracao;
  }


