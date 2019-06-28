///////////////////////////////////////////////////////
// 来源：leetcode
// 题目：判断一个整数是否为回文数 
// 难度；easy
///////////////////////////////////////////////////////

#include <iostream>
#include <deque>
using namespace std;

//思路：
//1. 将所给数的每一位（不是比特位）存放到双端队列中
//2. 依次判断队列的头是否等于队列的尾，如果相同，并且队列中不止1个元素，则删除队头和队尾，继续这个过程
//3. 若队列为空或者只剩一个元素，则说明全部匹配上，否则说明不是回文数
//4. 注意判断边界条件，eg：所给数等于0，所给数小于0....

bool isPalindrome(int x){
  if(x < 0) return false;
  deque<int> tmp;
  while(x != 0){
    tmp.push_back(x % 10);
    x /= 10;
  }
  while(!tmp.empty() && tmp.front() == tmp.back()){
    if(tmp.size() != 1){
      tmp.pop_back();
      tmp.pop_front();
    }else 
      return false;
  }
  if(tmp.empty()) 
    return true;
  return false;
}

//test case
int main() {
  int x = -121; 
  int y = 121;
  int m = 0;
  int n = 10;
  cout << isPalindrome(x) << endl;
  cout << isPalindrome(y) << endl;
  cout << isPalindrome(m) << endl;
  cout << isPalindrome(n) << endl;
  return 0;
}
