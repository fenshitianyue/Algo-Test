#include <iostream>

class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 1){
            return number;
        }
        int num1 = 0, num2 = 1;
        int result = 0;
        for(int i = 1; i <= number; ++i){
            result = num1 + num2;
            num1 = num2;
            num2 = result;
        }
        return result;
    }
};

int main(){

  return 0;
}
