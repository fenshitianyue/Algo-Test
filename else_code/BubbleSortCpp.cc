#include <iostream>
#include <vector>
#include <algorithm>

void BubbleSort(std::vector<int>& arr) {
  for(std::vector<int>::size_type i = 0; i != arr.size(); ++i) {
    for(std::vector<int>::size_type j = 0; j != (arr.size() - 1 - i); ++j) {
      if(arr[j] > arr[j+1]) {
        std::swap(arr[j], arr[j+1]);
      }
    }
  }
}

void BubbleSortPlus(std::vector<int>& arr) {
  bool flag = false;
  for(std::vector<int>::size_type i = 0; i != arr.size() && !flag; ++i) {
    for(std::vector<int>::size_type j = 0; j != (arr.size() - 1 - i); ++j) {
      if(arr[j] > arr[j+1]) {
        flag = true;
        std::swap(arr[j], arr[j+1]);
      }
    }
  }
}

int main() {
  std::vector<int> arr{3, 1, 2, 6, 9, 7};  
  BubbleSort(arr);
  //BubbleSortPlus(arr);
  return 0;
}
