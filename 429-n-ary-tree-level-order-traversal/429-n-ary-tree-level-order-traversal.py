"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root is None:
            return []
        ans = []
        queue = deque([])
        queue.append(root)
        ans.append([root.val])
        while queue:
            n = len(queue)
            tmpNodes = []
            tmp = []
            for _ in range(n):
                f = queue.popleft()
                for n in f.children:
                    tmp.append(n.val)
                    tmpNodes.append(n)
                    # print(len(tmpNodes))
            if tmp != []:
                queue.extend(tmpNodes)
                ans.append(tmp)
        return ans