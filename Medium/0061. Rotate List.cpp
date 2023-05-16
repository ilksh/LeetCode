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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head== NULL || k == 0)
            return head;
        ListNode* cur = head;
        int cnt = 0;    // number of node
        while (cur->next) { // iterate until (n -1) th node
            cnt++;
            cur = cur->next;
        }
        cur->next = head;

        k %= (cnt + 1); // scaling the k
        int diff = cnt - k;

        cur = head;
        while (diff--) cur = cur->next;
        cur->next = NULL;
        ListNode* rst = cur->next;
        return rst;
    }
};