#include <stdio.h>
#include <stdlib.h>

void Print(int* array, int size) {
  for(int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void CountSort(int* array, int size) {
  int max_idx = array[0];
  int min_idx = array[0];
  for(int i = 0; i < size; ++i) {
    if(max_idx < array[i])
      max_idx = array[i];
    if(min_idx > array[i])
      min_idx = array[i];
  }
  int space_size = max_idx - min_idx + 1;
  int* tmp_space = (int*)calloc(space_size, sizeof(int));
  if(NULL == tmp_space)
    return;
  //数据统计
  for(int i = 0; i < size; ++i) {
    ++tmp_space[array[i] - min_idx]; 
  }
  //数据回收
  int index = 0;
  for(int i = 0; i < space_size; ++i) {
    while(tmp_space[i]--) {
      array[index++] = i + min_idx;
    }
  } 
}

int main() {
  int array[] = {3, 1, 5, 7, 2, 4, 9, 6};
  printf("sort begin: ");
  Print(array, sizeof(array) / sizeof(array[0]));

  CountSort(array, sizeof(array) / sizeof(array[0]));

  printf("sort after: ");
  Print(array, sizeof(array) / sizeof(array[0]));
  
  return 0;
}
