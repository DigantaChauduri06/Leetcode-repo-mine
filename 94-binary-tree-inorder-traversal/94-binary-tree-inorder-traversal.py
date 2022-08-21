# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        stack,ans = [],[]
        tmp = root
        while tmp or stack:
            while tmp:
                stack.append(tmp)
                tmp = tmp.left
            # print(len(stack))
            tmp = stack.pop()
            ans.append(tmp.val)
            tmp = tmp.right
        return ans