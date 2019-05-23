//字符串中找出连续最长的数字串
//url: www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void find_maxlength_num_str(const string& s){
  string tmp;
  string max;
  size_t i = 0;
  while(i != s.size()){
    switch(isdigit(s[i])){
      case 0:
        ++i;
        break;
      default:
        while(i != s.size() && isdigit(s[i])){
          tmp += s[i++];
        }
        if(max.size() < tmp.size()){
          max = tmp;
        }
        tmp.clear();
        break;
    }
  }
  cout << max << endl;
}

int main(){
  string s;
  while(getline(cin, s)){
    find_maxlength_num_str(s);
    s.clear();
    s.shrink_to_fit();
  }
  return 0;
}


