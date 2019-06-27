///////////////////////////////////////////////////////
//题目：
// 对于一颗给定的二叉搜索树，求两个指定节点的最近公共父节点
///////////////////////////////////////////////////////

#include <iostream>
#include <stack>
using namespace std;

typedef struct BiNode{
  struct BiNode* lchild;
  struct BiNode* rchild;
  int elem;
}BiNode, *PTNode;

//方法1：
//分别找出从根节点到这两个节点的路径，然后从逆向从路径中比对
//第一个相同的节点，即这两个节点的最近公共父节点

////  获取路径的方法1：
// bool GetPathFromRoot(PTNode root, PTNode node, stack<PTNode>& s){
//   if(NULL == root)
//     return false;
//   if(node->elem == root->elem){
//     s.push(root);
//     return true;
//   }
//   //如果node节点在root节点的左子树或者右子树上，那么root就是node的祖先节点，把它添加到路径中
//   if(GetPathFromRoot(root->lchild, node, s) || GetPathFromRoot(root->rchild, node, s)){
//     s.push(root);
//     return true;
//   }
//   return false;
// }

//   获取路径的方法2
bool GetPathFromRoot(PTNode root, PTNode node, stack<PTNode>& s){
  if(NULL == root || NULL == node) 
    return false;
  //如果node中元素小于二叉搜索树遍历到的当前节点元素，并且也不在当前节点的右子树，则返回false
  if(node->elem > root->elem && !GetPathFromRoot(root->rchild, node, s)){
    return false; 
  }
  //如果node中元素大于二叉搜索树遍历到的当前节点元素，并且也不在当前节点的左子树，则返回false
  else if(node->elem < root->elem && !GetPathFromRoot(root->lchild, node, s)){ 
    return false; 
  }
  s.push(root);
  return true;
}

PTNode FindParentNode(PTNode root, PTNode node1, PTNode node2){
  stack<PTNode> s1;
  stack<PTNode> s2;
  if(GetPathFromRoot(root, node1, s1) || GetPathFromRoot(root, node2, s2)){
    return NULL;
  }
  PTNode comment = NULL;
  while(s1.top() == s2.top()){
    comment = s1.top();
    s1.pop();
    s2.pop();
  }
  return comment;
}


//方法2：
//可以把问题转换成这样：找到一个节点node，是的node1和node2分别在node的左子树和
//右子树中。

// PTNode FindParentNode(PTNode root, PTNode node1, PTNode node2){
//   if(NULL == node1 || root == node2 || root == node1) 
//     return NULL;
//   PTNode lchild = FindParentNode(root->lchild, node1, node2);
//   PTNode rchild = FindParentNode(root->rchild, node1, node2);
//   //root的左子树上没有节点node1和node2，那么一定node一定存在于右子树上
//   if(NULL == lchild) 
//     return rchild;
//   //root的右子树上没有节点node1和node2，那么一定node一定存在于左子树上
//   else if(NULL == rchild) 
//     return lchild;
//   //否则说明root就是要找的node
//   else 
//     return root;
// }

//test case
int main() {
  
  return 0;
}
