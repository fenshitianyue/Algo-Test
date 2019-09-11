#include <stdio.h>

void Print(int* array, int size) {
  for(int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void ShellSort(int* array, int size) {
  int incre = size;
  while(incre > 1) {
    incre = incre / 3 + 1;
    for(int i = incre; i < size; ++i) {
      int end = i - incre;
      int key = array[i];
      while(end >= 0 && key < array[end]) {
        array[end + incre] = array[end];
        end -= incre;
      }
      array[end + incre] = key;
    } 
  }
}

int main() {
  int array[] = {3, 1, 5, 7, 2, 4, 9, 6};
  printf("sort begin: ");
  Print(array, sizeof(array) / sizeof(array[0]));

  ShellSort(array, sizeof(array) / sizeof(array[0]));

  printf("sort after: ");
  Print(array, sizeof(array) / sizeof(array[0]));
  
  return 0;
}
