#include<bits/stdc++.h>

using namespace std;

class Solution {
private: 
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    const int MIN_INT = -1e5 - 1;
    const int MAX_INT = 1e5 + 1;
public:
    bool hasCycle(ListNode *head) {

        unordered_set<ListNode*> visitedNodes;  
        
        ListNode *cur = head;
        bool isCycle = false; // flag which signifies whether there is a cycle
        while (cur) {
             if (visitedNodes.count(cur) > 0) {
                isCycle = true;
                break;
            }
            
            visitedNodes.insert(cur);  // Mark current node as visited
            cur = cur->next;  // Move to the next node
        }

        return isCycle;
    }
};