#include <vector>
#include <queue>
#include <map>
using namespace std;

class BreadthFirstSearch{
public:
    struct Node{
        int index;
        vector<Node*> neighbours;

        Node()
        {
        }
        Node(int i){
            index = i;
        }
        Node(int i, vector<Node*> ngh){
            index = i;
            neighbours = ngh;
        }

        void AddNeighbour(Node* n){
            neighbours.push_back(n);
        }
    };

    struct Graph{
        map<int, Node> nodes;
        int size;

        Graph(){
            nodes = map<int, Node>();
        }
        Graph(vector<Node>& g){
            for(Node& n : g){
                nodes.emplace(n.index, n);
            }
            size = g.size();
        }

        Node* Get(int i){
            return &nodes[i];
        }
        void Add(Node& n){
            nodes.emplace(n.index, n);
            size++;
        }
        void Add(int i){
            nodes.emplace(i, Node(i));
            size++;
        }
    };

    Graph graph;
    int size;

    BreadthFirstSearch()
    {
    }
    BreadthFirstSearch(Graph& g){
        size = g.size;
        graph = g;
    }

    vector<Node*> SearchPath(int s, int e){
        vector<Node*> p = Solve(s);
        return Reconstruct(s, e, p);
    }
    vector<Node*> Solve(int s){
        queue<int> q;
        q.push(s);

        vector<bool> v(size, false);
        v[s] = true;

        vector<Node*> p(size, nullptr);

        while (q.empty() == false){
            int i = q.front();
            q.pop();

            Node* node = graph.Get(i);
            for (Node* n : node->neighbours){
                if (v[n->index] == false){
                    q.push(n->index);
                    v[n->index] = true;
                    p[n->index] = node;
                }
            }
        }
        return p;
    }
    vector<Node*> Reconstruct(int s, int e, vector<Node*>& p){
        vector<Node*> path;
        for (Node* n = graph.Get(e); n != nullptr; n = p[n->index]){
            path.push_back(n);
        }

        reverse(path.begin(), path.end());
        
        if (path[0] == graph.Get(s)){
            return path;
        }
        return vector<Node*>();
    }
};

class GridBreadthFirstSearch{
    vector<vector<char>> grid;
    int rows, columns;

    int startX, startY;

    queue<int> rowQueue, columnQueue;
    vector<vector<bool>> visitedNodes;

    // Initialize rows and columns left right down and up directions to look for neighbours
    int rowDirections[4] = {-1, 1, 0, 0}, columnDirections[4] = {0, 0, 1, -1};

    // Initialize two nodes counter to check our progress from one layer to the other
    int nodesLeftInLayer = 1, nodesInNextLayer = 0;
public:
    GridBreadthFirstSearch()
    {
    }
    GridBreadthFirstSearch(vector<vector<char>>& g){
        grid = g;
        rows = g.size();
        columns = g[0].size();
    }

    int SearchPath(int x, int y){
        // Initialize start node coordinates
        startX = x;
        startY = y;

        // Initialize a visited nodes 2D array to track the nodes we go through
        visitedNodes = vector<vector<bool>>(rows, vector<bool>(columns));

        // Add the start node to the search queues and mark it as visited
        rowQueue.push(startX);
        columnQueue.push(startY);
        visitedNodes[startX][startY] = true;

        // Initialize the path length and the path finding status
        int moves = 0;
        bool end = false;

        // Loop through the search queues
        while (rowQueue.size() > 0){
            // Process the next node and remove it from the search queues
            int nodeX = rowQueue.back(), nodeY = columnQueue.back();
            rowQueue.pop();
            columnQueue.pop();

            // Found the end node update path finding status and exit the loop
            if (grid[nodeX][nodeY] == 'E'){
                end = true;
                break;
            }

            // Check the node neighbours and add them to the search queues
            visitNeighbours(nodeX, nodeY);

            // If no more nodes in current layer switch to next layer of nodes
            if (nodesLeftInLayer == 0){
                nodesLeftInLayer = nodesInNextLayer;
                nodesInNextLayer = 0;
            }
        }

        // Path found return its length
        if (end){
            return moves;
        }
        // No path found
        return -1;
    }
    void visitNeighbours(int x, int y){
        for (int i = 0; i < 4; ++i){
            // Get Neighbour coordinates with the directions
            int nx = x + rowDirections[i];
            int ny = y + columnDirections[i];

            // Out of bounds coordinates
            if (nx < 0 || ny < 0 || nx >= rows || ny >= columns){
                continue;
            }
            // Already visited node or obstacle node
            if (visitedNodes[nx][ny] == true || grid[nx][ny] == '#'){
                continue;
            }

            // Add the node to the search queues
            rowQueue.push(nx);
            columnQueue.push(ny);
            // Mark node as visited and add it to the next layer
            visitedNodes[nx][ny] = true;
            nodesInNextLayer++;
        }
    }
};

// Types of Graphs :

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