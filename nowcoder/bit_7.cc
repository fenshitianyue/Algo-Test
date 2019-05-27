///////////////////////////////////////////////////////
// 网易笔试题
// url: www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId
// 
// 二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。
// 每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
// 对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
// ( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。
//
//输入描述：
//  每组数组包含网格长宽W,H，用空格分隔(1<=W、H<=1000)
//输出描述：
//  输出一个最多可以放的蛋糕数
///////////////////////////////////////////////////////

#include <iostream>
#include <cstring>

int main() {
  int w, h;  
  scanf("%d%d", &w, &h);
  bool mp[1024][1024];
  memset(mp, true, sizeof(mp));
  int count = 0;
  for(int i = 0; i != h; ++i){
    for(int j = 0; j != w; ++j){
      if(mp[i][j]){
        if(i + 2 < h) mp[i+2][j] = false;
        if(j + 2 < w) mp[i][j+2] = false;
        ++count;
      }
    }
  }
  std::cout << count << std::endl;
  return 0;
}

