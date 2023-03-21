#include <iostream>
using namespace std;

//// GRAPH THEORY 101

//
// GRAPHS TYPES :

// Base graphs :
// Undirected Graphs -> A Graph of Nodes where Edges have no orientation (nodes connected by an edge point to each other, the edge is doubly-linked)
    // Edges represent connections between two distinct nodes
// Directed Graphs -> A Graph of Nodes where Edges have an orientation (nodes connect to other nodes but not necessarily to each other, the edge is single-link)
    // Edges represent a pointer from node to node
    // As such, in a Directed Graph, nodes can have an edge to themselves, therefore point to themselves
// Weighted Graphs -> A Graph of Nodes where Edges have a weight (weight are arbitrary values assigned to edges to characterize them)
    // Edges are usually denoted as a triplet (u, v, w) with u : where the edge is coming from, v : where the edge is going to, w : the weight of the edge
    // Weighted Graphs can be Directed or Undirected
// All of the above Graphs can have Cycles

// Special Graphs :
// Tree Graphs -> A Tree is an Undirected Graph that has no Cycles
// Rooted Tree Graphs -> A Directed Tree where every node either points away or towards a root node (the root node is either the start or the end of the graph)
    // An Out-Tree is when the root is the start of the graph, and In-Tree is when the root is the end of the graph
// Directed Acyclic Graphs (DAG) -> A Directed Graph with no Cycles
    // All Rooted Trees are DAGs, yet not all DAGs are Rooted Trees
// Bipartite Graph -> A Graph whose Nodes can be divided into two groups such that every edge connects between a node from one group and a node from the other group
    // Another definition is that the graph is colourable by two such that no nodes of the same color connect to each other
// Complete Graph -> A Graph where every node is connected to all other nodes

// Graphs Representation :
// Adjacency Matrix -> A simple way to represent a Graph. An Adjacency Matrix is a 2D Matrix in which each cell represents the weight of going from node i to node j
    // Essentially by looking up this Matrix you can directly know which nodes connect to each other and the weight and type of edge that is between them
    // Adjacency Matrix is good to represent dense graphs (lots of edges) and the lookup for any pair of nodes is O(1), it's also a very simple and straighforward representation
    // Adjacency Matrix is also bad because it takes a lot of space O(n^2) n being the number of nodes in the graph, same goes for the time it takes to iterate on the entire matrix
// Adjacency List -> A way to represent a Graph as a Map of Nodes to a List of Edges
    // Essentially, each Node in the Graph will be mapped to a list of all of its neighbours and the weight associated with the edge between them
    // Adjacency List is good for representing sparse graphs, meaning it is space efficient O(n) and iteration is faster too O(n), in opposition to the Adjacency Matrix
    // But Adjacency List is bad to represent dense graphs in terms of space, the representation is a bit more complex, and to lookup an Edge weight is a bit slow O(e)
    // where e is the number of edges for a certain node
// Edge List -> A way to represent a Graph with its Edges as a List of Edges using the triplet denotation
    // Each entry in the list is a triplet of two nodes and the edge weight between them
    // Since this is neither a Matrix nor a Map, you cannot lookup a certain element in the list using a certain node, meaning this is an unordered data structure
    // Edge List is good because of space and time efficiency just like for the Adjacency List, which means it is good for sparse graphs, it also is a very simple structure
    // Edge List is bad on the other hand for dense graphs in terms of space, and the Edge weight lookup is slow too O(e) where e is the number of edges in the entire Graph
// For any of these Graphs structures, Large Dense Graphs will always be hard to represent efficiently, as the amount of nodes and edges scales the space and time complexities
// of these data structures

//
// GRAPHS ALGORITHMS :

// Common Problems :
// Shortest Path Problem -> Pretty straightforward we need to find the shortest path, if any, from one node to another in our Graph
    // Breadth-First Seach for Unweighted Graphs
    // Dijkstra, Bellman, Floyd
    // A* and many other Algorithms
// Connectivity -> Is there a path between a node and another node in our Graph
    // Any search Algorithm can work, such as Depth-First Search or Breadth-First Search
    // Use the Union Find Data Structure
// Negative Cycles -> Is there a Cycle in our Directed Graph that is impossible to escape from, especially if the Graph is Weighted and you Cycle through it using costs
    // Bellman and Floyd Algorithms
// Strongly Connected Components -> Are there Self-Contained Cycles in our Directed Graph, meaning the smallest sets of Nodes which you can cycle through in a Graph
    // Tarjan and Kosaraju Algorithms
// Traveling Salesman Problem -> A classic problem of finding the shortest route that visits all nodes exactly once and returns to the start node. This is a very complicated problem
    // Held-Karp Algorithm
    // Branch and Bound, Approximation Algorithms
// Bridges -> Are there Bridges or Cut Edges in our Graph, meaning Edges which if we remove would disconnect entire parts of the Graph from each other
    // Identifying Bridges can be important to hint at weak points or bottlenecks in a Graph
    // Articulation Points -> Same as Bridges but with Nodes or Cut Vertices, which if we remove would seperate parts of the Graph from each other
// Minimum Spanning Tree -> In an Undirected Weighted Graph, can we find a Tree that connects all of the Nodes together for a minimal Cost of all the Edges
    // Very useful to find least cost networks for circuit design or transportation networks
    // Kruskal, Prim and Boruvka Algorithms
// Network Flow -> In a Directed Flow Graph, which is essentially a DAG in which all of the edges go in one direction, from a source node to an end node, going through other nodes,
// the graph being weighted, the weight representing how much of something can go through a node to another, find how much flow we can push through the Network
    // Very useful to simulate a flow in any kind of traffic or fluid systems
    // Ford, Edmond and Dinic Algorithms
