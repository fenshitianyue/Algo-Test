#include <iostream>

class Solution {
public:
    int jumpFloorII(int number) {
        if(0 == number){
            return 0;
        }
        if(1 == number){
            return 1;
        }
        return tools(number - 1);
    }
    int tools(int number){
        int re = 1;
        while(number--){
            re *= 2;
        }
        return re;
    }
};

int main(){

  return 0;
}
