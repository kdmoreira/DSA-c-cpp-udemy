#include <stdio.h>
#include <stdlib.h>

/* Graphs: collections of vertices (nodes) and edges (links): G = (V,E).
Graphs are very useful for solving problems. Many of real-world problems can be converted into graphs.

Concepts: Directed, self-loop (a node connected to itself), parallel edges (two nodes connected
to each other mutually), indegree of a vertex (n of edges pointing at it) and outdegree (n of edges
going out from it), adjacent vertices.
Simple Directed Graph/Digraph: no self-loops or parallel edges.
Graph/Non-Directed Graph: without directions. Nodes have degrees (n of edges connected to it). Assume
that directions can go either way.
Non-connected Graphs: two components (graphs) that aren't connected. The contrary: Connected Graph.
The nodes that are necessary to connect both components are called articulation points. If one more
edge connects the components, there will be no articulation points, they become bi-connected components,
or strongly connected components.
Strongly Connected: from every vertex we can reach any other vertex.
Path: set of all the vertices between a par of vertices, can be shorter-length or longer-length paths.
Cycle/Circular Path/Circuit: starting from a node, going through other vertices and coming back
to where it started.
Directed/Acyclic Graph: if you start from any vertex you can't reach the same vertex in any way.
Topological ordering: directed/acyclic graphs can be arranged linearly such that edges go in a
forward direction only.

Representation of undirected graphs:
1. Adjacency Matrix: if there's an edge between two vertices, 1, else, 0.
For weighed edges, put the weight instead of 1 (cost adjency matrix). Time complexity: n x n = O(n^2)
2. Adjacency List: an array (representing vertices) of linked lists (representing the vertices that
are linked to it by edges). In case there's weight, store them inside each node along with the vertex name.
Time complexity: |V|+2|E|, V for vertices in the array (n) and 2|E| since vertices are represented
twice = n + 2E
3. Compact List: using a simple array whose size is: |V|+2|E|+1 = 0 index vacant, first locations for
each vertex (starting index of the adjacent vertices will go here), next location vacant, start adding
the adjacent vertices for each vertex and add the starting index inside the previous locations.
This means that the first indices (after zero) represent the vertices and the number inside each
location will map to the starting index of their adjacent vertices. Between these locations there will
be a vacant space meant to store the size+1 index of the array to indicate where the last vertex's
adjacency list goes. For weighed graphs, a two-dimensional array would work.
Time complexity: |v|+2|E| = n + 2n = 3n = O(n)

Representation of directed graphs:
1. Adjacency Matrix: similar to undirected graphs, but the edges won't go both ways. Time: O(n^2)
Rows represent the edges going out (out-degree). Columns represent edges coming in (in-degree).
2. Adjacency List: similar to undirected. Not possible to know in-degrees as easily as in an
adjacency matrix, but instead you can make a inverse adjacency list. Time: |V|+|E|, n+e, n+n, O(n)
3. Compact List also possible, just like undirected graphs.

Breadth First Search:
Convert the graph into a tree (not necessarily a binary one) and take the level order.
You can start from any vertex. This tree is called "BFS Spanning Tree". When edges form a
cycle (they appear dotted in the tree) they are called cross edges.
1. Visiting (visiting any vertex) & Exploring (visiting all adjacent vertices).
Enqueue a vertex you visit. Then dequeue it and explore it (enqueueing each one you visit),
then, dequeue the next one and explore it, repeating the process.
There are many possible BF searches, depending on the starting vertices and the exploring order.
Time taken: O(n)

*/

int main(void)
{
    return 0;
}
