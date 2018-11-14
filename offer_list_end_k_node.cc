#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL)
            return pListHead;
        unsigned int testNum = 0;
        ListNode* ptr_test = pListHead;
        while(ptr_test){
            ptr_test = ptr_test->next;
            testNum++;
        }
        if(k > testNum){
            return NULL;
        }
        ListNode* ptr_front = pListHead;
        ListNode* ptr_ago = pListHead;
        while(k != 0){
            ptr_front = ptr_front->next;
            k--;
        }
        while(ptr_front){
            ptr_front = ptr_front->next;
            ptr_ago = ptr_ago->next;
        }
        return ptr_ago;
    }
};

int main() {
  
  return 0;
}
