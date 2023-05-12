#include<bits/stdc++.h>

using namespace std;


class Solution {
    bool used[300];
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
   ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        // the value of each node is in the range of [-100, 100]
        memset(used, 0, sizeof(used));
        ListNode* curr = head;
        // Scaling for the negative number
        used[curr->val + 100] = true;  
        while (curr->next != nullptr) {
            int scaledNum = curr->next->val + 100;
            if (used[scaledNum]) { // the next node is a duplicate, delete it
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } 
            else { // the next node is not a duplicate
                used[scaledNum] = true;
                curr = curr->next;
            }
        }
        return head;
}

};