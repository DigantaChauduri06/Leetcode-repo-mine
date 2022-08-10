# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        si,ei = 0, len(nums)-1
        def helper(si, ei):
            if si > ei:
                return None
            m = (si + ei) // 2
            root = TreeNode(nums[m])
            if si == ei:
                return root
            root.left = helper(si, m-1)
            root.right = helper(m+1, ei)
            return root
        return helper(si,ei)