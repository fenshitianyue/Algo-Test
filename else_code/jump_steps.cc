#include <iostream>
using namespace std;

int jump_steps(int n){
  if(n <= 1)
    return 1;
  return jump_steps(n - 1) + jump_steps(n - 2);
}

int main() {
  int n = 0;
  while(cin >> n){
    cout << jump_steps(n) << endl;
  }
  return 0;
}
