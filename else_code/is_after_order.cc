///////////////////////////////////////////////////////
// 判断数组中元素是否为二叉搜索树的后续遍历结果
// 
// 思路：
//  二叉查找树的特点是，左子树内的元素小于根节点的元素，
//右子树内的元素大于根节点的元素  
//  而后续遍历的最后一个节点是根节点，在数组中找出第一个
//大于根节点元素的元素位置，这个位置之前的元素都是左子树
//上的，后面的位置都是右子树上的，递归这个过程
///////////////////////////////////////////////////////
#include <iostream>

typedef struct BiNode{
  struct BiNode* lchild;
  struct BiNode* rchild;
  int elem;
}BiNode, *PTNode;


///////////////////////////////////////////////////////
// @param:arr -> 待判断的数组
// @param:n -> 数组元素
///////////////////////////////////////////////////////

bool IsAfterOrder(int* arr, int n){
  if(NULL == arr || n <= 0) 
    return false;
  int root = arr[n - 1];
  int i = 0, j = 0;
  while(i < n){
    if(arr[i++] > root) 
      break;
  }
  for(j = i; j < n; ++j){
    if(arr[j] > root)
      return false;
  }
  bool left_is = true;
  bool right_is = true;

  return (left_is && right_is);
}

int main() {
  
  return 0;
}

