///////////////////////////////////////////////////////
// 计算两个大整数相加的和
// eg:
// input:
//  999999999999 1
// ouput:
//  1000000000000
///////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add_string(string& s1, string& s2){
  int i = s1.size() - 1;
  int j = s2.size() - 1;
  string result("");
  int carry = 0;
  while(i >= 0 || j >= 0){
    if(i >= 0){
      carry += s1[i] - '0';
    } 
    if(j >= 0){
      carry += s2[j] - '0';
    } 
    result += (carry % 10 + '0'); 
    carry /= 10;
    --i;
    --j;
  }
  //相加完后，如果还有进位，给最高位+1
  if(carry){
    result += "1";
  }
  reverse(result.begin(), result.end());
  return result;
}

int main(){
  string s1, s2;
  while(cin >> s1 >> s2){
    cout << add_string(s1, s2) << endl;
  }
  return 0;
}
