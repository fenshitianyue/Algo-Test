///////////////////////////////////////////////////////
// 判断两颗二叉树是否相等
///////////////////////////////////////////////////////

#include <iostream>

typedef struct BiNode{
  struct BiNode* lchild;
  struct BiNode* rchild;
  int elem;
}BiNode, *PTNode;

bool isEqual(PTNode root1, PTNode root2){
  if(NULL == root1 && NULL == root2)
    return true;
  if(NULL == root1 || NULL == root2)
    return false;
  return root1->elem == root2->elem && isEqual(root1->lchild, root2->lchild) && isEqual(root2->rchild, root2->rchild);
}

int main() {
  
  return 0;
}
