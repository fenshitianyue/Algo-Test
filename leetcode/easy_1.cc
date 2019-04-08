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
  int j = distance(result_2, nums.rend() - 1);
  vector<int> result(i, j);
  return result;
}


//method 2
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// 
// vector<int> twoSum(vector<int>& nums, const int target){
//   vector<int> result;
//   for(vector<int>::size_type i = 0; i < nums.size(); ++i){
//     int num2 = target - nums[i];
//     int j = 0;
//     vector<int>::iterator pos = find(nums.begin(), nums.end(), num2);
//     if((pos != nums.end()) && (j = distance(nums.begin(), pos)) != static_cast<int>(i)){
//       cout << i << " " << j << endl;
//       result.push_back(i);
//       result.push_back(j);
//       return result;
//     }
//   } 
//   return result;
// }
// 

//test case
int main(){

}
