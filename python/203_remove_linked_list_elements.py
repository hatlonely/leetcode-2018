#!/usr/bin/env python3

from listnode import *


class Solution:
    def removeElements(self, head, val):
        prev = ListNode(0)
        prev.next = head
        node = prev
        while node.next is not None:
            if node.next.val == val:
                node.next = node.next.next
            else:
                node = node.next
        return prev.next


if __name__ == '__main__':
    solution = Solution()
    head = NewList([1, 2, 6, 3, 4, 5, 6])
    solution.removeElements(head, 6)
    ListShow(head)
