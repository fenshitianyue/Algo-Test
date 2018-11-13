#include <iostream>

class Solutuin{
public:
  inline double Power(double base, int exponent){
    double re = 1.0;
    bool flag = true;
    if(exponent < 0){
      flag = false;
      exponent = -exponent;
    }
    while(exponent--){
      re *= base;
    }
    return flag ? re : 1.0 / re;
  }
};

int main() {
  
  return 0;
}
