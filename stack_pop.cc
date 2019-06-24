///////////////////////////////////////////////////////
// 题目描述：
// 输入两个整数序列，其中一个序列表示栈的push顺序，判断
// 另一个序列有没有可能是对应的pop顺序
// 思路：
// 1.把push序列依次入栈，直到栈顶元素等于pop序列的第一个元素，
//   然后把栈顶元素出栈，pop序列移动到第二个元素
// 2.如果栈顶元素仍然等于pop序列当前元素，那么继续上述过程
// 3.如果push序列已经全部入栈，但是pop序列并未全部遍历，而且
//   栈顶元素不等于当前pop元素，那么pop序列不是一个可能的出
//   栈序列；如果栈为空，并且pop序列也全部被遍历，则说明pop
//   序列是一个可能的出栈序列
///////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stack>

bool isPopSerial(const std::string _push, const std::string _pop){
  if(_push.empty() || _pop.empty())
    return false;
  size_t pushLen = _push.size();
  size_t popLen = _pop.size();
  if(pushLen != popLen) 
    return false;
  size_t pushIndex = 0, popIndex = 0;
  std::stack<char> s;
  while(pushIndex < popIndex){
    //把push序列依次入栈，直到栈顶元素等于pop序列的第一个元素
    s.push(_push[pushIndex]); 
    ++pushIndex;
    while(!s.empty() && s.top() == _pop[popIndex]){
      s.pop();
      ++popIndex;
    }
  }
  if(s.empty() && popIndex == popLen) 
    return true;
  return false;
}

int main() {
  std::string _push("12345") ;
  std::string _pop("32541");

  return 0;
}

