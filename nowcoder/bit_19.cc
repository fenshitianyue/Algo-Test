
#include <iostream>
#include <string>
using namespace std;

int main(){
	string r;
	string s;
	int flag = 0;
	int count = 0;
	while (getline(cin, s)){
		for (size_t i = 0; i != s.size(); ++i){
			if (s[i] == '\"'){
				++flag;
				continue;
			}
			if (s[i] != ' '){
				r += s[i];
			}
			else if (0 == flag % 2){
				r += string("\n");
				++count;
			}
			else{
				r += s[i];
			}
		}
		cout << count + 1 << endl;
		cout << r << endl;
		r.clear();
		s.clear();
	}
	return 0;
}
