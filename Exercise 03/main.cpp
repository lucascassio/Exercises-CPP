#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;

void mostFreqWord(map<string, int>& words, string text) {
    stringstream newText(text);
    string word;

    while(newText >> word) {
    if(words.find(word) == words.end()) {
        words[word] = 0;
    } else {
        words[word]++;
    }
    }

    int freq = 0;
    string mostFreqWord;

    for(auto itr = words.begin(); itr != words.end(); itr++) {
        if((*itr).second >= freq) {
        freq = (*itr).second;
        mostFreqWord = (*itr).first;
        }
    }

    cout << mostFreqWord;
}

int main() {
  
    string line;
    string text = "";
    map<string, int> words;

    while (cin >> line) {
        text += line + "\n";
    }
  
    mostFreqWord(words, text);

    return 0;
}