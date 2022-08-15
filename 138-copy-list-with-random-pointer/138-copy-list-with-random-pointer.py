"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        oldToNew = {None:None}
        tmp = head
        while tmp:
            copy = Node(tmp.val)
            oldToNew[tmp] = copy
            tmp = tmp.next
        tmp = head
        # print(oldToNew[tmp.next].val)
        while tmp:
            copy = oldToNew[tmp]
            copy.next = oldToNew[tmp.next]
            copy.random = oldToNew[tmp.random]
            tmp = tmp.next
        return oldToNew[head]
            
            
            
            
            
            
            
            