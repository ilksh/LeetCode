#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> v; // vector with result
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
public:
    void traverse(TreeNode* root) {
        if (root == NULL) return;
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return v;
    }
};