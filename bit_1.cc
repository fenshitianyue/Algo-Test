#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////
// 删除第一个字符串中的第二个字符串中的字符
///////////////////////////////////////////////////////


void delete_target_char_from_string(string& target, string& ch_set){
  size_t i = 0;
  auto begin = target.begin();
  while(true){
    size_t n = target.find(ch_set[i]);
    if(n != string::npos){
      target.erase(begin + n);
    }else if(++i > ch_set.size()){
      break;
    }
  }
}

int main() {
  string s1;
  string s2;
  getline(cin, s1);
  getline(cin, s2);
  cout << "begin: " << s1 << endl;
  delete_target_char_from_string(s1, s2);
  cout << "after: " << s1 << endl;
  
  return 0;
}
