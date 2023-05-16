#include<bits/stdc++.h>

using namespace std;

class Solution {
     struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode* swapPairs(ListNode* head) {
        // head is NULL or there is only one node
        if(head == NULL || head -> next == NULL) return head;

        ListNode* ans = head;
        ListNode* cur = head;

        while (true) {
            if (!cur || !cur->next) break;
            ListNode* nxt = cur->next;
            swap(cur->val, nxt->val); // swap the node instead swapping the address
            cur = nxt->next; // jump two steps
        }
        return ans;
    }
};