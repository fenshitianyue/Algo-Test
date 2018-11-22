#include <iostream>
#include <algorithm>
using namespace std;

#define JOB_N 100
#define MACHINE_N 100

int job[JOB_N];
int machine[MACHINE_N];

int main() {
  int n; //作业个数 
  int m; //机器个数
  cout << "输入作业个数:";
  cin >> n; 
  cout << "输入机器个数:";
  cin >> m; 
  for(int i = 0; i < n; ++i){
    cin >> job[i];
  }
  sort(job, job + n, greater<int>());
  for(int i = 0; i < n; ++i){
    *min_element(machine, machine + m) += job[i];
  }
  cout << "花费的最长时间：";
  cout << *max_element(machine, machine + m); 
  return 0;
}
