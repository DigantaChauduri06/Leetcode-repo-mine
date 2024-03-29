class Solution:        
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 1:
            return head
        start = None
        node = None
        tail = None
        stack = []
        while head:
            i = 1
            start = head
            while i < k and head:
                head = head.next
                i+=1
            if not head:
                break
            nxt = head.next
            head.next = None
            prev = self.reverse(start)
            tail = prev
            if not node:
                node = prev
            head = nxt
            if len(stack) > 0:
                cur = stack.pop()
                cur.next = prev
            if not head:
                return node
            stack.append(start)
        while tail and tail.next:
            tail = tail.next
        tail.next = start
        return node
    
    def reverse(self, head):
        after,cur,prev = None,head, None
        while cur:
            after = cur.next
            cur.next = prev
            prev = cur
            cur = after
        return prev