#include "google_password.h"

#include <iostream>

using namespace std;

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {

    if(validPassword(password)) {
      Usuario NovoUsuario{login, password};
      string novaUrl = url;
      passwords_.insert({novaUrl, NovoUsuario});
    }
 }

void GooglePassword::remove(const std::string& url) {
    for(auto it = passwords_.begin(); it != passwords_.end(); it++) {
        if(it -> first == url) {
          passwords_.erase(it);
          return;
        }
    }
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
  for(auto it = passwords_.begin(); it != passwords_.end(); it++) {
    if(it -> first == url) {
      if(it -> second.password == old_password && validPassword(new_password)) {
      it -> second.login = login;
      it -> second.password = new_password;
    }
  }
}
}



void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */

  int aux = 0;

  for(auto it = passwords_.begin(); it != passwords_.end(); it++) {
    aux++;
  }

  cout << aux << endl;

  for(auto it = passwords_.begin(); it != passwords_.end(); it++) {
   cout << it -> first << ":" << " " << it->second.login << " and " << it->second.password << endl;
  }
}

bool GooglePassword::validPassword(const std::string& password) const {

    if (password.find("123456") != std::string::npos) {
        return false;
    }

    if (password.length() > 50) {
        return false;
    }

    if (password.length() < 6) {
        return false;
    }

    for(int i= 0; i < password.length(); i++) {
        if(password[i] == ' ') {
            return false;
        }
    }

    return true;
}

