class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Declare a pointer to the head of the new linked list
        ListNode* head = nullptr;
        // Declare a pointer to a pointer to the current node of the new linked list
        ListNode** tail = &head;
    
        int carry = 0;
        
        // Loop until both input lists and the carry value are null.
        while (true) {
            if (l1 == nullptr && l2 == nullptr && carry == 0) break;
            int sum = carry; // Initialize
            
            // If l1 is not null, add its value and move l1 to the next node.
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // If l2 is not null, add its value and move l2 to the next node.
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10; // Calculate the new carry value
            *tail = new ListNode(sum % 10); // Create a new node with the ones digit of the sum.
            tail = &((*tail)->next);  // Move the tail pointer
        }
        return head;
    }

};