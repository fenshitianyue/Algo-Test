#include <stdio.h>

//int pow_3(int a){
//  return a * a * a;
//}
//
//int main() {
//  int arr[128] = {0}; 
//  int index = 0;
//  int count = 0;
//  for(index = 0; index < 128; ++index){
//    scanf("%d", &arr[index]);
//    if(0 == arr[index]) {
//      break;
//    } 
//  }
//  for(int j = 0; j < index; ++j){
//    for(int i = 0;i < arr[j]; ++i){
//      if(arr[j] == 1){
//        count++;
//      } else if(arr[j] == pow_3(i)){
//        count++;
//      } 
//    }
//  }
//  printf("%d\n", count);
//  return 0;
//}


int table[1024] = { 0  };

void InitTable(){
  int index = 0;
  for (int i = 1; i < 1024; ++i){
    table[index++] = i * i *i;
  }
}

int main(){
  InitTable();
  int count = 0;
  int num = 0;
  while (scanf("%d", &num) != EOF && num != 0){
    for (int i = 0; i < 1024; ++i){
      if (num == table[i]){
        count++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}


