#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
private:
    stack<int> calc(stack<int>* s) {
        stack<int> rst;
        bool carry = false;
        while (!s->empty()) {
            int cur = s->top(); s->pop();
            cur *= 2;
            if (carry) cur += 1;
            
            if (cur >= 10) {
                carry = true;
                cur %= 10;
            }
            else carry = false;
            rst.push(cur);
        }
        if (carry) rst.push(1);
        return rst;
    }
    
public:

    ListNode* doubleIt(ListNode* head) {
        stack<int> s;

        for (ListNode* cur = head;cur != nullptr ; cur = cur->next) {
            s.push(cur->val);
        }
        auto rst = calc(&s);

        ListNode* newHead = nullptr;
        ListNode* temp = nullptr;

        while(!rst.empty()) {
            auto cur = rst.top(); rst.pop();
            if (!newHead) {
                newHead = new ListNode(cur);
                temp = newHead;
            }
            else {
                temp->next = new ListNode(cur);
                temp = temp->next;
            }
        }
        
        return newHead;;
    }
};