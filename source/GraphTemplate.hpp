#include <vector>
#include <string>
#include <map>
#include <bits/stdc++.h> 

// YOU CAN USE ONLY THE VECTORS, STRINGS AND MAPS FOR THIS ASSIGNMENT!

class Graph {
private:
    std::vector<Node> nodes;
    bool isDirected;

public:
    Graph();
    ~Graph();

    Node addNode(Node node, std::iterator<int> pos);
    Node remove(std::iterator<int> pos);
    void prim();
    bool BellmanFord(int source);
};

struct Node {
    std::string label;
    std::map<Node, int> adjacentNodes; // the int is for the weight of the egde
    Node *parent;
    int key;

    Node(label, adjacentNodes, parent, key);

    void addConnection(Node const& new_node);
    void remove_connection(Node node);
    void set_key(int new_key);
    void set_parent(Node* new_parent);
};
    
struct MinHeap{
    Node* left{};
    Node* right{};
    Node* parent{};

    std::vector<Node> priorityQueue(std::vector<Node> nodeVec);
    void heapify(Node root, Node n, std::vector<Node>);
    Node extractMin(std::vector<Node> prioQueue);
};

void printMST(Graph graph);
