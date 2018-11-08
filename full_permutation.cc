#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using string_list = std::vector<std::string>;
using index_t = std::string::size_type;

class full_permutation{
public:
  string_list Permutation(std::string s){
    string_list ve;
    if(s.size() <= 0) return ve;
    Result(ve, s, 0);
    //std::sort(ve.begin(), ve.end());
    std::unique(ve.begin(), ve.end());
    return ve;
  } 
  void Result(string_list& ve, std::string str, index_t index){
    if(index == str.size() - 1){
      ve.push_back(str); 
    }
    for(index_t i = index; i <= str.size() - 1; ++i){
      if(i != index && str[i] == str[index]){
        continue;
      }
      std::swap(str[i], str[index]);
      Result(ve, str, index + 1);
      std::swap(str[i], str[index]);
    }
  }
};

//test
int main(){
  full_permutation re;
  string_list result = re.Permutation("abc");
  for(const auto& it : result){
    std::cout << it << std::endl;
  }
  //for(std::vector<std::string>::size_type i = 0; i < result.size(); ++i){
  //  std::cout << result[i] << std::endl;  
  //}
  return 0;
}
