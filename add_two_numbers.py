from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
def push_node(l: Optional[ListNode], val):
    if l.val == None:
        l.val = val
        return
    while l.next != None:
        l = l.next
    l.next = ListNode(val)

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        total = 0
        i = 0
        gate1, gate2 = True, True
        while True:
    
            if gate1: total += l1.val * (10**i)
            if gate2: total += l2.val * (10**i)
            if l1.next == None: gate1 = False
            if l2.next == None: gate2 = False
            if gate1 == False and gate2 == False: break
            
            if gate1: l1 = l1.next
            if gate2: l2 = l2.next
            i += 1
        
        total = list(str(total))
        total.reverse()
        total = "".join(total)
        
        final = ListNode(None)
        for j in total:
            push_node(final, int(j))
        
        return final