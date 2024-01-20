#include <iostream>
using namespace std;

// The TSP can be seen as this problem :
// Given a complete graph (you can go from one node to any other node) with weighted edges (but these connexions each have a cost)
// what is the Hamiltonian cycle (the path that visits every node once) of minimum cost ?

// The best graph representation for this problem is the Adjacency Matrix, which is best to represent dense graphs with lots of edges,
// and in our case, since it is a complete graph, it fits exactly our purpose.
// An Adjacency Matrix is essentially a 2D array in which each value represents the cost of going from one node to another.

// Finding the optimal solution to this problem is next to impossible. It is a NP-Hard problem so we either have the computation power to find the solution,
// or we will try and get an approximate good enough solution.

// The first way to do this is with computation power, with the Brute Force solution where we test every possible route then return the best cost. This takes O(n!).
// Obviously this scales extremely fast, so only very small graphs can be solved this way.

// The second way to do this is with an approximate solution, using Dynamic Programming. This will take us to O(n^2.2n). It is still not that good,
// but a standard modern computer will be able to solve this for graphs up to 23 nodes withtout trouble.

// Actually, the brute force solution, using n! is more efficient for small graphs up until 7 or 8 noddes, then the dynamic solution, with n^2.2n becomes more efficient.

// But it only becomes efficient up until 32 nodes max, after that, it takes way too much time for a normal computer to perform this algorithm.