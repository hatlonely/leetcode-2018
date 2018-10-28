#!/usr/bin/env python3

from listnode import *


class Solution(object):
    def hasCycle(self, head):
        if head is None:
            return False
        node1 = head
        node2 = head.next
        while node1 != node2:
            if node2 is None or node2.next is None:
                return False
            node1 = node1.next
            node2 = node2.next.next
        return True
