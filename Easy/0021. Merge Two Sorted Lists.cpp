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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();    
        ListNode* tail = temp;

        while(l1 != nullptr && l2 != nullptr) { 
            int valOne = l1->val;
            int valTwo = l2->val;

            if (valOne > valTwo) { // add l2
                tail->next = l2;
                l2 = l2->next; // move on to the next node
            }
            else { // add l1
                tail->next = l1;
                l1 = l1->next; // move on to the next node
            }
            tail = tail->next;
        }
        // IMPORTANT: current WHILE loop cannot reach to the tail of l1 and l2 
        if (l1 != nullptr) tail->next = l1;
        else tail->next = l2;

        ListNode* ans = temp->next;
        delete temp;
        return ans;
  }
};		