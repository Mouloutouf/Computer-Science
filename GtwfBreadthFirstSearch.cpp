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