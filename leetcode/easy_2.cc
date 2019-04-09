#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int reverse(int num){
  int result = 0;
  while(num != 0){
    int n = num % 10;
    num /= 10;
    if(result > INT32_MAX / 10 || (result == INT32_MAX / 10 && n > 7)){
      return 0;
    }
    if(result < INT32_MIN / 10 || (result == INT32_MIN / 10 && n < -8)){
      return 0;
    }
    result = result * 10 + n;
  }
  return result;
}

void reverse_old(int num){
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
//get input from the command line
int main(int argc, char* argv[]) {
  int num = atoi(argv[1]);
  int result = reverse(num);
  cout << result << endl;
  return 0;
}
