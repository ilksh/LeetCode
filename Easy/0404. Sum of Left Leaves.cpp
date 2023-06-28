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
   int sumOfLeftLeaves(TreeNode* root, bool left = false) {
    if (!root) return 0; 
    if (!root->left && !root->right) { // current node is at the edge
        if (left) return root->val; // if it is on the left, add
        return 0;
    }
    
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }   
};

int main() {
    Solution solution;
    TreeNode* root5 = new TreeNode(3);
    root5->left = new TreeNode(9);
    root5->left->left = new TreeNode(4);
    root5->left->left->left = new TreeNode(10);
    root5->right = new TreeNode(7);
    int sum5 = solution.sumOfLeftLeaves(root5);
    cout << "Sum of left leaves in Test Case : " << sum5 << endl;
}