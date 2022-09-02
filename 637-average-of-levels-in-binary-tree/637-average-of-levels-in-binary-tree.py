class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        queue = deque([])
        queue.append(root)
        lvl = []
        while queue:
            n = len(queue)
            sm = 0
            for _ in range(n):
                f = queue.popleft()
                sm += f.val
                if f.left:
                    queue.append(f.left)
                if f.right:
                    queue.append(f.right)
            lvl.append(sm / n)
        return lvl
        