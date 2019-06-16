//字符串反转

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string reverse_string(string& s){
  if(s.empty())
    return s;
  size_t start = 0;
  size_t end = s.size() - 1;
  while(start < end){
    swap(s[start], s[end]);
    ++start;
    --end;
  }
  return s;
}

int main(){
  string s;
  while(getline(cin, s)){
    cout << reverse_string(s) << endl;
    s.clear();
  }
  return 0;
}



