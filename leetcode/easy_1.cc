// questin url
// https://leetcode-cn.com/problems/two-sum/ector<int> result(first, second + 1);

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, const int target){
  sort(nums.begin(), nums.end());
  vector<int>::iterator first = nums.begin();
  vector<int>::iterator second = nums.end();
  while(first != second){
    if(*first + *second == target){
      break;
    }else if(*first + *second < target){
      ++first;
    }else{
      --second;
    }
  }
  vector<int>::iterator result_1 = find(nums.begin(), nums.end(), *first);
  int i = distance(nums.begin(), result_1);
  vector<int>::reverse_iterator result_2 = find(nums.rbegin(), nums.rend(), *second);
  int j = -distance(nums.rend() - 1, result_2);
  vector<int> result(i, j);
  return result;
}

//test case
int main(){

}
