///////////////////////////////////////////////////////
// 统计输入字符串中的字母个数，数字个数，空格个数以及
// 其他字符的个数
///////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

void func(char* arr, int size){
  int table[128] = { 0 };
  for (int i = 0; i < size; ++i){
    table[(int)arr[i]]++;
  }
  //字母
  int num1 = 0;
  for (int i = 65; i <= 90; ++i){
    num1 += table[i];
  }
  for (int i = 97; i <= 122; ++i){
    num1 += table[i];
  }
  printf("%d ", num1);
  //数字
  int num2 = 0;
  for (int i = 48; i <= 57; ++i){
    num2 += table[i];
  }
  printf("%d ", num2);
  //空格
  printf("%d ", table[32]);
  //其他
  int num3 = 0;
  for (int i = 0; i <= 127; ++i){
    if ((i != 32) && (i < 48) && (i >57) && (i < 65) && (i > 90) && (i < 97) && (i > 122)){
      num3 += table[i];
    }
  }
  printf("%d\n", num3);
}

int main()
{
  char arr[128] = { 0 };
  scanf("%[^\n]", arr);
  func(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}
