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
public:
    bool isPalindrome(ListNode* head) {
        int n = 0; // number of elements
        vector<int> v;
        for (ListNode* c = head;c != NULL ; c = c->next) { // iterate the whole linked list 
            v.push_back(c->val); // add to vector
            n++; // increase the number of elements
        } 

        for (int i = 0; i < n / 2; ++i) { // iterate from start to the mid
            if (v[i] != v[n - 1 - i]) return false; // the linked list is not palindrome 
        }

        return true; 
    }
};