#include <iostream>
#include <vector>
using namespace std;

//最大子序列和

int _max(int a, int b){
  return a > b ? a : b;
}

int maxNum(vector<int>& nums){
  int res = nums[0];
  int sum = 0;
  for(int n : nums){
    if(sum > 0)
      sum += n;
    else 
      sum = n;
    res = _max(res, sum);
  }
  return res;
}

//test case
int main() {
  
  return 0;
}

