# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class getDiameterClass:
    def __init__(self, diameter = 0, height = 0):
        self.diameter = diameter
        self.height = height

class Solution:
    def getDiameter(self, root):
        if not root:
            a = getDiameterClass(0,0)
            return a
        left = self.getDiameter(root.left)
        right = self.getDiameter(root.right)
        ans = getDiameterClass()
        ans.height = max(left.height, right.height) + 1
        ans.diameter = max(left.height+right.height, ans.diameter, max(left.diameter, right.diameter))
        return ans
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return self.getDiameter(root).diameter
        