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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            if (cur->val == val) { // If the value is matched
                if (!prev) { // current node is head
                    head = cur->next;
                }
                else {  // current node is not head
                    prev->next = nxt; 
                }

                ListNode* temp = cur;
                cur = cur->next; // move to the next node
                delete temp;    // remove the current node 
            }
            else { // no matching nodes
                prev = cur;  // update the prev node
                cur = nxt;   // move to the next node
            }
        }
        return head;
   }
};