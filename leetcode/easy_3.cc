///////////////////////////////////////////////////////
// 编写一个函数来查找字符串数组中的最长公共前缀
// 如果不存在公共前缀，返回空字符串""
// question url: https://leetcode-cn.com/problems/longest-common-prefix/ 
///////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(const vector<string>& strs){
  if(strs.empty()){
    return string("");
  }
  //find min string
  string::size_type min = strs.begin()->size();
  for(const auto& it : strs){
    if(min > it.size())
      min = it.size();
  }
  //matching
  string common;
  for(decltype(min) j = 0; j < min; ++j){
    auto cur_ch = strs[0][j];
    for(decltype(strs.size()) i = 0; i < strs.size();){
      if(cur_ch == strs[i][j]){
        ++i;
      }else{
        return common;
      }
    }
    common += cur_ch;
  }
  return common;
}

//test case
int main() {
  vector<string> strs = {"dog", "recaer", "hello"}; 
  string common = longestCommonPrefix(strs);
  cout << common << endl;
  return 0;
}
