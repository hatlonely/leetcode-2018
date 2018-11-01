#!/usr/bin/env python3

from listnode import *


class Solution(object):
    def reorderList(self, head):
        if head is None or head.next is None:
            return
        slow = head
        fast = head
        while True:
            if fast.next is None or fast.next.next is None:
                break
            slow = slow.next
            fast = fast.next.next

        l1 = head
        n1 = slow
        n2 = n1.next
        while n2 is not None:
            n3 = n2.next
            n2.next = n1
            n1 = n2
            n2 = n3
        slow.next.next = None
        slow.next = None
        l2 = n1

        while l2 is not None:
            n1 = l1.next
            n2 = l2.next
            l1.next = l2
            l2.next = n1
            l1 = n1
            l2 = n2


if __name__ == '__main__':
    solution = Solution()
    ListShow(solution.reorderList(NewList([1, 2])))
    ListShow(solution.reorderList(NewList([1, 2, 3])))
    ListShow(solution.reorderList(NewList([1, 2, 3, 4])))
    ListShow(solution.reorderList(NewList([1, 2, 3, 4, 5])))
