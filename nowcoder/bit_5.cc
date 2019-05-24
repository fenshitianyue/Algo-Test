//找出n个数里出现次数大于等于n/2的数

//case 1:
//对数组排序，然后找出中间那个数

//case 2:
//因为要找过半的数，用一个变量count记录读取每个变量变化的次数，一个变量temp记录可能过
//半的数，先让count=1，然后让temp=vec[0]，然后往后遍历一遍，碰到和temp相同的数就给count++，否
//则就count--，如果，count变成0，就让temp=vec[i](vec数组遍历过程中的当前值),并让count=1，如此遍历
//一遍，因为有一个数过半，所以temp最后肯定存储的是过半的数

//case 3:
//看代码应该直接就能看懂思路

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void case_1(vector<int>& v){
  sort(v.begin(), v.end());
  cout << v[(v.size() >> 1) - 1];
}

void case_2(vector<int>& v){
  int count = 1;
  int tmp = v[0];
  for(size_t i = 1; i != v.size(); ++i){
    if(v[i] == tmp)
      ++count;
    else 
      --count;
    if(0 == count){
      tmp = v[i];
      ++count;
    }
  }
  cout << tmp << endl;
}

void case_3(vector<int>& v){
  int tmp = 0;
  unordered_map<int, int> m;
  while(cin>>tmp){
    auto key = m.find(tmp);
    if(key != m.end()){
      ++key->second;
    }else{
      m.insert({tmp, 1});
    }
  }
  int size_2 = m.size() >> 1;
  for(const auto& it: m){
    if(it.second > size_2){
      cout << it.first;
      break;
    }
  }
}


int main() {
  int n = 0;
  vector<int> v;
  while(cin >> n){
    v.push_back(n);
  } 
  //case_1(v);
  return 0;
}
