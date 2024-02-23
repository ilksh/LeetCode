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
    // Define a new type for the elements in the priority queue
    typedef pair<int, ListNode*> NodePair;

    // Define a new type for the priority queue itself, which sorts the elements in ascending order based on the integer value
    typedef priority_queue<NodePair, vector<NodePair>, greater<NodePair>> MinHeap;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* mergedListHead = new ListNode(-1);
        ListNode* currentTail = mergedListHead;

        // Use the newly defined type for the min heap
        MinHeap minHeap;

        for (ListNode* listHead : lists) {
            if (listHead != nullptr) minHeap.push({listHead->val, listHead});
        }

        while (!minHeap.empty()) {
            ListNode* smallestNode = minHeap.top().second;
            minHeap.pop();

            if (smallestNode->next != nullptr) {
                minHeap.push({smallestNode->next->val, smallestNode->next});
            }

            currentTail->next = smallestNode;
            currentTail = currentTail->next;
        }

        return mergedListHead->next;
    }
};