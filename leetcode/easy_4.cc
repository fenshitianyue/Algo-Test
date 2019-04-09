//question url : https://leetcode-cn.com/problems/valid-parentheses/
//给定一个只包括'(', ')','{','}','[',']'的字符串，判断字符串中的括号是否匹配(类型，种类)

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_valid(string str){
  stack<char> s; 
  for(const auto& it : str){
    if(it == '(' || it == '[' || it == '{'){
      s.push(it);
    }else{
      if(s.empty()){
        return false;
      } 
      else if((s.top() == '(' && it == ')') || 
              (s.top() == '[' && it == ']') ||
              (s.top() == '{' && it == '}')){
        s.pop();
      }else{
        return false;
      }
    }
  } 
  if(!s.empty())
    return false;
	return true;
}

//test case
int main() {
  string s1 = "()"; 
  cout << is_valid(s1) << endl;
  string s2 = "()[]{}"; 
  cout << is_valid(s2) << endl;
  string s3 = "(]"; 
  cout << is_valid(s3) << endl;
  return 0;
}
