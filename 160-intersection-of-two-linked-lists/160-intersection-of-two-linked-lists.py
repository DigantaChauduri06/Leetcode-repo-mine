# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def length(self, head):
        cnt = 0
        while head:
            cnt += 1
            head = head.next
        return cnt

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        sz1 = self.length(headA)
        sz2 = self.length(headB)
        while sz1 < sz2 and headB:
            headB = headB.next
            sz2-=1
        
        # print(sz1, sz2)
        
        while sz1 > sz2 and headA:
            headA = headA.next
            sz1 -= 1
        # print(headA.val, headB.val)
        while headA is not headB and headA and headB:
            headA = headA.next
            headB = headB.next
        return headA