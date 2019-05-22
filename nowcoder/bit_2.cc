///////////////////////////////////////////////////////
//描述：倒置输入的字符串，以空格分隔
//url: www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId
//eg:
// input:I love beijing.
// output: beijing. love I
///////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

//case 1
//将输入的字符串按照空格进行切割，将切割后的部分存入vector
//然后将vector中的元素逆向输出
void case_1_tool(const string& input, vector<string>& output, const char split_char){
  stringstream s(input);
  string buf;
  size_t output_index = 0;
  while(getline(s, buf, split_char)){
    if(buf.empty()){
      break;
    }
    output.push_back(buf);
    ++output_index;
  }
}

void case_1(){
  string s;
  vector<string> s_sets;
  while(getline(cin ,s)){
    case_1_tool(s, s_sets, ' ');
    for(auto it = s_sets.rbegin(); it != s_sets.rend(); ++it){
      if(it + 1 == s_sets.rend())
        cout << *it << endl;
      else 
        cout << *it << " ";
    }
    s.clear();
    s.shrink_to_fit();
    s_sets.clear();
    s_sets.shrink_to_fit();
  }
}


//case 2
//先将整个字符串n逆置过来，然后以空格为分隔符，依次逆置每一个子字符串
void case_2(){
  string s; 
  while(getline(cin, s)){
    reverse(s.begin(), s.end()); //先逆转整个字符串
    auto start = s.begin();
    while(start != s.end()){
      auto end = start;
      //end依次找到以空格为分隔符的子字符串的尾边界 
      while(end != s.end() && *end != ' '){
        end++;
      }
      reverse(start, end);
      if(end != s.end()) //如果没到字符串结尾，就将start置为下一个子字符串的首边界
        start = end + 1;
      else //否则设置退出循环的条件
        start = end;
    }
    cout << s << endl;
    string().swap(s); //释放字符串底层的空间
  }
}

//case 3
//这个方法是一个比较讨巧的方法。直接利用cin接收输入，遇到空格自然就结束了，也就实现了
//以空格分隔子字符串，然后将每次接收到的子字符串拼接到要输出的字符串的前面即可
void case_3(){
  string child_s, s; 
  cin >> s;
  while(cin >> child_s){
    s = child_s + " " + s;
  } 
  cout << s << endl;
}

int main(){

}

