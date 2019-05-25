//把字符串转换成数字
//    如果字符串不是正确数字，就返回0
//    否则返回转换后的数字
//eg:
//   -12345678 -> 12345678
//   1a123 -> 0

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int str_to_int(string& s){
  if(0 == s.size()){
    return 0;
  }
  int flag = 1;
  int num = 0;
  size_t index = 0;
  //处理正负号
  if(s[index] == '-' || s[index] == '+'){
    if(s[index] == '-')
      flag = -flag;
    ++index;
  }
  for(; index != s.size(); ++index){
    //如果是字符数字，则转换成整数
    if(isdigit(s[index])){
      num = num * 10 + (s[index] - '0');
    }else{
      return 0;
    }
  }
  //如果有负号，则给结果乘以-1
  if(flag < 0)
    return -num;
  return num;
}

int main() {
  string s1 = "1a33"; 
  string s2 = "-12345678";
  cout << str_to_int(s1);
  return 0;
}
