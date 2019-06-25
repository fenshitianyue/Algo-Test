#include <stdio.h>
#include <stdlib.h>

void swap(char* c1, char* c2){
  char tmp = *c1;
  *c1 = *c2;
  *c2 = tmp;
}

void permutation(char* str, char* pStart){
  if(!str || !pStart){
    return;
  }
  char* p = pStart;
  if(*pStart == '\0'){
    printf("%s  ", str);
  }else{
    for(p = pStart; *p != '\0'; ++p){
      swap(pStart, p);
      permutation(str, pStart + 1);
      swap(pStart, p);
    }
  }
}

//test case
int main() {
  char str[] = "abc";  
  permutation(str, str);
  printf("\n");
  return 0;
}
