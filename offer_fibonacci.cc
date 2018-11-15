#include <iostream>

class Solution {
public:
    Solution() {
        table = new int[40];
        table[0] = 0;
        table[1] = 1;
        for(int i = 2; i < 40; ++i){
            table[i] = table[i - 1] + table[i - 2];
        }
    }
    int Fibonacci(int n) {
        if(n <= 39 && n >= 0)
            return table[n];
        return 0;
    }
    ~Solution() {
        delete[] table;
    }
public:
    int *table;
};

int main() {
  
  return 0;
}
