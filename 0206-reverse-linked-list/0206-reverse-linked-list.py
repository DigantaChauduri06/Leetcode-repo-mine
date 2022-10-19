# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        newHead = self.reverseList(head.next)
        # after = head.next
        head.next = None
        # after.next = head
        tmp = newHead
        while tmp and tmp.next:
            tmp = tmp.next
        if tmp:
            tmp.next = head
        return newHead