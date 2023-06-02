#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if (!root) return true; // tree is empty
       return solve(root->left, root->right);
    }
    bool solve(TreeNode* p, TreeNode* q) {
         if (!p && !q) return true;  // both trees reach the end
         if (!p || !q) return false; // at least one of tree node is null
         if (p->val != q->val) return false; // compare the values
         // move to next step: matching left and right && right and left
        return solve(p->left, q->right) && solve(p->right, q->left);
    }
};