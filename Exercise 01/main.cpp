#include <iostream>
#include <string>

using namespace std;

void numVowels(string p) {

    int a=0, e=0, i=0, o=0, u=0;

    for(int l=0; l <= p.length(); l++) {
    if(p[l] == 'a') a++;
    if(p[l] == 'e') e++;
    if(p[l] == 'i') i++;
    if(p[l] == 'o') o++;
    if(p[l] == 'u') u++;
  }

      if (a >= 1) cout << "a " << a << endl;
      if(e >= 1) cout << "e " << e << endl;
      if(i >= 1) cout << "i " << i << endl;
      if(o >= 1) cout << "o " << o << endl;
      if(u >= 1) cout << "u " << u << endl;

}

int main() {
  string palavra;

  cout << "insira a palavra: ";
  cin >> palavra;

  numVowels(palavra);

  return 0;
}
