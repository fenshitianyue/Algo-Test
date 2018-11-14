#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> pos;
        if(head != NULL){
            deque<int> result;
            while(head != NULL){
                result.push_front(head->val);
                head = head->next;
            }
            copy(result.begin(), result.end(), back_inserter(pos));
            return pos;
        }
        return pos;
    }
};

int main() {
  
  return 0;
}
