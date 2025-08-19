# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def getKth(self,head,k):
        while(head and k):
            head = head.next
            k-=1
        
        return head

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(-1,head)

        groupPrev = dummy

        while(True):
            kth = self.getKth(groupPrev,k)

            if(not kth): break

            groupNext = kth.next
            prev = kth.next
            curr = groupPrev.next

            while(curr != groupNext):
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
            
            temp = groupPrev.next
            groupPrev.next = kth
            groupPrev = temp
        
        return dummy.next