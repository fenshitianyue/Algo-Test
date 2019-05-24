///////////////////////////////////////////////////////
// 找出整数集合中子序列的最大和
///////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

inline int _max(int a, int b){
  return a > b ? a : b;
}

int maxSubArray(vector<int>& nums){
  int max = nums[0];
  int tmp = 0;
  for(int num : nums){
    if(tmp > 0){
      tmp += num;
    }else{
      tmp = num;
    }
    max = _max(tmp, max);
  }
  return max;
}

void case_1(vector<int>& v){
  cout << maxSubArray(v);
}

int main(){
  int n = 0;
  cin >> n;
  vector<int> v;
  int tmp;
  for(int i = 0; i != n; ++i){
    cin >> tmp;
    v.push_back(tmp);
  }
  case_1(v);
  return 0;
}
