#include <stdio.h>
#define SIZE(array) ((sizeof(array)) / (sizeof(array[0])))

//assist function
void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void HeapAdjust(int* array, size_t size, size_t parent){
  size_t child = parent * 2 + 1;
  while(child < size){
    if((child + 1 < size) && (array[child + 1] < array[child])) {
      child += 1;
    }
    if(array[child] > array[parent]){
      swap(&array[child], &array[parent]);      
      parent = child;
      child = parent * 2 + 1;
    }
    else{
      return;
    }
  }
}

void HeapSort(int* array, size_t size){
  if(NULL == array) return;
  size_t parent = (size - 2) >> 1;
  for(; parent > 0; parent--){
    HeapAdjust(array, size, parent);
  }
  size_t end = size - 1;
  while(end > 0){
    swap(&array[0], &array[end]);
    HeapAdjust(array, size, 0);
    --end;
  }
}

int main() {
  
  return 0;
}
