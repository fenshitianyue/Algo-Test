//题目描述：
//不能使用+、-、*、/运算符计算两个数的和


#include <stdio.h>

int add(int a,int b){
  if(!(a & b)) //如果没有进位
    return a ^ b;
  return add(a ^ b, (a & b) << 1); //如果有进位，递归计算“没有进位时的和”与“进位的”和
}

int main(){
  int sum = add(10, 20);
  printf("sum = %d\n", sum);
  return 0;
}
