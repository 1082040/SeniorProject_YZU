# SeniorProject_YZU

Graph Algorithm Programs
This repository contains two C++ programs implementing key graph algorithms:

Hamiltonian Cycle Finder
Eulerian Path Finder
Both programs solve specific graph traversal problems and provide results in user-friendly formats.

1. Hamiltonian Cycle Finder
Description
This program finds a Hamiltonian cycle in a graph, which is a closed path that visits each vertex exactly once. It uses backtracking to explore potential cycles.

Features
Checks for the existence of a Hamiltonian cycle.
Outputs the cycle if found in a structured format.
Input Format
Number of vertices (n).
Number of edges (Edges).
Each edge represented by two vertices (v1, v2).

Example Input:

4
4
1 2
2 3
3 4
4 1

Example Output:

0-1 2-3 

Execution Time: 0.002S

2. Eulerian Path Finder
Description
This program finds an Eulerian path or circuit in a graph, which traverses every edge exactly once. It uses a depth-first search (DFS) approach.

Features
Detects Eulerian paths or circuits.
Automatically starts at a vertex with odd degree (if applicable).
Outputs the path in sequence.
Input Format
Number of edges (m).
Each edge represented by two vertices (a, b).

Example Input:

5
1 2
2 3
3 4
4 1
1 3

Example Output:

1->3->2->1->4->3

How to Compile and Run
Use a C++ compiler like g++ to compile the programs:

bash

g++ -o HamiltonianCycle HamiltonianCycleFinder.cpp
g++ -o EulerianPath EulerianPathFinder.cpp

Run the executables:

bash

./HamiltonianCycle
./EulerianPath

Provide the required inputs as prompted.

Notes
Ensure the input graph is correctly formatted and connected to avoid undefined behavior.
These programs assume a maximum of 500 vertices for the Eulerian path and 10 vertices for the Hamiltonian cycle. Adjust array sizes as needed for larger graphs.
