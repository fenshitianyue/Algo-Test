#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(NULL == root){
            return result;
        }else{
            deque<TreeNode*> queue;
            queue.push_back(root);
            while(!queue.empty()){
                auto* node = queue.front();
                result.push_back(node->val);
                queue.pop_front();
                if(node->left != NULL){
                    queue.push_back(node->left);
                }
                if(node->right != NULL){
                    queue.push_back(node->right);
                }
            }
        }
        return result;
    }
};

int main() {
  
  return 0;
}
