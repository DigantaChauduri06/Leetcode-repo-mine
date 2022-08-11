# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head):
        cur,prev = head,None
        while cur:
            after = cur.next
            cur.next = prev
            prev = cur
            cur = after
        
        return prev
            
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        head = self.reverse(head)
        tmp = head
        if n == 1:
            if tmp:
                return self.reverse(tmp.next)
            # return self.reverse(head)
        n -= 1
        # print(tmp.val)
        # self.printLL(head)
        while n > 1:
            n -= 1
            # print(tmp.val)
            tmp = tmp.next
        if tmp:
            tmp.next = tmp.next.next
        return self.reverse(head)
        
        