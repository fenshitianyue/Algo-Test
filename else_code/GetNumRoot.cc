//返回一个输入数字的“数根”
//“数根定义”
//123的树根：1 + 2 + 3 = 6 
//123456的树根：1 + 2 + 3 + 4 + 5 + 6 = 21 -> 2 + 1 = 3
//输入范围：1-10e1000


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//123456789987654321

string IntToString(int num){
	string re;
	while (num != 0){
		re += ((num % 10) + '0');
		num /= 10;
	}
	reverse(re.begin(), re.end());
	return re;
}

int GetNumRoot(string num){
	int result = 0;
	for (size_t i = 0; i != num.size(); ++i){
		result += (num[i] - '0');
	}
	if (result < 10)
		return result;
	else
		return GetNumRoot(IntToString(result));
}

int main(){
	string num("123");
	string num2("123456");
	int re = GetNumRoot(num);
	re = GetNumRoot(num2);
	return 0;
}
