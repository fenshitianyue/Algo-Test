//max Top N


#include <iostream>
#include <vector>
using namespace std;

class TopN{
public:
	void FindTopN(size_t n, vector<int>& data){
		//用前n个数建一个小顶堆
		BuildHeap(n, data);
		//用第n个值后面的数据调整堆
		for (size_t i = n; i != data.size(); ++i){
			adjust(i, n, data);
		}
	}
	void PrintN(vector<int>& data){
		for (size_t i = 0; i != data.size(); ++i){
			cout << data[i] << " ";
		}
		cout << endl;
	}
private:
	size_t parent(size_t n){
		return (n - 1) >> 1;
	}
	size_t left_child(size_t n){
		return (n << 1) + 1;
	}
	size_t right_child(size_t n){
		return (n << 1) + 2;
	}
	void swap(int& a, int& b){
		a ^= b;
		b ^= a;
		a ^= b;
	}
	//创建一个小顶堆
	void BuildHeap(size_t n, vector<int>& data){
		for (size_t i = 1; i != n; ++i){
			size_t index = i;
			//调整堆，保证小顶堆的特性(父节点比左右孩子节点都小)
			while (index != 0 && data[parent(index)] > data[index]){
				swap(data[index], data[parent(index)]);
	            //重新设置当前节点的父节点为当前节点,继续向上重复这个过程
				index = parent(index); 
			}
		}
	}
	void adjust(size_t i, size_t n, vector<int>& data){
		if (data[i] <= data[0]) return;
		//置换堆顶
		swap(data[i], data[0]);
		//调整堆
		size_t index = 0;
		while ((left_child(index) < n && data[index] > data[left_child(index)]) ||
			   (right_child(index) < n && data[index] > data[right_child(index)])){
			if (right_child(index) < n && data[right_child(index)] < data[left_child(index)]){
				swap(data[index], data[right_child(index)]);
				index = right_child(index);
			}
			else{
				swap(data[index], data[left_child(index)]);
				index = left_child(index);
			}
		}
	}
};

int main(){
	TopN t;
	vector<int> v{ 56, 30, 71, 18, 29, 93, 44, 75, 20, 65, 68, 34 };
	cout << "原数组：";
	t.PrintN(v);
	t.FindTopN(5, v);
	cout << "调整后数组：";
	t.PrintN(v);
	cout << endl;
	return 0;
}
