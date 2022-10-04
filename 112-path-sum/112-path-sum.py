# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        def helper(root, cur = 0):
            if root and not root.left and not root.right:
                if cur + root.val == targetSum:
                    return True
                return False
            if not root:
                return False
            left = helper(root.left, (cur+root.val))
            if left:
                return True
            right = helper(root.right, (cur+root.val))
            return left or right
        return helper(root)