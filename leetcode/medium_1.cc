///////////////////////////////////////////////////////
// 题目描述：
//    给定一个包含n个整数的数组nums，判断nums中是否存在
// 三个元素a,b,c,使得a + b + c = 0。找出所有满足条件且
// 不重复的三元组。
// url:https://leetcode-cn.com/problem/3sum/
///////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> GetThreeNum(vector<int> nums){
  sort(nums.begin(), nums.end()); 
  vector<vector<int>> result_set;
  for(int c = nums.size()-1; c >= 2;){
    for(int a = 0, b = c-1; a < b;){
      int tmp = nums[a] + nums[b];
      if(tmp < -nums[c]){
        ++a;
      }else if(tmp > -nums[c]){
        --b;
      }else{
        vector<int> v{nums[a], nums[b], nums[c]};
        result_set.push_back(v);
        do{
          ++a;
        }while(a < b && nums[a+1] == nums[a]);
        do{
          --b;
        }while(a < b && nums[b-1] == nums[b]);
      }
    }
    do{
      --c;
    }while(c >= 2 && nums[c-1] == nums[c]);
  }
  return result_set;
}

int main() {
   
  return 0;
}
