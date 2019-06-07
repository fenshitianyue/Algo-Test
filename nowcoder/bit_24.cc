#include <iostream>
#include <vector>
using namespace std;

inline int Min(int a, int b){
	return a > b ? b : a;
}

int findMinimum(int n, vector<int>& left, vector<int>& right) {
	int count = 0;
	int leftSum = 0, rightSum = 0;
	int leftMin = 27, rightMin = 27;

	for (int i = 0; i != n; i++)
	{
		if (0 == left[i] * right[i]){
			count += (left[i] + right[i]);
			continue;
		}
		leftSum += left[i];
		rightSum += right[i];
		leftMin = Min(leftMin, left[i]);
		rightMin = Min(rightMin, right[i]);
	}
	count += (Min(leftSum - leftMin + 1, rightSum - rightMin + 1));
	return count;
}

int main(){
	vector<int> left{ 0, 7, 1, 6 };
	vector<int> right{ 1, 5, 0, 6 };
	int n = 4;
	cout << findMinimum(n, left, right) << endl;
	return 0;
}
