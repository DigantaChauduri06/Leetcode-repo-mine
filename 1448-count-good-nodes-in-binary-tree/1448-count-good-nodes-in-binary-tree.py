# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        queue = deque([])
        curMax = root.val
        queue.append([root, root.val])
        cnt = 1
        while queue:
            sz = len(queue)
            for _ in range(sz):
                r,c = queue.popleft()
                if r.left:
                    if c <= r.left.val:
                        cnt += 1
                    queue.append([r.left, max(c, r.left.val)])
                if r.right:
                    if c <= r.right.val:
                        cnt += 1
                    queue.append([r.right, max(c, r.right.val)])
        return cnt
        
        
        
                