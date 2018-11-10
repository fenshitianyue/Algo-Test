#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(array) ((sizeof(array)) / (sizeof(array[0])))


void CountSort(int *array, size_t size){
  int max_index = array[0]; 
  int min_index = array[0]; 
  int* tmp = NULL;
  //calc assist space length
  for(size_t i = 1; i < size; ++i){
    if(max_index < array[i]) max_index = array[i];
    if(min_index > array[i]) min_index = array[i];
  }
  int space_size = max_index - min_index + 1;
  tmp = (int*)calloc(size, sizeof(int) * space_size);
  //tmp = (int*)malloc(sizeof(int) * space_size);
  //memset(tmp, 0, sizeof(int) * space_size);
  if(NULL == tmp) return;
  //statistics data
  for(size_t i = 0; i < size; ++i){
    tmp[array[i] - min_index]++;
  } 
  int index = 0;
  //collect data 
  for(int i = 0; i < space_size; ++i){
    while(tmp[i]--){
      array[index++] = i + min_index;
    }
  }//end for(int)
}//end func

//test
int main() {
  int arr[] = {1, -1, 0, 100, -200, 129};  
  printf("not sort array:\n"); 
  for(size_t i = 0; i < SIZE(arr); ++i){
    printf("%d ", arr[i]);
  }
  CountSort(arr, SIZE(arr));
  printf("\nalready sort array:\n"); 
  for(size_t i = 0; i < SIZE(arr); ++i){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
