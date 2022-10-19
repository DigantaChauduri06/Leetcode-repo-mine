# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def BST_Helper(self, nums, low, high):
        if low > high:
            return None
        m = (low + high) // 2
        root = TreeNode(nums[m])
        if low == high:
            return root
        root.left = self.BST_Helper(nums,low, m-1)
        root.right = self.BST_Helper(nums,m+1, high)
        return root
    
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        low,high = 0,len(nums)-1
        return self.BST_Helper(nums, low, high)