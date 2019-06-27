
///////////////////////////////////////////////////////
// 找出二叉树最大的子树和
///////////////////////////////////////////////////////

#include <stdio.h>

typedef struct BiNode{
  struct BiNode* lchild;
  struct BiNode* rchild;
  int elem;
}BiNode, *PTNode;

int FindMaxSubTree(PTNode root, int* maxSum, PTNode* maxRoot){
  if(NULL == root) 
    return 0;
  int lmax = FindMaxSubTree(root->lchild, maxSum, maxRoot);
  int rmax = FindMaxSubTree(root->rchild, maxSum, maxRoot);
  int sum = lmax + rmax + root->elem;
  if(sum > *maxSum){
    *maxSum = sum;
    *maxRoot = root;
  }
  return sum;
}

int main() {
  
  return 0;
}



