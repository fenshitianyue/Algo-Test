#include <iostream>
using namespace std;

int find_count(int n){
  if(1 == n)
    return 0;
	if (n <= 3)
		return 1;
	if (!(n % 3)){ //能分成相同的三组
		return 1 + find_count(n / 3);
	}
	else{ //不能分成相同的三组
		return 1 + find_count(n / 3 + 1);
	}
}

//循环版本的find_count
int _find_count(int n){
  int cnt = 0;
  while(n > 1){
    if(n % 3)
      n = n / 3 +1;
    else 
      n /= 3;
    ++cnt;
  }
  return cnt;
}

int main(){
	int n = 0;
	while (cin >> n){
		if (!n)
			return 0;
		cout << find_count(n) << endl;
	}
	return 0;
}
