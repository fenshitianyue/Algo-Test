//判断字符串是否为合法的括号串
//url:www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId/ 

#include <string>
#include <stack>
using namespace std;

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> s;
        for(auto it : A){
            switch(it){
                case '(':
                    s.push(it); break;
                case ')':
                    if(s.empty() || s.top() != '(')
                        return false;
                    else
                        s.pop();
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
};

