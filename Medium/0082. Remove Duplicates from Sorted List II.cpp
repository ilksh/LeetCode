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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int used[210];
        memset(used, 0, sizeof(used));
        for (ListNode* cur = head; cur != NULL ; cur = cur -> next) {
            int curNum = cur->val + 100;
            used[curNum] += 1;
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        for (int i = 0; i < 210; ++i) {
            if (used[i] == 1) {
                tail->next = new ListNode(i - 100);
                tail = tail->next;
            }
        }

        return dummy.next;
    }
};