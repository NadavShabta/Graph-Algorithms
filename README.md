Nadav034@gmail.com

# Graph Algorithms Project

This project implements various graph algorithms to analyze and process graph data. It includes functionalities for checking connectivity, finding shortest paths, detecting cycles, checking bipartiteness, and detecting negative weight cycles in both directed and undirected graphs. The project also uses `doctest` for unit testing.

## Table of Contents

- [Graph Algorithms Project](#graph-algorithms-project)
  - [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [Algorithms Implemented](#algorithms-implemented)
    - [1. Connectivity Check](#1-connectivity-check)
    - [2. Shortest Path](#2-shortest-path)
    - [3. Cycle Detection](#3-cycle-detection)
    - [4. Bipartite Check](#4-bipartite-check)
    - [5. Negative Cycle Detection](#5-negative-cycle-detection)
  - [Graph Class](#graph-class)
  - [Project Structure](#project-structure)
  - [Building and Running](#building-and-running)
    - [Dependencies](#dependencies)
    - [Building](#building)
    - [Running Tests](#running-tests)
  - [Usage](#usage)
  - [Testing](#testing)

## Description

This project implements a set of algorithms to perform various operations on graphs. It can determine if a graph is connected, find the shortest path between nodes, detect cycles, check if a graph is bipartite, and identify negative weight cycles. The project leverages depth-first search (DFS), breadth-first search (BFS), Dijkstra's algorithm, and the Bellman-Ford algorithm to perform these operations. The implementation is tested using the `doctest` framework to ensure correctness.

## Algorithms Implemented

### 1. Connectivity Check

The `isConnected` function determines if a graph is connected.

- **Undirected Graph**: Uses Depth-First Search (DFS) to check if all vertices are reachable from any starting vertex.
- **Directed Graph**: Uses DFS and then transposes the graph to check for strong connectivity.

### 2. Shortest Path

The `shortestPath` function finds the shortest path between two vertices.

- **Weighted Graph**: Uses Dijkstra's algorithm.
- **Unweighted Graph**: Uses Breadth-First Search (BFS).

### 3. Cycle Detection

The `isContainsCycle` function detects cycles in a graph.

- **Directed Graph**: Uses Depth-First Search (DFS) with a recursion stack.
- **Undirected Graph**: Uses DFS with a parent tracking mechanism.

### 4. Bipartite Check

The `isBipartite` function checks if a graph is bipartite, meaning its vertices can be divided into two disjoint sets such that no two graph vertices within the same set are adjacent. This is done using BFS.

### 5. Negative Cycle Detection

The `negativeCycle` function detects negative weight cycles in a graph using the Bellman-Ford algorithm.

## Graph Class

The `Graph` class represents a graph using an adjacency matrix. Key methods include:

- `loadGraph(const std::vector<std::vector<int>>& newGraph)`: Loads a new graph from a given adjacency matrix.
- `printGraph() const`: Prints the graph's adjacency matrix.
- `getVertexNum() const`: Returns the number of vertices in the graph.
- `getNumberOfEdges() const`: Returns the number of edges in the graph.
- `isGraphDirected() const`: Returns whether the graph is directed.
- `isGraphWeighted() const`: Returns whether the graph is weighted.
- `getGraph() const`: Returns the adjacency matrix.

## Project Structure

- **Graph.hpp**: Header file defining the `Graph` class.
- **Graph.cpp**: Implementation of the `Graph` class.
- **Algorithms.hpp**: Header file defining the `Algorithms` class and its methods.
- **Algorithms.cpp**: Implementation of the `Algorithms` class.
- **Test.cpp**: Contains test cases for all implemented algorithms using `doctest`.
- - **MakeFile**.

## Building and Running

### Dependencies

- **C++11 or higher**: Ensure your compiler supports C++11.
- **doctest**: A lightweight C++ testing framework. Download `doctest.h` from the [doctest GitHub repository](https://github.com/onqtam/doctest).
