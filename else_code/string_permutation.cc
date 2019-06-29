///////////////////////////////////////////////////////
// 题目要求：
//     输出指定字符串的全部可能组成方式，eg：abc -> abc, acb, bac, bca, cab, cba
// 思路：
//     用STL的algorithm搞定即可，主要用到了其中的算法next_permutation
///////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print_permutation(string& s){
  string container(s);
  do{
    cout << container.data()
         << endl;
  }while(next_permutation(container.begin(), container.end()));
}

int main() {
  string s;
  while(getline(cin, s)){
    print_permutation(s);
    s.clear();
  }
  return 0;
}
