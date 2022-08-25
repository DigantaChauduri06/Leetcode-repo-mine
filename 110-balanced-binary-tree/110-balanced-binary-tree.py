# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class TreeInfo:
    def __init__(self):
        self.isBalenced = True
        self.height = 0

class Solution:
    def checkBalenced(self, root):
        if not root:
            n = TreeInfo()
            return n
        left = self.checkBalenced(root.left)
        right = self.checkBalenced(root.right)
        ans = TreeInfo()
        ans.height = max(left.height, right.height) + 1
        ans.isBalenced = ans.isBalenced and abs(left.height - right.height) <= 1 and left.isBalenced and right.isBalenced
        return ans
        
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.checkBalenced(root).isBalenced