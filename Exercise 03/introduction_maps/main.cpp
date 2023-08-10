#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

string countWords(map<string, int>& words, string text){

  stringstream ss(text);
  string word;
  int num = 0; 
  string mostCommonWord = ""; 

  while(ss >> word){
    auto p = words.emplace(word, 1);
    if (!p.second) {
      p.first->second++;
    }
    if (p.first->second > num) {
      num = p.first->second;
      mostCommonWord = p.first->first;
    }
  }

  return mostCommonWord;
}

int main(){

  string text;

  getline(cin, text);

  map<string, int> words;

  cout << countWords(words, text) << endl;

  return 0;
}
