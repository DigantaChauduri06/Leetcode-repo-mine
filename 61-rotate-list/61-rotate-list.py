# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def length(self, head):
        cur = 0
        while head:
            cur+=1
            head = head.next
        return cur
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        sz = self.length(head)
        if not head or k == 0 or not head.next:
            return head
        k = k % sz
        if sz == k or k == 0:
            return head
        slow, fast = head, head
        for i in range(k):
            fast = fast.next
            if not fast:
                return head
            
        while fast.next:
            fast = fast.next
            slow = slow.next
        nextHalf = slow.next
        slow.next = None
        # print(nextHalf.next.val)
        tHead = nextHalf
        while nextHalf and nextHalf.next:
            nextHalf = nextHalf.next
        # head = nextHalf
        if nextHalf:
            nextHalf.next = head
        return tHead