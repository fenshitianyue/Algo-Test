//url:www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue
///////////////////////////////////////////////////////
// 情况1：
//       3
//    2     2  2  
// 1              1
// 情况2：
//    3   3
//      2
// 1
// 这种情况波峰和波谷数目加一起有3个，但是要注意，一个子序列至少要包含2个数，所以
// 这种情况只能算2个有序子序列，而不是3个
///////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 0;
  cin >> n;
  vector<int> sets;
  sets.resize(n);
  int tmp = 0;
  for(int i = 0; i != n; ++i){
    cin >> tmp;
    sets.push_back(tmp);
  }
  int ret = 1;
  for(int i = 1; i != n-1; ++i){
    if((sets[i-1] < sets[i] && sets[i] > sets[i+1]) || (sets[i-1] > sets[i] && sets[i] < sets[i+1])){
      ret++;
      if(i != n - 3)
        ++i;
    }
  }
  cout << ret << endl;
  return 0;
}

