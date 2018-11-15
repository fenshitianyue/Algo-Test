#include <iostream>
#include <deque>

struct ListNode {
	int val;
    ListNode() :
              val(0), next(NULL){
              }
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL){
            return pHead;
        }
        deque<int> tmp;
       // int num = 0;
        while(pHead != NULL){
            tmp.push_front(pHead->val);
            pHead = pHead->next;
         //   num++;
        }
        ListNode* newHead;
        newHead = new ListNode(tmp.front());
        tmp.pop_front();
        ListNode* ptr = newHead;
        while(!tmp.empty()){
            newHead->next = new ListNode(tmp.front());
            newHead = newHead->next;
            tmp.pop_front();
        }
        return ptr;
    }
};

int main() {
  
  return 0;
}
