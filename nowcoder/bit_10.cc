///////////////////////////////////////////////////////
// 将第二个字符串插入到第一个字符串中，使得第一个
// 字符串成为回文串，输出有多少种插入方式
// url:www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId
///////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool judge(const string& s){
  auto begin = s.begin();
  auto end = s.end() - 1;
  while(begin <= end){
    if(*begin == *end){
      ++begin;
      --end;
      continue;
    }
    break;
  }
  return begin > end;
}

void print_method_num(string& s1, string& s2){
  if(0 == s1.size() && 0 == s2.size()){
    cout << "0" << endl;
    return;
  }
  else if(0 == s1.size()){
    if(judge(s2)){
      cout << "1" << endl;
      return;
    }
    cout << "0" << endl;
    return;
  }
  else if(0 == s2.size()){
    if(judge(s1)){
      cout << "1" << endl;
      return;
    }
    cout << "0" << endl;
    return;
  }
  int num = 0;
  for(size_t i = 0; i <= s1.size(); ++i){
    string tmp = s1;
    tmp.insert(i, s2);
    if(judge(tmp))
      ++num;
  }
  cout << num << endl;
}

int main() {
  string s1;
  getline(cin, s1);
  string s2;
  getline(cin, s2);
  print_method_num(s1, s2);
  return 0;
}

