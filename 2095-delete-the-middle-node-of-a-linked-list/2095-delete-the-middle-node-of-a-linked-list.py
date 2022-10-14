class Solution:
    def middle_node(self, head):
        slow,fast = head, head.next
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        midNode = self.middle_node(head.next)
        tmp = head
        while tmp and tmp.next != midNode:
            tmp = tmp.next
        tmp.next = tmp.next.next
        return head