#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;


int main() {
  int elements[] = {1, 2, 3, 4};  
  const size_t size = sizeof(elements) / sizeof(elements[0]);
  vector<int> vec(elements, elements + size);
  int cnt = 0;
  do{
    cout << ++cnt << ": ";
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
    //上面那行代码作用等价于这行：for_each(vec.begin(), vec.end(), [](const int n){cout << n << " ";});
    cout << endl;
  }while(next_permutation(vec.begin(), vec.end()));
  return 0;
}
