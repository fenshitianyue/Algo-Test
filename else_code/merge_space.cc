#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void RemoveContinuousSpace(string& str){
	string::iterator last = unique(str.begin(), str.end(),
		[](char x, char y){return ' ' == x && ' ' == y; });
	str.erase(last, str.end());
}

int main(){
	string s;
	while (getline(cin, s)){
		RemoveContinuousSpace(s);
		cout << s.data() << endl;
		s.clear();
	}
	return 0;
}
