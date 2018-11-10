#include <stdio.h>
#define SIZE(array) ((sizeof(array)) / (sizeof(array[0])))

//assist function
void swap(int* a, int* b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

//increase sequence
void BubbleSort(int *array, int size){
  int flag;
  for(int i = 0; i < size; ++i){
    flag = 0;
    for(int j = 0; j < size - i; ++j){
      if(array[j] > array[j+1]){
        swap(&array[j], &array[j+1]);
        flag = 1;
      }
    }//end for(j)
    if(!flag) break;
  }//end for(i)
}//end func

//test
int main() {
  int arr[] = {1, 3, 9, 10, 101, -1}; 
  printf("not sort array:\n"); 
  for(size_t i = 0; i < SIZE(arr); ++i){
    printf("%d ", arr[i]);
  }
  BubbleSort(arr, SIZE(arr));
  printf("\nalready sort array:\n"); 
  for(size_t i = 0; i < SIZE(arr); ++i){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
