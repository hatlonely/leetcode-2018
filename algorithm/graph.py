#!/usr/bin/env python3

import sys


class GraphNode(object):
    def __init__(self, value):
        self.value = value
        self.edges = []

    def __str__(self):
        return '[' + str(self.value) + ', ' + ', '.join([str(edge) for edge in self.edges]) + ']'

    def addEdge(self, node, distance=1):
        self.edges.append(GraphEdge(node, distance))


class GraphEdge(object):
    def __init__(self, node, distance=1):
        self.node = node
        self.distance = distance

    def __str__(self):
        return '(' + str(self.node.value) + ',' + str(self.distance) + ')'


class Graph(object):
    def __init__(self, nodes, edges):
        self.nodes = []
        self.vnMap = {}
        for value in nodes:
            node = GraphNode(value)
            self.vnMap[value] = node
            self.nodes.append(node)
        for edge in edges:
            self.vnMap[edge[0]].addEdge(self.vnMap[edge[1]], edge[2])

    def __str__(self):
        return '[' + ', '.join([str(node) for node in self.nodes]) + ']'

    def dijkstra(self, n1):
        vset = set(self.nodes)
        emap = {}
        vset.remove(self.vnMap[n1])
        for edge in self.vnMap[n1].edges:
            emap[edge.node.value] = GraphEdge(self.vnMap[n1], edge.distance)
        while vset:
            mindistance = sys.maxsize
            node = None
            for n in vset:
                if n.value not in emap:
                    continue
                edge = emap[n.value]
                if mindistance > edge.distance:
                    mindistance = edge.distance
                    node = n
            vset.remove(node)
            for edge in node.edges:
                if edge.node.value not in emap:
                    emap[edge.node.value] = GraphEdge(
                        node, emap[node.value].distance + edge.distance)
                else:
                    if emap[edge.node.value].distance > emap[node.value].distance + edge.distance:
                        emap[edge.node.value].distance = emap[node.value].distance + \
                            edge.distance
                        emap[edge.node.value].node = node

        for node in self.nodes:
            n2 = node.value
            if n2 not in emap:
                yield [], -1
            else:
                path = [n2]
                n = n2
                while n != n1:
                    n = emap[n].node.value
                    path.append(n)
                yield path[::-1], emap[n2].distance


if __name__ == '__main__':
    graph = Graph(
        ['v0', 'v1', 'v2', 'v3', 'v4'], [
            ('v0', 'v1', 10),
            ('v0', 'v3', 30),
            ('v0', 'v4', 100),
            ('v1', 'v2', 50),
            ('v2', 'v4', 10),
            ('v3', 'v1', 10),
            ('v3', 'v2', 20),
            ('v3', 'v4', 60),
        ]
    )
    print(graph)
    print(list(graph.dijkstra('v0')))
