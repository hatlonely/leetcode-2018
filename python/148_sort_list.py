#!/usr/bin/env python3

from listnode import *


class Solution(object):
    def mergeList(self, l1, l2):
        prev = ListNode(0)
        node = prev
        while l1 and l2:
            if l1.val < l2.val:
                node.next = l1
                l1 = l1.next
            else:
                node.next = l2
                l2 = l2.next
            node = node.next
        if l1:
            node.next = l1
        if l2:
            node.next = l2
        return prev.next

    def middleListNode(self, head):
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

    def sortList(self, head):
        if not head or not head.next:
            return head
        m = self.middleListNode(head)
        l1 = head
        l2 = m.next
        m.next = None
        return self.mergeList(self.sortList(l1), self.sortList(l2))


if __name__ == '__main__':
    solution = Solution()
    ListShow(solution.sortList(NewList([4, 2, 1, 3])))
    ListShow(solution.mergeList(NewList([1, 4, 5]), NewList([2, 6])))
