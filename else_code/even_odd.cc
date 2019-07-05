///////////////////////////////////////////////////////
// 题目描述：
//     把偶数放到数组的偶数位（偶数位要占满），或者把奇数
// 放到数组的奇数位（同上）
///////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void func(vector<int>& arr, int len) {
	if (arr.empty() || len < 2){
		return;
	}
	int odd = 1, even = 0;
	while ((odd <= len - 1) && (even <= len - 1)){
		if (arr[len - 1] % 2){
			swap(arr[len - 1], arr[odd]);
			odd += 2;
		}
		else{
			swap(arr[len - 1], arr[even]);
			even += 2;
		}
	}
}
int main(){
	vector<int> arr{ 1, 2, 3, 4};
	func(arr, arr.size());
	return 0;
}
