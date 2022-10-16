# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
"""
def mergeTwoLists(self, h1: Optional[ListNode], h2: Optional[ListNode]) -> Optional[ListNode]:
    if not h1 and not h2:
        return None
    if not h1 or not h2:
        return h1 if not h2 else h2
    if h2.val < h1.val:
        h2.next = self.mergeTwoLists(h1, h2.next)
        return h2
    else:
        h1.next = self.mergeTwoLists(h1.next, h2)
        return h1

"""


class Solution:
    def mergeTwoLists(self, h1: Optional[ListNode], h2: Optional[ListNode]) -> Optional[ListNode]:
        if not h1 and not h2:
            return None
        if not h1 or not h2:
            return h1 if not h2 else h2
        nn = ListNode(0)
        dummy = nn
        while h1 and h2:
            if h1.val < h2.val:
                nn.next = h1
                h1 = h1.next
            else:
                nn.next = h2
                h2 = h2.next
            nn = nn.next
        nn.next = h1 or h2
        return dummy.next