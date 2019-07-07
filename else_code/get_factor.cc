///////////////////////////////////////////////////////
// 题目描述：
//    获取一个整数的构成因子数。eg: 36 = 2 * 2 * 3 * 3, 
// 所以36的构成因子为2和3，它的构成因子数为2
///////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_prime_number(int n){
	for (int i = 2; i <= sqrt(n); ++i){
		if (!(n % i))
			return false;
	}
	return true;
}

void get_factor(int n, vector<int>& container){
	if (is_prime_number(n)){
		//如果容器中不存在该质数
		if (find(container.begin(), container.end(), n) == container.end())
			container.push_back(n);
		return;
	}
	int i = 2;
	while (i <= sqrt(n)){
		if (!(n % i))
			break;
		++i;
	}
	get_factor(i, container);
	get_factor(n / i, container);
}

int main(){
	int n = 0;
	vector<int> container;
	while (cin >> n){
		get_factor(n, container);
		cout << container.size() << endl;
		container.clear();
	}
	return 0;
}
