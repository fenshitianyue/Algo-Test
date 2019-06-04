#include <iostream>
#include <vector>
using namespace std;

inline int Min(int n, int m){
	return n > m ? m : n;
}

int main(){
	int n, m;
	while (cin >> n >> m){
		vector<int> v(m + 1, 100001);
		v[n] = 0;
		for (int i = n; i <= m; ++i){
			if (v[i] == 100001){
				continue;
			}
			for (int j = 2; (j * j) <= i; ++j){
				if (0 == i % j){
					//设置第一个约数的步数
					if (i + j <= m){
						v[i + j] = Min(v[i] + 1, v[i + j]);
					}
					//设置第二个约数的步数
					if (i + (i / j) <= m){
						v[i + (i / j)] = Min(v[i] + 1, v[i + (i / j)]);
					}

				}

			}
		}
		if (100001 == v[m]){
			v[m] = -1;
		}
		cout << v[m] << endl;
	}
	return 0;
}
