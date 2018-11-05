#include <stdio.h>
#include <string.h>
#define SIZE 10

//构建next数组，有效元素下标从1开始
void Next(char* Tar, int* next){
  next[1]=0;//next数组第一个元素为0
  size_t j = 1; //用来遍历目标串
  size_t k = 0; 
  while (j < strlen(Tar)) {
    //k == 0,说明已经无法向右移动了 || 匹配到了相等的项
    if (k == 0 || Tar[j-1] == Tar[k-1]) {
      next[++j] = ++k; // 就是老师上课讲的 next[j+1] = k + 1 步骤
    }else{
      k = next[k]; //向右滑动
    }
  }
}
//返回值含义
//-1 ： 匹配失败
//!=-1 ：字串在目标串中的起始下标
int KMP(char * Src,char * Tar){
  int next[SIZE];
  Next(Tar,next);//根据模式串Tar,初始化next数组
  size_t i = 1;
  size_t j = 1;
  while (i <= strlen(Src) && j <= strlen(Tar)) {
    //j==0:代表模式串的第一个字符就和当前测试的字符不相等；
    //Src[i-1]==Tar[j-1],如果对应位置字符相等；这两种情况下，指向当前测试的两个指针下标i和j都向后移
    if (j == 0 || Src[i-1] == Tar[j-1]) {
      i++;
      j++;
    }
    else{
      j = next[j];//如果测试的两个字符不相等，i不动，j变为子串当前字符的next值
    }
  }
  if (j > strlen(Tar)) {//如果条件为真，说明匹配成功
    return i-(int)strlen(Tar);
  }
  return -1;
}

//测试用例
int main() {
  char tar[] = "ababcabcacbab";
  char son_str[] = "abcac";
  int i=KMP(tar,son_str);
  printf("%d",i);
  return 0;
}
