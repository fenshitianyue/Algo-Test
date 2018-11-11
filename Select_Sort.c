#include <stdio.h>
#define SIZE(array) ((sizeof(array)) / (sizeof(array[0])))

//assist function
void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void SelectSort(int* array, size_t size){
  size_t min_index = 0;
  for(size_t i = 0; i < size; ++i){
    min_index = i;
    for(size_t j = i+1; j < size; ++j){
      if(array[j] < array[min_index]){
        min_index = j;
      }
    }
    if(i != min_index){
      swap(&array[i], &array[min_index]);
    }
  }
}

void SelectSortPro(int* array, size_t size){
  size_t max_index = 0, min_index = 0;
  size_t start = 0, end = size - 1;
  for(size_t i = 0; i < ( size >> 1 ); ++i){
    max_index = min_index = i;
    for(size_t j = start + 1; j <= end; ++j){
      if(array[max_index] < array[j]) max_index = j;
      if(array[min_index] > array[j]) min_index = j;
    }
    if(end != max_index){
      swap(&array[end], &array[max_index]);
    }
    if(array[min_index] == array[end] && start != max_index){
      swap(&array[start], &array[max_index]);
    } else if(start != min_index) {
      swap(&array[start], &array[min_index]);
    }
    --end;
    ++start;
  }//end for(i)
}

//test
int main() {
  int arr[] = {8, -3, 9, 10, 101, -1}; 
  printf("not sort array:\n"); 
  for(size_t i = 0; i < SIZE(arr); ++i){
    printf("%d ", arr[i]);
  }
  SelectSortPro(arr, SIZE(arr));
  printf("\nalready sort array:\n"); 
  for(size_t i = 0; i < SIZE(arr); ++i){
    printf("%d ", arr[i]);
  }
  printf("\n"); 
  return 0;
}

