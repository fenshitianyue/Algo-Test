#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MoveOddsBeforeEvens_method1(vector<int>& vec){
	partition(vec.begin(), vec.end(), [](int x){ return (x % 2 != 0); });
	for_each(vec.begin(), vec.end(), [](int n) { cout << n << " "; });
	cout << endl;
}

void MoveOddsBeforeEvens_method2(vector<int>& vec){
	stable_partition(vec.begin(), vec.end(), [](int x){ return (x % 2 != 0); });
	for_each(vec.begin(), vec.end(), [](int n) { cout << n << " "; });
	cout << endl;
}

int main(){
	vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	MoveOddsBeforeEvens_method1(vec);
	return 0;
}