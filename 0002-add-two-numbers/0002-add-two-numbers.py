# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        nn = ListNode(0)
        dummy = nn
        while l1 or l2 or carry:
            sm = 0
            if l1:
                sm += l1.val
            if l2:
                sm += l2.val
            sm+=carry
            nn.next = ListNode(sm%10)
            carry = sm//10
            nn = nn.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        return dummy.next