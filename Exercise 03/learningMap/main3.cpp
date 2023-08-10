#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(){
  
  map <int, int> map1;

  map1.insert(pair <int, int> (6, 50));
  map1.insert(pair <int, int> (1, 40));
  map1.insert(pair <int, int> (2, 30));
  map1.insert(pair <int, int> (3, 60));
  map1.insert(pair <int, int> (3, 50));
  map1.insert(pair <int, int> (4, 20));
  map1.insert(pair <int, int> (7, 10));
  map1.insert(pair <int, int> (8, 80));
  map1.insert(pair <int, int> (9, 20));
  map1.insert(pair <int, int> (6, 50));

  map <int, int> :: iterator itr;
  cout << endl << "The size of map1 is : "<< map1.size() << endl;

  map1.clear();

  cout << endl << "The size of map1 is : "<< map1.size() << endl << endl;
  cout << "Maximum size of map1 is : " << map1.max_size() << endl;

  return 0;
}