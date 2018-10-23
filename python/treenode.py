class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def NewTree(nums):
    prev = TreeNode(0)
    node = prev
    nodes = []
    isLeft = False
    for num in nums:
        if (isLeft):
            if (num is not None):
                node.left = TreeNode(num)
                nodes.append(node.left)
            isLeft = False
        else:
            if (num is not None):
                node.right = TreeNode(num)
                nodes.append(node.right)
            node = nodes[0]
            nodes = nodes[1:]
            isLeft = True
    return prev.right


def TreeShow(node):
    nodes = []
    nodes.append(node)
    vals = []
    vals.append(node.val)
    while (nodes):
        node = nodes[0]
        nodes = nodes[1:]
        if (node.left):
            nodes.append(node.left)
            vals.append(node.left.val)
        else:
            vals.append(None)
        if (node.right):
            nodes.append(node.right)
            vals.append(node.right.val)
        else:
            vals.append(None)
    print(vals)


def TreeEqual(node1, node2):
    if node1 is None:
        return node2 is None
    if node2 is None:
        return False
    return node1.val == node2.val and TreeEqual(node1.left, node2.left) and TreeEqual(node1.right, node2.right)
