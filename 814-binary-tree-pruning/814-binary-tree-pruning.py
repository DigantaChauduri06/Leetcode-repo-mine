# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isContainingOne(self,root):
        if not root:
            return False
        if root.val == 1:
            return True
        return (self.isContainingOne(root.left) or
                self.isContainingOne(root.right))
    def pruneTreeHelper(self, root):
        if not root:
            return root
        if not self.isContainingOne(root.left):
            root.left = None
        if not self.isContainingOne(root.right):
            root.right = None
        self.pruneTreeHelper(root.left)
        self.pruneTreeHelper(root.right)
        return root
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        root = self.pruneTreeHelper(root)
        return None if not root.left and not root.right and root and root.val != 1 else root