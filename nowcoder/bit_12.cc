///////////////////////////////////////////////////////
// 给定一个十进制数M，以及需要转换的进制N，将十进制数M
// 转换成N进制数
///////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main() {
  std::string s = "";
	std::string tools = "0123456789ABCDEF";
	int M = 0;
	std::cin >> M;
	int N = 0;
	std::cin >> N;
	if (0 == M){
		s = "0";
	}
	else if (M < 0){
		M = -M;
		std::cout << "-";
	}
	while (M){
		s = tools[M % N] + s;
		M /= N;
	}
	std::cout << s << std::endl;
  return 0;
}
