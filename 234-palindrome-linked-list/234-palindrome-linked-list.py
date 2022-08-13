class Solution:
    def reverse(self, head):
        after,cur,prev = None,head, None
        while cur:
            after = cur.next
            cur.next = prev
            prev = cur
            cur = after
        return prev
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow,fast = head,head.next
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        nextHalf = slow.next
        slow.next = None
        nextHalf = self.reverse(nextHalf)
        while head and nextHalf:
            if head.val != nextHalf.val:
                return False 
            head = head.next
            nextHalf = nextHalf.next
        
        if not head and not nextHalf:
            return True
        if not head and nextHalf and not nextHalf.next:
            return True
        if not nextHalf and head and not head.next:
            return True
        return False
        
        
        