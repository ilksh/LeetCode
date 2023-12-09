# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def hasPathSum(self, root, targetSum):
        # Base case: if the root does not exist, there's no path, return False
        if not root: return False

        # Recursive inner function to check the path sum
        def checkPath(node, currentSum):
            # Base case: if the current node is a leaf, check if the path sum equals the targetSum
            if not node.left and not node.right: return currentSum == node.val

            # Recursive case: check the path sum for the left subtree
            if node.left:
                if checkPath(node.left, currentSum - node.val):
                    return True

            # Recursive case: check the path sum for the right subtree
            if node.right:
                if checkPath(node.right, currentSum - node.val):
                    return True

            # If neither subtree has a path sum, return False
            return False

        # Invoke the inner function starting from the root node and the initial targetSum
        return checkPath(root, targetSum)
