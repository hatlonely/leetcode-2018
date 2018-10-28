#!/usr/bin/env python3


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def NewList(nums):
    prev = ListNode(0)
    node = prev
    for num in nums:
        node.next = ListNode(num)
        node = node.next
    return prev.next


def ListEqual(node1, node2):
    while node1 is not None and node2 is not None:
        if node1.val != node2.val:
            return False
        node1 = node1.next
        node2 = node2.next
    return node1 is None and node2 is None


def ListShow(node):
    vals = []
    while node is not None:
        vals.append(node.val)
        node = node.next
    print(vals)
