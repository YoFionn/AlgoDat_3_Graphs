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
	//for every v of V
    for(int i = 0; i<nodes.size(); i++ ){
		//distance(v) = infinite
        nodes[i].key = 2147483640;
		//no parent
        nodes[i].parent = NULL;
    }
	source.key = NULL;
	//repeat n-1 times
	for(int i=1; i=nodes.size()-1; i++){
		//for every (u,v) of E
		for(auto it= nodes[i].adjacentNodes.begin();it!=nodes[i].adjacentNodes.end();){
			//if distanve of u + weight of (u,v) < distance of v
			if((nodes[i].key + nodes[i].adjacentNodes) < nodes[i].adjacentNodes.key){
				//distance of v = distance of u + weight of (u,v)
				nodes[i].adjacentNodes.key = nodes[i].key + nodes[i].adjacentNodes;
				//parent of v = u
				nodes[i].parent = i;
			}
		}
	}	
	//for every (u,v) aus E
	for(auto it= nodes[i].adjacentNodes.begin();it!=nodes[i].adjacentNodes.end();){
		//if distanve of u + weight of (u,v) < distance of v
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

Node::Node(Node const& copy_node):
    label{copy_node.label},
    adjacentNodes{copy_node.adjacentNodes},
    parent{copy_node.parent},
    key{copy_node.key}{}

Node::Node(label, adjacentNodes, parent, key):
	label{label},
	adjacentNodes{adjacentNodes},
	partent{parent},
	key{key}{}

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

std::string storrage;   //saves the output, must be cleard after using the printTree() funktion
void printTree(Graph graph){
	//iterating through graph nodes
	for(nodes::iterator it == nodes.begin();it != nodes.end(); ++i){
		std::cout<<it<<" -> ";
		//itorating the neighbour
		for(adjacentNodes::iterator i == adjacentNodes.begin(); i != adjacentNodes.end(); ++i){
			std::cout<<i;
			//highlighting the shortest path
			if(BellmanFord(i)){
				std::cout<<"[label="0.4",color=red,penwidth=3.0]";
			}
			std::cout<<std::endl;
		}
	}
}

int main(int argc, char* argv[])
{	//first graph
	Graph graph;
	//creating nodes
	Node node("a",map<>,NULL,2);
	Node node1("b",map<node,3>,node,2);
	Node node2("c",map<node,4>,node,2);
	Node node3("d",map<node,2>,node,2);
	Node node4("e",map<node1,6>,node1,2);
	//adding nodes in graph
	graph.addNode(node);
	graph.addNode(node1);
	graph.addNode(node2);
	graph.addNode(node3);
	graph.addNode(node4);
	//calling prim
	graph.prim();
	//printing graph
	printMST(graph);

	//second graph
	Graph graph1;
	//creating nodes
	Node node5("f",map<>,NULL,2);
	Node node6("g",map<node,1>,node,2);
	Node node7("h",map<node,3>,node,4);
	Node node8("i",map<node,5>,node,1);
	Node node9("j",map<node1,7>,node1,7);
	//adding nodes in graph
	graph.addNode(node5);
	graph.addNode(node6);
	graph.addNode(node7);
	graph.addNode(node8);
	graph.addNode(node9);
	//calling prim
	graph1.prim();
	//printing graph
	printMST(graph1);

	return 0;

	//sorry francesco...we were really struggeling :( 
}
