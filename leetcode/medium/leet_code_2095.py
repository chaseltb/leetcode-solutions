# 2095 Delete the middle node of the linked list
# Medium O(1) space and O(n) time

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (head is None or head.next is None):
            return None
        # fast and slow pointers to accomplish O(2) space

        slow = head
        fast = head

        # Iterate through half of the list for O(n/2) = O(n) time
        while (fast and fast.next):
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = slow.next
        return head
