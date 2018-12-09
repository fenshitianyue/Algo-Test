///////////////////////////////////////////////////////
// 要求：不使用乘除法，循环，if...else, switch, case等关键字
// 及条件判断语句?:
// 题目描述：
// 求1+2+3+...+n
///////////////////////////////////////////////////////

#include <stdio.h>

int sum_solution(int n){
  int sum = n;
  int tmp = (n > 0) && (sum += sum_solution(n - 1));
  return sum;
}

int main() {
  int re = sum_solution(5); 
  int re2 = sum_solution(6); 
  int re3 = sum_solution(7); 
  int re4 = sum_solution(8); 
  printf("re = %d\n", re);
  printf("re2 = %d\n", re2);
  printf("re3 = %d\n", re3);
  printf("re4 = %d\n", re4);
  return 0;
}
