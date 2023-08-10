#include <iostream>
#include <map>

using namespace std;

int main(){
  
  map<char, int> mp = {
   {'T', 7},
   {'S', 8},
   {'a', 4} 
  };

  mp['u'] = 9;
  pair<char, int> new_key('z', 20);
  
  mp.insert(new_key);
  cout << new_key.first << endl;
  mp.erase(new_key.first);
  new_key.first = 'j';

  cout << new_key.first << endl; 

  mp.insert(pair<char, int>('v', 9));



  cout << mp['v'] << endl;

  return 0;
}