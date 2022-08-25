# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class TreeInfo:
    def __init__(self):
        self.height = 0
        self.diameter = 0

class Solution:
    def diameterOfTree(self, root):
        if not root:
            n = TreeInfo()
            return n
        left = self.diameterOfTree(root.left)
        right = self.diameterOfTree(root.right)
        ans = TreeInfo()
        ans.height = max(left.height, right.height) + 1
        ans.diameter = max(left.height + right.height, ans.diameter, left.diameter, right.diameter)
        return ans
        
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return self.diameterOfTree(root).diameter