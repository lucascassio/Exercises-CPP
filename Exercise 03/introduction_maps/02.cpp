#include <iostream>
#include <map>

using namespace std;

int main(){
  
  map<char, int> mp = {
   {'T', 9},
   {'S', 8},
   {'a', 4} 
  };

  mp['u'] = 9;
  pair<char, int> new_key('z', 20);
  
  mp.insert(new_key);
  
  for(map <char, int>::iterator itr = mp.begin(); itr != mp.end(); itr++){
    
    cout << itr->second << endl;

  }

  return 0;
}