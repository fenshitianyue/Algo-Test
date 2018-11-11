#include <stdio.h>
#define SIZE(array) ((sizeof(array)) / (sizeof(array[0])))

//assist function
void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void SelectSort(int* array, int size){
  int min_index = 0;
  for(int i = 0; i < size; ++i){
    min_index = i;
    for(int j = i+1; j < size; ++j){
      if(array[j] < array[min_index]){
        min_index = j;
      }
    }
    if(i != min_index){
      swap(&array[i], &array[min_index]);
    }
  }
}


//test
int main() {
  int arr[] = {1, 3, 9, 10, 101, -1}; 
  printf("not sort array:\n"); 
  for(size_t i = 0; i < SIZE(arr); ++i){
    printf("%d ", arr[i]);
  }
  SelectSort(arr, SIZE(arr));
  printf("\nalready sort array:\n"); 
  for(size_t i = 0; i < SIZE(arr); ++i){
    printf("%d ", arr[i]);
  }
  printf("\n"); 
  return 0;
}

