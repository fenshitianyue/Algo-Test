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
  size_t begin = 0;
  size_t end = s.size() - 1;
  while(begin != end){
    if(s[begin] != s[end])
      return false;
    ++begin;
    --end;
  }
  return true;
}

void print_method_num(string& s1, string& s2){
  int count = 0;
  string s;
  for(size_t i = 0; i != s1.size(); ++i){
    s = s1; 
    s.insert(i, s2);
    if(judge(s))
      ++count;
  }
  cout << count << endl;
}

int main() {
  string s1;
  getline(cin, s1);
  string s2;
  getline(cin, s2);
  print_method_num(s1, s2);
  return 0;
}

