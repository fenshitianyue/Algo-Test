#include <iostream>
#include <map>
#include <vector>
using namespace std;


int find_num(const vector<int>& v){
  map<int, size_t> m;
  for(const auto& it : v){
    m[it]++;
  }
  for(const auto& it : m){
    if(it.second > (v.size() >> 1))
      return it.first;
  }
  return 0;
}

int main() {
  vector<int> v{1, 2, 3, 2, 2, 2, 5, 4, 2};  
  cout << find_num(v) << endl;
  return 0;
}
