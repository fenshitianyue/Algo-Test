#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void reverse(int num){
  int nums[32] = {0};
  for(int i = 0; num != 0; ++i){
    nums[i] = num % 10;
    num /= 10;
  }
  int result = 0;
  //5 4 3 2 1 0 0 ...
  //12000  //not ok
  //0 0 0 2 1 0 0 ...
  //12010  //not ok
  //0 1 0 2 1 0 0 ...
  int *pos = find(nums, nums + 32, 0);
  for(int i = pos-nums-1, j = 0; i >= 0; --i, ++j){
    result += (nums[j] * pow(10, i));
  }
  cout << result << endl;
}

//test case
int main(int argc, char* argv[]) {
  int num = atoi(argv[1]);
  reverse(num);
  return 0;
}
