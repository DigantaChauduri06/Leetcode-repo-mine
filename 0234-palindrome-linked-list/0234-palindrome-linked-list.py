# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, node):
        after,prev,cur = node.next,None,node
        while cur:
            after = cur.next
            cur.next = prev
            prev = cur
            cur = after
        return prev
    def length(self, node):
        cnt = 0
        while node:
            cnt += 1
            node = node.next
        return cnt
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return True
        fast,slow = head,head
        while fast and fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        n = slow.next
        slow.next = None
        n = self.reverse(n)
        while head and n:
            if head.val != n.val:
                return False
            head = head.next
            n = n.next
        l1,l2 = self.length(head),self.length(n)
        if abs(l1 - l2) <= 1:
            return True
        
        return False