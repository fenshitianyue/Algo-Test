///////////////////////////////////////////////////////
// 题目描述：
//    输入一个日期的年月日，如果日期正确，输出从这年开始
//到这个日期一共多少天；否则，输出-1
///////////////////////////////////////////////////////



#include <iostream>
using namespace std;

bool is_run_year(int y){
	if ((!(y % 4) && (y % 100)) || !(y % 400))
		return true;
	return false;
}

int date(int y, int m, int d){
	//进行一个基本的判断
	if (y <= 0 || m <= 0 || d <= 0) return -1;
	//记录12个月的天数, 默认为平年
	int year[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//如果是闰年，修改2月的天数为29
	if (is_run_year(y)){
		year[1] = 29;
	}
	//判断月的合法性 和 天的合法性
	if (m > 12 || d > year[m-1]) return -1;
	
	int count = 0;
	for (int i = 0; i != m - 1; ++i){
		count += year[i];
	}
	count += d;
	return count;
}

int main(){
	int y = 0, m = 0, d = 0;
	while (cin >> y >> m >> d){
		cout << date(y, m, d) << endl;
	}
	return 0;
}
