#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
public:
    int maxDepth(TreeNode* root) {
        // Base case: If the tree is empty (root is nullptr)
        if (root == nullptr) {
            return 0;
        }

        // Recursive step: Compute the depth of each subtree
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Return the larger one and add 1 for the current node
        return max(leftDepth, rightDepth) + 1;
    }
    
};