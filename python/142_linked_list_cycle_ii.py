#!/usr/bin/env python3

from listnode import *


class Solution(object):
    def detectCycle(self, head):
        if head is None:
            return None
        slow = head
        fast = head.next
        while slow != fast:
            if fast is None or fast.next is None:
                return None
            slow = slow.next
            fast = fast.next.next

        k = 1
        fast = fast.next
        while slow != fast:
            slow = slow.next
            fast = fast.next.next
            k += 1

        slow = head
        fast = head
        for _ in range(k):
            slow = slow.next

        while fast != slow:
            slow = slow.next
            fast = fast.next
        return slow


if __name__ == '__main__':
    solution = Solution()
    head = NewList([1, 2])
    head.next.next = head
    node = solution.detectCycle(head)
    print(node.val)
