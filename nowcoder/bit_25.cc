///////////////////////////////////////////////////////
// 题目描述：
//    输入一个整数n， 计算n以内（包含n）的数中完全数的个数
//    完全数：自己所有的约数（除了本身外）加起来等于自己的数
//    eg: 28 -> 1 + 4 + 7 + 14 + 2 = 28
//    
// 输出输出示例：
//    input:
//          1000
//    output:
//          3
///////////////////////////////////////////////////////


#include <iostream>
#include <cmath>
using namespace std;

//method1
bool is_com(int n){
	int sum = 0;
	//计算除本身以外的约数的和
	for (int i = 1; i < n; ++i){
		if (0 == n % i)
			sum += i;
	}
	return (sum == n);
}

int count1(int n){
	int cnt = 0;
	for (int i = 1; i <= n; ++i){
		if (is_com(i))
			++cnt;
	}
	return cnt;
}

//method2
int count2(int n){
  int cnt = 0;
  if(n < 0 || n > 500000)
    return -1;
  for(int i = 2; i <= n; ++i){
    int sum = 0;
    int sq = sqrt(n);
    for(int j = 2; j <= sq; ++j){
      if(0 == i % j){ //保证i比j大，这样就不会把约数加两遍
        if(j == i / j)
          sum += j;
        else 
          sum += j + (i / j);
      }
    }
    if(sum + 1 == i){
      ++cnt;
    }
    return cnt;
  }
  return -1;
}

int main(){
	int n = 0;
	while (cin >> n){
		cout << count1(n) << endl;
	}
	return 0;
}
