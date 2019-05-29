///////////////////////////////////////////////////////
//判断一个字符串数组是否有序，
//  1.如果是按照长度排序有序，那么输出 lengths
//  2.如果是按照字节序排序有序，那么输出 lexicographically
//  3.如果是两个排序方式都有序，那么输出 both
//  4.如果是两个排序方式都无序，那么输出 none
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//思路：
//    拷贝一份字符串数组，对拷贝的字符串数组分别进行两种方式
//  的升序排序和降序排序，然后将排序后的数组和原数组进行元素
//  对比，只要和元素组相同(升序/降序)，那么说明是有序的
//  时间复杂度：0(N)
///////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

bool is_stable_sort(vector<string>& v){
	vector<string> _v(v);
	bool b1 = true;
	bool b2 = true;
	sort(_v.begin(), _v.end(), less<string>());
	for (auto _it = _v.begin(), it = v.begin(); it != v.end(); ++_it, ++it){
		if (*it != *_it){
			b1 = false;
			break;
		}
	}
	sort(_v.begin(), _v.end(), greater<string>());
	for (auto _it = _v.begin(), it = v.begin(); it != v.end(); ++_it, ++it){
		if (*it != *_it){
			b2 = false;
			break;
		}
	}

	return (b1 || b2);
}

bool sort_func_greater(const string& s1, const string& s2){
	return s1.size() > s2.size(); //降序排序
}

bool sort_func_less(const string& s1, const string& s2){
	return s1.size() < s2.size(); //升序排序
}

bool is_sort(vector<string>& v){
	vector<string> _v(v);
	bool b1 = true;
	bool b2 = true;
	sort(_v.begin(), _v.end(), sort_func_greater);
	for (auto _it = _v.begin(), it = v.begin(); it != v.end(); ++_it, ++it){
		if (*it != *_it){
			b1 = false; break;
		}
	}
	sort(_v.begin(), _v.end(), sort_func_less);
	for (auto _it = _v.begin(), it = v.begin(); it != v.end(); ++_it, ++it){
		if (*it != *_it){
			b2 = false; break;
		}
	}
	return (b1 || b2);
}

int main(){
	int n = 0;
	while (cin >> n){
		vector<string> v;
		string s;
		for (int i = 0; i != n; ++i){
			cin >> s;
			v.push_back(s);
		}
		bool b1 = is_stable_sort(v);
		bool b2 = is_sort(v);
		if (b1 && b2){
			cout << "both" << endl;
		}
		else if (b1){
			cout << "lexicographically" << endl;
		}
		else if (b2){
			cout << "lengths" << endl;
		}
		else{
			cout << "none" << endl;
		}
	}
	
	return 0;
}
