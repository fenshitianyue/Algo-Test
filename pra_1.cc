///////////////////////////////////////////////////////
// 叠加一个数字的每一位
// eg:
//  input: 12345
//  output: 15
///////////////////////////////////////////////////////

#include <iostream>

int main() {
  int n = 0;
  int sum = 0;
  while(std::cin >> n){
    sum = 0;
    while(n){
      if(n < 0) n = -n;
      sum += (n % 10);
      n /= 10;
      if(n < 10) break;
    }
    if(n){
      sum += n;
    }
    std::cout<< sum << std::endl;
  }
  return 0;
}
