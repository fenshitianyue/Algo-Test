#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void passwd_level(string& s){
	int count = 0;
	//密码长度
	if (s.size() <= 4){
		count += 5;
	}
	else if (s.size() <= 7){
		count += 10;
	}
	else
		count += 25;
	//字母
	bool had_lower = false;
	bool had_upper = false;
	for (auto it : s){
		//判断小写
		if (islower(it)){
			had_lower = true;
		}
		//判断大写
		if (isupper(it)){
			had_upper = true;
		}
	}
	if (had_lower && had_upper){
		count += 20;
	}
	else if (had_lower || had_upper){
		count += 10;
	}
	//数字
	bool flag = false;
	for (auto it : s){
		if (isdigit(it) && !flag){
			count += 10;
			flag = true;
		}
		else if (isdigit(it) && flag){
			count += 10;
			break;
		}
	}
	//符号
	//HAVE BUG
	bool ch = false;
	for (auto it : s){
		if (((it >= 0x21 && it <= 0x2F) || (it >= 0x5B && it <= 0x60) || (it >= 0x3A && it <= 0x40) || (it >= 0x7B && it <= 0x7E)) && !ch){
			ch = true;
			count += 10;
		}
		else if (((it >= 0x21 && it <= 0x2F) || (it >= 0x5B && it <= 0x60) || (it >= 0x3A && it <= 0x40) || (it >= 0x7B && it <= 0x7E)) && ch){
			count += 10;
			break;
		}
	}
	//奖励
	if (had_lower && had_upper && flag && ch){
		count += 5;
	}
	else if ((had_lower || had_upper) && flag && ch){
		count += 3;
	}
	else if ((had_lower || had_upper) && flag ){
		count += 2;
	}
	//输出评级
	if (count >= 90){
		cout << "VERY_SECURE" << endl;
	}
	else if(count >= 80){
		cout << "SECURE" << endl;
	}
	else if(count >= 70){
		cout << "VERY_STRONG" << endl;
	}
	else if(count >= 60){
		cout << "STRONG" << endl;
	}
	else if(count >= 50){
		cout << "AVERAGE" << endl;
	}
	else if (count >= 25){
		cout << "WEAK" << endl;
	}
	else{
		cout << "VERY_WEAK" << endl;
	}
}

int main() {
	string s;
	while (cin >> s){
		passwd_level(s);
		s.clear();
	}
	return 0;
}
