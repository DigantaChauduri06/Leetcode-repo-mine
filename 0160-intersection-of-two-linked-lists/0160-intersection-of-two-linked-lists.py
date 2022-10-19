# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getLen(self,head):
        cnt = 0
        while head:
            cnt += 1
            head = head.next
        return cnt
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        len1 = self.getLen(headA)
        len2 = self.getLen(headB)
        node1,node2 = headA,headB
        while node1 and len1 > len2:
            node1 = node1.next
            len1 -= 1
        while node2 and len2 > len1:
            node2 = node2.next
            len2 -= 1
        while node1 and node2:
            if node1 == node2:
                return node1
            node1 = node1.next
            node2 = node2.next
        return None
        