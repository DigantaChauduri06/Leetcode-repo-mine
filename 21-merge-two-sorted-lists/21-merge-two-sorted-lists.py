# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        tHead = dummy
        while list1 and list2:
            if list1.val == list2.val:
                dummy.next = ListNode(list1.val)
                dummy = dummy.next
                dummy.next = ListNode(list2.val)
                dummy = dummy.next
                list1 = list1.next
                list2 = list2.next
            elif list1.val > list2.val:
                dummy.next = ListNode(list2.val)
                list2 = list2.next
                dummy = dummy.next
            else:
                dummy.next = ListNode(list1.val)
                list1 = list1.next
                dummy = dummy.next
        
        while list1:
            dummy.next = ListNode(list1.val)
            list1 = list1.next
            dummy = dummy.next
        
        while list2:
            dummy.next = ListNode(list2.val)
            list2 = list2.next
            dummy = dummy.next
        
        return tHead.next
        