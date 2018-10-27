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
        self.viMap = {}
        for value in nodes:
            node = GraphNode(value)
            self.vnMap[value] = node
            self.viMap[value] = len(self.nodes)
            self.nodes.append(node)
        for edge in edges:
            n1, n2, distance = edge
            self.vnMap[n1].addEdge(self.vnMap[n2], distance)

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
            if node is None:
                break
            vset.remove(node)
            for edge in node.edges:
                if edge.node.value not in emap or emap[edge.node.value].distance > emap[node.value].distance + edge.distance:
                    emap[edge.node.value] = GraphEdge(
                        node,
                        emap[node.value].distance + edge.distance
                    )

        for node in self.nodes:
            n2 = node.value
            if n2 == n1:
                yield '{}=>{}'.format(n1, n2), 0, [n1]
            elif n2 not in emap:
                yield '{}=>{}'.format(n1, n2), -1, []
            else:
                path = [n2]
                n = n2
                while n != n1:
                    n = emap[n].node.value
                    path.append(n)
                yield '{}=>{}'.format(n1, n2), emap[n2].distance, path[::-1]

    def floyd(self):
        n = len(self.nodes)
        ad = [[None for i in range(n)] for j in range(n)]
        pd = [[-1 for i in range(n)] for j in range(n)]
        for i in range(0, n):
            ad[i][i] = 0
            pd[i][i] = i
        for node in self.nodes:
            for edge in node.edges:
                i = self.viMap[node.value]
                j = self.viMap[edge.node.value]
                ad[i][j] = edge.distance
                pd[i][j] = i
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if ad[i][k] and ad[k][j] and (ad[i][j] is None or ad[i][j] > ad[i][k] + ad[k][j]):
                        ad[i][j] = ad[i][k] + ad[k][j]
                        pd[i][j] = pd[k][j]
        for i in range(n):
            for j in range(n):
                n1 = self.nodes[i].value
                n2 = self.nodes[j].value
                k = j
                path = [n2]
                while k != i:
                    k = pd[i][k]
                    path.append(self.nodes[k].value)
                yield '{}=>{}'.format(n1, n2), ad[i][j], path[::-1]


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
    print()
    for i in graph.dijkstra('v0'):
        print(i)
    print()
    for i in graph.floyd():
        print(i)
