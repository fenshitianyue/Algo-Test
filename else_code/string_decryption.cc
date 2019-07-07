///////////////////////////////////////////////////////
// 输入密文，输出明文
// 加密规则：所有大写字符，转换为它后面的第5个字母（26个字母循环）
///////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;

void decryption(string& s){
	for (auto it = s.begin(); it != s.end(); ++it){
		if (!isupper(*it))
			continue;
		*it = (*it - 44) % 26 + 65; // (*it - 'A' + 26 - 5) % 26 +'A'
	}
}

int main(){
	string s;
	while (getline(cin, s)){
		decryption(s);
		cout << s.data() << endl;
		s.clear();
	}
	return 0;
}
