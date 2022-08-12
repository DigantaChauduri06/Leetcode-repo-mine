# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not l1 and not l2:
            return 0
        if not l1 and l2:
            return l2
        if l1 and not l2:
            return l1
        nn = ListNode(0)
        dummy = nn
        carry = 0
        while l1 or l2 or carry:
            data = 0
            data += l1.val if l1 else 0
            data += l2.val if l2 else 0
            data += carry
            nn.next = ListNode(data%10)
            nn = nn.next
            carry = data // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        return dummy.next