#include <iostream>

class Solution {
public:
     int  NumberOf1(int n) {
         int result = 0;
         while(n != 0){
             n &= (n - 1);
             result++;
         }
         return result;
     }
};

int main() {
  
  return 0;
}
