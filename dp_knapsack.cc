#include <iostream>
#define N 100
#define MAX(a,b) a < b ? b : a
using namespace std;

struct goods{
  int _sign;//物品序号
  int _wight;//物品重量
  int _value;//物品价值
};

int n,bestValue,cv,cw,C;//物品数量，价值最大，当前价值，当前重量，背包容量
int X[N],cx[N];//最终存储状态，当前存储状态
struct goods goods[N];

int KnapSack(int n,struct goods a[],int C,int x[]){
    int V[N][10*N];
    for(int i = 1; i <= n; i++)
        V[i][0] = 0;
    for(int j = 1; j <= C; j++)
        V[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= C; j++)
          if(j < a[i-1]._wight)
            V[i][j] = V[i-1][j];
          else
            V[i][j] = MAX(V[i-1][j],V[i-1][j-a[i-1]._wight] + a[i-1]._value);

    for(int i = n,j = C; i > 0; i--){
        if(V[i][j] > V[i-1][j]){
            x[i-1] = 1;
            j = j - a[i-1]._wight;
        }
        else
            x[i-1] = 0;
    }
    return V[n][C];
}
int main()
{
    cout << "物品种类n: ";
    cin >> n;
    cout << "背包容量C: ";
    cin >> C;
    for(int i = 0; i < n; i++){
        cout << "物品" << i+1 << "的重量w[" << i+1 << "]及其价值v[" << i+1 << "]：";
        cin >> goods[i]._wight 
            >> goods[i]._value;
    }
    int sum2 = KnapSack(n,goods,C,X);
    cout << "动态规划法求解0/1背包问题:" << endl;
    cout << "X=[ "; 
    for(int i = 0; i < n; i++)
      cout<<X[i]<<" ";//输出所求X[n]矩阵
    cout << "]   装入总价值" << sum2 << endl;
    return 0;
}
