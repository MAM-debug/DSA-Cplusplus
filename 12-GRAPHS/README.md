# Graphs - Data Structures and Algorithms

## Overview
This directory contains implementations of graph data structures and related algorithms using adjacency list representation.

## Files

### directedgraph.cpp
Implementation of a directed graph using adjacency list with the following features:

**Node Structure:**
- `vertex`: stores the vertex value
- `next`: pointer to the next node in the adjacency list

**Graph Class Methods:**

| Method | Description | Time Complexity |
|--------|-------------|-----------------|
| `addEdgedirected(source, destination)` | Adds a directed edge from source to destination | O(1) |
| `addedgeundirected(source, destination)` | Adds an undirected edge (bidirectional) | O(1) |
| `removeEdgedirected(source, destination)` | Removes a directed edge | O(V + E) |
| `removeedgeundirected(source, destination)` | Removes an undirected edge | O(V + E) |
| `degree(vertex)` | Returns out-degree of a vertex | O(degree) |
| `indegree(vertex)` | Returns in-degree of a vertex | O(V²) |
| `outdegree(vertex)` | Returns out-degree of a vertex | O(degree) |
| `totaldegree(vertex)` | Returns total degree (in + out) | O(V²) |
| `printGraph()` | Displays the adjacency list representation | O(V + E) |

## Usage Example
```cpp
Graph g(4);
g.addEdgedirected(0, 1);
g.addEdgedirected(0, 2);
g.addedgeundirected(1, 3);
g.printGraph();
g.degree(0);
g.indegree(1);
```

## Notes
- Uses adjacency list representation
- Supports both directed and undirected graphs
- In-degree calculation iterates through all vertices (O(V²) complexity)