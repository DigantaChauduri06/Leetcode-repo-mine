# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
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