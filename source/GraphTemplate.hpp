#include <vector>
#include <string>
#include <map>

// YOU CAN USE ONLY THE VECTORS, STRINGS AND MAPS FOR THIS ASSIGNMENT!

class Graph {
private:
    std::vector<Node> nodes;
    MinHeap *minPriorityQueue;
    bool isDirected;

public:
    Graph(/* args */);
    ~Graph();

    // TODO: implement additional constructors
    // TODO: implement method for adding a node
    // TODO: implement method for removing a node


    void prim() {
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].key = 2147483647;
            nodes[i].parent = NULL;
        }
        minPriorityQueue.key = 0;
        MinHeap Q = minPriorityQueue*;
        while {Q != NULL}
    }


    // TODO: implement Bellman-Ford


    // TODO: implement printGraph function that generates a file written using the dot format
};

class Node {
private: 
    std::string label;
    std::map<Node, int> adjacentNodes; // the int is for the weight od the egde
    Node *parent;
    int key;
public:
    Node() :
        label{},
        adjacentNodes{},
        parent{ nullptr },
        key{}{};

    Node(Node const& copy_node) :
        label{copy_node.label},
        adjacentNodes{copy_node.adjacentNodes},
        parent{copy_node.parent},
        key{copy_node.key}{}

    ~Node();

    void add_connection(Node const& new_node){
        adjacentNodes.insert({ new_node, new_node.key });
    }
    void remove_connection(Node node) {
        adjacentNodes.erase(node);
    }
    void set_key(int new_key) {
        key = new_key;
    }
    void set_parent(Node* new_parent) {
        parent = new_parent;
    }
};

class MinHeap {
private:
    MinHeapNode* root;

public:
    MinHeap(/* args */);
    ~MinHeap();


    // TODO: implement method for restructuring the min-priority Queue
    // TODO: implement method for extracting the smaller element from the min-priority Queue
};

struct MinHeapNode {    //were using a struct becouse no constructors are nassasary
    Node* node;
    MinHeapNode* parent;
    MinHeapNode* left;
    MinHeapNode* right;
};