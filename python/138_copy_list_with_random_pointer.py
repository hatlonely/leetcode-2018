#!/usr/bin/env python3


class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None


class Solution(object):
    def copyRandomList(self, head):
        node = head
        nodemap = {None: None}
        while node is not None:
            nodemap[node] = RandomListNode(node.label)
            node = node.next
        node = head
        while node is not None:
            cnode = nodemap[node]
            cnode.next = nodemap[node.next]
            cnode.random = nodemap[node.random]
            node = node.next
        return nodemap[head]
