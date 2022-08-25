# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root and not root.left and not root.right:
            return 1
        if not root:
            return 0
        queue = deque([])
        queue.append([root, 0])
        mx = 0
        while queue:
            n = len(queue)
            for _ in range(n):
                r, i = queue.popleft()
                if r.left:
                    queue.append([r.left, i*2+1])
                if r.right:
                    queue.append([r.right, i*2+2])
            if queue:
                curWid = queue[-1][1] - queue[0][1] + 1
                mx = max(curWid, mx)
        return mx