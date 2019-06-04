#include <iostream>
using namespace std;

inline int Max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int n = 0;
	while (cin >> n){
    int tmp = 0;
    int count = 0;
		while (n){
			if (n & 1){ ++tmp; }
			else{
				count = Max(count, tmp);
				tmp = 0;
			}
			n >>= 1;
		}
		cout << count << endl;
	}
	return 0;
}
