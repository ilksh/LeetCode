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
    // This function counts the number of node in the linked list
    int numOfNode(ListNode* head) {
        int cnt = 0;
        for (ListNode* n = head; n != NULL;n = n->next) cnt++;
        return cnt;
    }
    // This function returns the head of the linked list after 
    // swapping the values of the kth node from the beginning and the kth node from the end 
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head;   // current address
        ListNode* front = NULL; // address of kth node from the beginning
        ListNode* rear = NULL;  // address of kth node from the end 

        int nodeCnt = numOfNode(head); // number of node
        int firstCnt = 1, rearCnt = 1; // the list is 1-indexed

        for (int i = 0 ; i < nodeCnt; ++i) { // iterate until the end
            if (i == k -1) front = cur;         // find the address
            if (i == (nodeCnt - k)) rear = cur; // find the address
            if (rear && front) break;           // optimization
            cur =cur->next;
        }
        
        swap(front->val, rear->val); // swapping the values 
        return head;
    }
};