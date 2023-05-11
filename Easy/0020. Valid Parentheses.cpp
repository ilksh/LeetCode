#include<bits/stdc++.h>

using namespace std;


class ValidParentheses {
public:
    bool isValid(string s) {
        stack<char> stk;
        // Iterate all characters in input "s"
        for (char c : s) {
            // current character =  opening parenthesis
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            // current character = closing parenthesis
            else { 
                // no corresponding opening parenthesis
                if (stk.empty()) {
                    return false;
                }

                // checking whether current character matches the top element
                if (c == ')' && stk.top() == '(') {
                    stk.pop();
                } 
                else if (c == '}' && stk.top() == '{') {
                    stk.pop();
                }
                else if (c == ']' && stk.top() == '[') {
                    stk.pop();
                }
                else { 
                    return false;
                }
            }
        }
        // stack is empty > all opening parentheses matches with closing parentheses
        // stack is not empty > all opening parentheses don't match with closing parentheses
        return stk.empty();
    }
};
