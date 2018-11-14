#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = 0;
        int j = array[0].size() - 1;
        while(j >= 0 && i < array[0].size()){
            if(array[i][j] > target){
                j--;
            }else if(array[i][j] == target || array[i][0] == target){
                return true;
            }else if(array[i][0] < target){
                i++;
            }
        }
        return false;
    }
};

int main(){

  return 0;
}
