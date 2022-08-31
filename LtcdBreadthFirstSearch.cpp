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

    vector<Node*> Search(int s, int e){
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