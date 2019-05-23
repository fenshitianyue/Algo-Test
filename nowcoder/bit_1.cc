#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////
// 删除第一个字符串中的第二个字符串中的字符
// url: www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId
///////////////////////////////////////////////////////

//case 1:
//依次用第一个串中的字符遍历第二个串，判断第二个串是否包含，如果包含，从第一个串中删掉
//时间复杂度：0(N^2)

void case_1(string& target, string& ch_set){
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
  cout << target << endl;
}

//case_2
//1.将第二个字符串中的字符映射到哈希表中
//2.将不在哈希表中的字符添加到一个新字符串中（结果字符串）
//时间复杂度：O(N)

void case_2(string& s1, string& s2){
  int hashtable[256] = {0};
  for(size_t i = 0; i != s2.size(); ++i){
    hashtable[s2[i]]++;
  }
  string ret;
  for(size_t i = 0; i != s1.size(); ++i){
    if(!hashtable[s1[i]]){
      ret += s1[i];
    }
  }
  cout << ret << endl;
}

int main() {
  string s1;
  string s2;
  getline(cin, s1);
  getline(cin, s2);
  //case_1(s1, s2);
  case_2(s1, s2);
  return 0;
}

