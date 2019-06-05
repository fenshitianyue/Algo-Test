#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int method(vector<int>& v, size_t target, long sum, long multi)
{
	int count = 0;
	for (size_t i = target; i != v.size(); ++i)
	{
		sum += v[i];
		multi *= v[i];
		//深度延深
		if (sum > multi)
			count += 1 + method(v, i + 1, sum, multi);
		else if (1 == v[i])
			count += method(v, i + 1, sum, multi);
		else
			break;
		//广度延深
		sum = sum - v[i];
		multi = multi / v[i];
		for (; i < v.size() - 1 && v[i] == v[i + 1]; i++);
	}
	return count;
}
int main()
{
	vector<int> v;
	int n = 0;
	while (cin >> n)
	{
		int tmp = 0;
		for (int i = 0; i != n; i++){
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		cout << method(v, 0, 0, 1);
	}
	return 0;
}
