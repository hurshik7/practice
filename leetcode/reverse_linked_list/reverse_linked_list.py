# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head

        ptr = head
        prevNode = ptr
        ptr = ptr.next
        prevNode.next = None
        while ptr is not None:
            nextNode = ptr.next
            ptr.next = prevNode
            prevNode = ptr
            ptr = nextNode


            return prevNode



