///////////////////////////////////////////////////////
// 题目描述：
// 将输入的正整数分解为素数的乘积
// eg:
// 4 = 2 * 2
// 18 = 2 * 3 * 3
///////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//method1
bool is_prime(int n){
	for (int i = 2; i <= sqrt(n); ++i){
		if (!(n % i))
			return false;
	}
	return true;
}

void func(int n, vector<int>& ve){
	if (is_prime(n)){ //如果是素数
		ve.push_back(n);
		return;
	}
	int i = 2;
	while (i <= sqrt(n)){
		if (!(n % i))
			break;
		++i;
	}
	func(i, ve);
	func(n / i, ve);
}

int main(){
	vector<int> ve;
	int n;
	while (cin >> n){
		func(n, ve);
		cout << n << " = ";
		for (auto it = ve.begin(); it != ve.end(); ++it){
			if ((it + 1) != ve.end()){
				cout << *it << " * ";
			}
			else{
				cout << *it << endl;
			}
		}
		ve.clear();
	}
	return 0;
}

//method2

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main(){
//  int n;
//  while(cin >> n){
//    cout << n << " =";
//    for(int i = 2; i <= sqrt(n); ++i){
//      while(i != n){
//        if(!(n % i)){
//          cout << " " << i << " *";
//          n /= i;
//        }else 
//          break;
//      }
//    }
//    cout << " " << n << endl;
//  }
//  return 0;
//}
