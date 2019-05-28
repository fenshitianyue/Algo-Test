//求两个数的最小公倍数

#include <iostream>
using namespace std;

int func(int a, int b){
	int max = a > b ? a : b;
	int min = a < b ? a : b;
	while (max % min != 0){
		max += (min == a ? b : a);
	}
	return max;
}
int main(){
	int a = 0, b = 0;
	while (cin >> a >> b){
		cout << func(a, b) << endl;
	}
	return 0;
}
