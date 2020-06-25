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
    void BellmanFord(int source);
<<<<<<< HEAD
 
=======

>>>>>>> 24ea7fdc9f9fb08d37df5aaaa5cb3269c47db72b
};

struct Node {
    std::string label;
    std::map<Node, int> adjacentNodes; // the int is for the weight od the egde
<<<<<<< HEAD
    Node *parent;
=======
    Node* parent;
>>>>>>> 24ea7fdc9f9fb08d37df5aaaa5cb3269c47db72b
    int key; // aka key

    void addConnection(Node const& new_node);
    void remove_connection(Node node);
    void set_key(int new_key);
    void set_parent(Node* new_parent);
};
<<<<<<< HEAD
    
struct MinHeap{
=======

struct MinHeap {
>>>>>>> 24ea7fdc9f9fb08d37df5aaaa5cb3269c47db72b
    Node* left{};
    Node* right{};
    Node* parent{};

    std::vector<Node> priorityQueue(std::vector<Node> nodeVec);
    void heapify(Node root, Node n, std::vector<Node>);
    Node extractMin(std::vector<Node> prioQueue);
};