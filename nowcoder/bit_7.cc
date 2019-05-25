
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
