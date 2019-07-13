//题目链接；www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t; 
  while(cin >> s >> t){
    int res = 0;
    size_t pos = 0;
    //依次在s中查找t，直到再也找不到t
    while((pos = s.find(t, pos)) != string::npos){
      pos += t.size(); //跳过t串整体的长度
      ++res; //计数++
    }
    cout << res << endl;
  }
  return 0;
}
