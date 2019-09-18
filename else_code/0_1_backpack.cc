#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m; // n表示物品的个数，m表示背包的容量
int f[N][N]; // 1010 * 1010 * 4 / 1024 / 1024 ~> 4M
int v[N], w[N]; // v表示每个物品的体积，w表示每个物品的价值

int main() {
  cin >> n >> m; 
  for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
  
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j <= m; ++j) {
      f[i][j] = f[i-1][j];
      if(j >= v[i]) {
        f[i][j] = max(f[i][j], f[i-1][j - v[i]] + w[i]);
      }
    }
  }

  int res = 0;
  for(int i = 0; i <= m; ++i) res = max(res, f[n][i]);
  cout << res << endl;
  return 0;
}
