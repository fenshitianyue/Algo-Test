#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        //The first stack is push stack
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int result = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
  
  return 0;
}
