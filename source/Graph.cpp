#define CATCH_CONFIG_RUNNER
#include <bits/stdc++.h> 
#include "GraphTemplate.hpp"
//adds node to graph
Node Graph::addNode(Node node, std::iterator<int> pos){
	nodes.insert(pos, node);
}
//removes node from Graph
Node Graph::remove(std::iterator<int> pos){
	nodes.erase(pos);
}
//priority queue needed in prim algorithm 
//works as min heap
std::vector<Node> priorityQueue(std::vector<Node> nodeVec){
	std::vector<Node> tmp;
    std::priority_queue<Node> nodeQueue;
    for(int i=0; i<nodeVec.size(); i++){
        nodeQueue.push(nodeVec[i]);
    }
	while (!nodeQueue.empty()){
		Node tmpNode = nodeQueue.top();
		nodeQueue.pop();
		tmp.push_back(tmpNode);
	}
	
	return tmp;
}
//function to heapify tree(needed for extract)
void MinHeap::heapify(Node root, std::vector<Node> vecci){
	Node max = root;
	Node left = 2*root+1;
	Node right = 2*root+2;
	//left child larger than root
	if(vecci[left] > vecci[max]){
		max = left;
	}
	//if right child is larger than root
	if(vecci[right] > vecci[max]){
		max = right;
	}
	//if max is not root
	if(max != root){
		//swapping root and max
		std::swap(vecci[root], vecci[max])
		//recursive heapify subtree
		heapify(max, vecci);
	}
}
//returns min node from heap(priority Queue) and deletes it
Node Minheap::extractMin(std::vector<Node> prioQueue){
	//root is min value
	Node min = prioQueue[0];
	//copy value of last element into root ->delete last
	prioQueue[0] = prioQueue.back();
	prioQueue.pop_back();

	heapify(min, prioQueue);
	return min;
}

void Graph::prim() {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].key = 2147483647;
        nodes[i].parent = NULL;
    }
	key = 0;
	std::vector<Node> Q = priorityQueue(nodes);
    while(!Q.empty()){
		nodes[i] = extractMin(nodes);
		for (int i = 0; i < nodes.size(); i++){
			if(nodes[i].adjacentNodes && adjacentNodes[i] < nodes[i].adjacentNodes.key){
				nodes[i].adjacentNodes.parent = nodes[i].parent;
				nodes[i].adjacentNodes.key = nodes[i].key
			}
	}
}

bool Graph::BellmanFord(Node source){
    for(int i = 0; i<nodes.size(); i++ ){
        nodes[i].key = 2147483640;
        nodes[i].parent = NULL;
    }
	source.key = NULL;
	for(int i=1; i=nodes.size()-1; i++){
		for(auto it= nodes[i].adjacentNodes.begin();it!=nodes[i].adjacentNodes.end();){
			if((nodes[i].key + nodes[i].adjacentNodes) < nodes[i].adjacentNodes.key){
				nodes[i].adjacentNodes.key = nodes[i].key + nodes[i].adjacentNodes;
				nodes[i].parent = i;
			}
		}
	for(auto it= nodes[i].adjacentNodes.begin();it!=nodes[i].adjacentNodes.end();){
		if((nodes[i].key + nodes[i].adjacentNodes)<nodes[i].adjacentNodes.key){
			return false
		}
	}
	return true
}

Node::Node():
    label{},
    adjacentNodes{},
    parent{ nullptr },
    key{}{}

Node::Node(Node const& copy_node) :
    label{copy_node.label},
    adjacentNodes{copy_node.adjacentNodes},
    parent{copy_node.parent},
    key{copy_node.key}{}

Node::~Node(){}

void Node::addConnection(Node const& new_node){
    adjacentNodes.insert({ new_node, new_node.key });
}
void Node::remove_connection(Node node) {
    adjacentNodes.erase(node);
}
void Node::set_key(int new_key) {
    key = new_key;
}
void Node::set_parent(Node* new_parent) {
    parent = new_parent;
}

int main(int argc, char* argv[])
{
	return 0;
}
