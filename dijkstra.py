#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File              : dijkstra.py
# Author            : azulbukh <l1pt0n1905@gmail.com>
# Date              : 29.01.2019
# Last Modified Date: 29.01.2019
# Last Modified By  : azulbukh <l1pt0n1905@gmail.com>

#graph
graph = {}
graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2
graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["end"] = 5
graph["a"] = {}
graph["a"]["end"] = 1
graph["end"] = {}

#costs hash table
infinity = float("inf")
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["end"] = infinity

#parents hash table
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["end"] = None

processed = []

def find_lowest_cost_node(costs):
    lowest_cost = infinity
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node

node = find_lowest_cost_node(costs)
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for i in neighbors.keys():
        new_cost = cost + neighbors[i]
        if costs[i] > new_cost:
            costs[i] = new_cost
            parents[i] = node
    processed.append(node)
    node = find_lowest_cost_node(costs)

print(costs["end"])
