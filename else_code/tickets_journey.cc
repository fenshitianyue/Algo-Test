///////////////////////////////////////////////////////
//题目描述：
// 给定一趟旅途中的车票信息，根据这些找出旅途的路线
// eg: (西安，重庆), (北京，西安)
// path：北京->西安->重庆
///////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <string>

using namespace std;

void PrintPath(map<string, string>& tickets);

int main() {
  map<string, string> tickets;
  tickets.insert({"西安", "重庆"});
  tickets.insert({"北京", "西安"});
  PrintPath(tickets); 
  return 0;
}

void PrintPath(map<string, string>& tickets){
  //逆转程票的始末城市
  map<string, string> r_tickets;
  map<string, string>::iterator it;
  for(it = tickets.begin(); it != tickets.end(); ++it){
    r_tickets[it->second] = it->first; 
  }
  //找出第一个旅途的出发点城市
  string begin;
  for(it = tickets.begin(); it != tickets.end(); ++it){
    if(r_tickets.find(it->first) == r_tickets.end()){
      begin = it->first; 
      break;
    }
  } 
  //从开始城市开始顺腾摸瓜往下找
  it = tickets.find(begin); 
  while(it != tickets.end()){
    cout << it->first << "->" << it->second;
    it = tickets.find(it->second);
    if(it != tickets.end()) 
      cout << ", ";
  }
  cout << endl;
 
}


