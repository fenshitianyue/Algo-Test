


#include <iostream>
using namespace std;

int fib_table[36];

void init_table(){
	fib_table[0] = 0;
	fib_table[1] = 1;
	for (int i = 2; i != 36; ++i){
		fib_table[i] = fib_table[i - 1] + fib_table[i - 2];
	}
}

int fib(int n){
	for (int i = 0; i < 36; ++i){
		if (fib_table[i] > n){
			return (fib_table[i] - n < n - fib_table[i-1]) ? fib_table[i] - n : n - fib_table[i-1];
		}
	}
	return -1;
}

int main(){
	init_table();
	int n = 0;
	while (cin >> n){
		cout << fib(n) << endl;
	}
	return 0;
}
