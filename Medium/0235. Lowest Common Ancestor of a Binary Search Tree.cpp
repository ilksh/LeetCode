#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Find the lowest common ancestor of node p and node q
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the current node is null or p or q, current node should not be common ancestor
        if (!root || root == p || root == q) return root;
        
        // traverse recursively
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are not null, it means p, q are on different subtrees of root
        if (left && right) return root;
        
        return left ? left : right;
    }
};
