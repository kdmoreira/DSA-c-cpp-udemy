#include <stdio.h>
#include <stdlib.h>

/* Graphs: collections of vertices (nodes) and edges (links): G = (V,E).
Graphs are very useful for solving problems. Many of them can be converted into a graph.

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

*/

int main(void)
{
    return 0;
}
