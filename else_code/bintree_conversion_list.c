///////////////////////////////////////////////////////
// 将二叉树转换成双向链表
///////////////////////////////////////////////////////

#include <stdio.h>

typedef struct BiNode{
  struct BiNode* lchild;
  struct BiNode* rchild;
  int elem;
}BiNode, *PTNode;

PTNode pHead = NULL;
PTNode pEnd = NULL;

void inorder_bsTree(PTNode root){
  if(NULL == root) return;
  inorder_bsTree(root->lchild);
  root->lchild = pEnd;
  if(NULL == pEnd) 
    pHead = root;
  else 
    pEnd->lchild = root;
  pEnd = root;
  inorder_bsTree(root->rchild);
}

int main() {
  
  return 0;
}


