#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0; // number of nodes

        // iterate to the end in order to count the number of nodes
        for (ListNode* c = head; c != NULL; c = c->next) cnt++;

        ListNode* cur = head;
        ListNode* prev = nullptr;
        // iterate until nth node from the end of the lis
        for (int i = 0; i < cnt - n; ++i) {
            prev = cur;
            cur = cur->next;
        }

        // if current node is not head
        if (prev != nullptr) prev->next = cur->next;
        // if current node is head
        else head = cur->next;
        
        return head;       
    }
};