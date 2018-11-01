#!/usr/bin/env python3

from listnode import *


class Solution(object):
    def insertionSortList(self, head):
        if head is None:
            return head
        prev = ListNode(0)
        prev.next = head
        tail = head
        while tail.next is not None:
            node = prev
            while node != tail and node.next.val < tail.next.val:
                node = node.next
            if node != tail:
                node2 = tail.next.next
                node1 = node.next
                node.next = tail.next
                tail.next.next = node1
                tail.next = node2
            else:
                tail = tail.next

        return prev.next


if __name__ == '__main__':
    solution = Solution()
    ListShow(solution.insertionSortList(NewList([4, 2, 1, 3])))
    ListShow(solution.insertionSortList(NewList([4])))
