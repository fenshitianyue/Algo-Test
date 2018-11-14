#include <iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str != NULL){
            int spaceNum = 0;
        //calculation space number
            for(int i = 0; i < length; ++i){
                if(isspace(str[i])){
                    spaceNum++;
                }
            }
        //this pointer point str new end
            char *freshArr = str + length - 1 + spaceNum * 2;
            for(int i = length - 1; i >= 0 && freshArr > str + i; --i){
                if(isspace(str[i])){
                    *freshArr-- = '0';
                    *freshArr-- = '2';
                    *freshArr-- = '%';
                }else{
                    *freshArr-- = str[i];
                }
                
            }    
        }
	}
};

int main() {
  
  return 0;
}
