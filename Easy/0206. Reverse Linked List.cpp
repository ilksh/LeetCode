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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;

        // 1 -> 2 -> 3
        // cur = 1, prev = NULL, nxt = 2
        // Step 1) 1 > NULL
        // Step 2) move to node 2. cur = 2, prv = 1, nxt = 3
        // Step 3) 2 > 1 > NULL
        while (true) {
            if (cur == NULL) break;
            ListNode* nxt = cur->next; // next node
            cur->next = prev;          // reverse the order   
            prev = cur;                // update the info
            cur = nxt;
        }
        return prev;
    }
};