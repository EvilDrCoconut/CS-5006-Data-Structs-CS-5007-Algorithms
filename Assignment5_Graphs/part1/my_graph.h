// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H
//#include "my_dll.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


// Create a neighbor data structure to server as the neighbor's list.
// In our case, we will stores 'integers' as our neighbors that 
// corresponding to the data that the actual nodes store.
typedef struct neighbor{
	int data;
	struct neighbor * next;
}neighbor_t;

// Create a node data structure to store data within
// our graph. In our case, we will stores 'integers'
// as our data in the nodes
typedef struct node{
	int data;
	struct node* next;
	neighbor_t* inNeighbor;
	neighbor_t* outNeighbor;
	int visited;
}node_t;

// Create a graph data structure
// Our graph keeps track of the number of nodes, the number of edges and an array
// of all the nodes in the graph, and the maximum number of nodes we store in our graph.
typedef struct graph{
	int numNodes;		
        int numEdges;
	node_t* nodes;	 //an array of nodes storing all of our nodes.
}graph_t;

// struct for node in created queue
typedef struct qnode{
	node_t* data;
	struct qnode* next;
}qnode_t;

// struct for queue used
typedef struct queue{
	int size;
	qnode_t* front;


}queue_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
graph_t* create_graph(){
	// Modify the body of this function as needed.
	graph_t* myGraph= (graph_t*)malloc(sizeof(graph_t));	
	myGraph->numNodes = 0;
	myGraph->numEdges = 0;
	myGraph->nodes = NULL;
	return myGraph;
}


// create an empty queue
queue_t* create_queue(){
	queue_t* myQueue = (queue_t*)malloc(sizeof(queue_t));
	myQueue->size = 0;
	myQueue-> front = NULL;

	if(myQueue == NULL){
		printf("NULL queue");
		return myQueue;
	}
	return myQueue;
}

// Graph Empty
// Check if the graph is empty
// Returns 0 if true (The graph is completely empty, i.e. numNodes == 0 )
// Returns -1 if false (the graph has at least one node)
int graph_empty(graph_t* g){
	if(g->numNodes == 0){
		return 0;
	}
	return -1;
}

//Returns 0 if the node with value is in the graph, otherwise returns -1;
int contains_node( graph_t * g, int value){
	if(g->numNodes == 0 || g == NULL){
		return -1;
	}
	node_t* temp = g->nodes;
	for(int i = 0; i < g->numNodes; i ++){
		if(temp->data == value){
			return 0;
		}
		temp = temp->next;
	}

   	return -1;
}

//Returns 0 if an edge from source to destination exists, -1 otherwise.
int contains_edge( graph_t * g, int source, int destination){
	if(g->numNodes == 0 || g == NULL){
		return -1;
	}
	node_t* temp = g->nodes;
	for(int i = 0; i < g->numNodes; i++){
		if(temp->data == source){
			break;
		}
		temp = temp->next;
	}
	
	if(temp->outNeighbor == NULL){
		return 1;
	}

	if(temp->data != source){
		return 1;
	}

	neighbor_t* temp2 = temp->outNeighbor;
	if(temp2->data == destination){
		return 0;
	}
	while(temp2->next != NULL){
		temp2 = temp2->next;
		if(temp2->data == destination){
			return 0;
		}
	
	}
	return 1;
}

// Returns the number of neighbors for value.
int numNeighbors( graph_t * g, int value ){	
	if(g->numNodes == 0 || g == NULL){
		return -1;
	}
	node_t* temp = g->nodes;
	for(int i = 0; i < g->numNodes; i++){
		if(temp->data == value){
			break;
		}
		temp = temp->next;
	}
	if(temp->outNeighbor == NULL){
		return 0;
	}
	int numberOfNeighbors = 1;
	neighbor_t* temp2 = temp->outNeighbor;
	while(temp2->next != NULL){
		temp2 = temp2->next;
		if(temp2->next == NULL){
			numberOfNeighbors ++;
			return numberOfNeighbors;
		}
		numberOfNeighbors ++;
	}
	return numberOfNeighbors;
}


// method to count in neighbors
int numInNeighbor(graph_t* g, int value){
	if(g->numNodes == 0 || g == NULL){
		return -1;
	}
	node_t* temp = g->nodes;
	for(int i = 0; i < g->numNodes; i++){
		if(temp->data == value){
			break;
		}
		temp = temp->next;
	}
	if(temp->inNeighbor == NULL){
		return 0;
	}
	int numberOfNeighbors = 1;
	neighbor_t* temp2 = temp->inNeighbor;
	while(temp2->next != NULL){
		temp2 = temp2->next;
		if(temp2->next == NULL){
			numberOfNeighbors ++;
			return numberOfNeighbors;
		}
		numberOfNeighbors ++;
	}
	return numberOfNeighbors;

}


// Returns the number of nodes in the graph
unsigned int graph_num_nodes(graph_t* g){
	return g->numNodes;
}

// Graph Size
// Returns the number of edges in the graph
unsigned int graph_num_edges(graph_t* g){
	return g->numEdges;
}

// Adds a new node withe the correspoding item in the graph.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// Duplicates nodes should not be added. For a duplicate node returns 0.
int graph_add_node(graph_t* g, int item){
	int existingNodeCheck = contains_node(g, item);
	if(existingNodeCheck == 0){
		return 0;
	}

	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = item;
	newNode->next = NULL;
	newNode->inNeighbor = NULL;
	newNode->outNeighbor = NULL;
	newNode->visited = 0;
	if(newNode == NULL){
		return -1; 
	}
	
	if(g->nodes == NULL){
		g->nodes = newNode;
		g->numNodes ++;
		return 0;
	} else{
		node_t* temp = g->nodes;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		g->numNodes ++;
		return 0;
	}
	return -1;
}

// Removes the node from the graph and the corresponding edges connected 
// to the node.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (the node to be removed doesn't exist in the graph).
int graph_remove_node(graph_t* g, int item){
	int existingNodeCheck = contains_node(g, item);
	if(existingNodeCheck == -1){
		return -1;
	}

	if(g->numNodes == 1){
		free(g->nodes);
		g->nodes = NULL;
		g->numNodes --;
		return 0;
	}
	node_t* temp = g->nodes;
	if(temp->data == item){
		g->nodes = temp->next;
		free(temp);
		return 0;
	}
	for(int i = 0; i < g->numNodes; i ++){
		node_t* temp2 = temp->next;
		if(temp2->data == item){
			temp->next = temp2->next;
			free(temp2);
			g->numNodes --;
			return 0;
		}
		temp = temp->next;
		i ++;
	}
	return -1; 
}

//Adds an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//Otherwise it returns 0 ( even for trying to add a duplicate edge )
int graph_add_edge(graph_t * g, int source, int destination){
	int checkExistingEdges = contains_edge(g, source, destination);
	if(checkExistingEdges == 0 || checkExistingEdges == -1){
		printf("check6");
		return 0;
	}
	if(g->numNodes == 0 || g == NULL){
		return -1;
	}
	node_t* temp = g->nodes;
	for(int i = 0; i < g->numNodes; i++){
		if(temp->data == source){
			break;
		}
		temp = temp->next;
	}
	neighbor_t* newNeighbor = (neighbor_t*)malloc(sizeof(neighbor_t));
	newNeighbor->data = destination;
	newNeighbor->next = NULL;
	if(newNeighbor == NULL){
		return -1;
	}
	if(temp->outNeighbor == NULL){
		temp->outNeighbor = newNeighbor;
	} else{
		neighbor_t* temp2 = temp->outNeighbor;
		while(temp2->next != NULL){
			temp2 = temp2->next;
		}
		temp2->next = newNeighbor;
	}


	node_t* temp3 = g->nodes;
	for(int j = 0; j < g->numNodes; j++){
		if(temp3->data == destination){
			break;
		}
		temp3 = temp3->next;
	}
	neighbor_t* newNeighbor2 = (neighbor_t*)malloc(sizeof(neighbor_t));
	newNeighbor2->data = source;
	newNeighbor2->next = NULL;
	if(newNeighbor2 == NULL){
		return -1;
	}

	if(temp3->inNeighbor == NULL){
		temp3->inNeighbor = newNeighbor2;
		g->numEdges ++;
		return 0;
	} else{
		neighbor_t* temp4 = temp3->inNeighbor;
		while(temp4->next != NULL){
			temp4 = temp4->next;
		}
		temp4->next = newNeighbor2;
		g->numEdges ++;
		return 0;
	}

	return -999999;
}

//Removes an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//If no such edge exists also returns -1.
//Otherwise it returns 0
int graph_remove_edge(graph_t * g, int source, int destination){
	if(g->numNodes == 0 || g == NULL){
		return -1;
	}
	int existingEdgeCheck = contains_edge(g, source, destination);
	if(existingEdgeCheck == -1 || existingEdgeCheck == 1){
		return -1;
	}

	int sourceCheck = 0; int destinationCheck = 0;
	node_t* temp = g->nodes;
	node_t* sourceTemp; node_t* destinationTemp;
	for(int i = 0; i < g->numNodes; i ++){
		if(temp->data == source){
			sourceCheck = 1;
			sourceTemp = temp;
		} else if(temp->data == destination){
			destinationCheck = 1;
			destinationTemp = temp;
		}
		if(sourceCheck == 1 && destinationCheck ==1){
			break;
		}
		temp = temp->next;	
	}	
	if(sourceCheck != 1 || destinationCheck != 1){
		return -1;
	}


	neighbor_t* temp2 = sourceTemp->outNeighbor;
	if(temp2->data == destination){
		sourceTemp->outNeighbor = temp2->next;
		free(temp2);
	}

	while(temp2->next != NULL){
		neighbor_t* temp3 = temp2->next;
		if(temp3->data == destination){
			temp2->next = temp3->next;
			free(temp3);
			break;
		}
		temp2 = temp2->next;
	}
	//removing from other destination node
	neighbor_t* temp4 = destinationTemp->inNeighbor;
	if(temp4->data == source){
		destinationTemp->inNeighbor = temp4->next;
		free(temp4);
		g->numEdges --;
		return 0;
	}
	while(temp4->next != NULL){
		neighbor_t* temp5 = temp4->next;	
		if(temp5->data == source){
			temp4->next = temp5->next;
			free(temp5);
			g->numEdges --;
			return 0;
		}
		temp4 = temp4->next;
	}
	return -1;
}

//Returns an int array of all the neighbors of the node with data=value.
int* getNeighbors( graph_t * g, int value ){
		
	node_t* temp = g->nodes;
	for(int i = 0; i < g->numNodes; i ++){
		if(temp->data == value){
			break;
		}
		temp = temp->next;
	}
	int neighborCount = numNeighbors(g, value);
	int* neighbors = (int*)malloc(neighborCount * sizeof(int));
	
	neighbor_t* temp2 = temp->outNeighbor;
	for(int j = 0; j < numNeighbors(g, value); j ++){
		neighbors[j] = temp2->data;
		temp2 = temp2->next;
	}

	return neighbors;
}


	

// enqueue method
int enqueue(queue_t * q, node_t* node){
	qnode_t* newqNode = (qnode_t*)malloc(sizeof(qnode_t));
	newqNode->data = node;
	newqNode->next = NULL;
	if(newqNode == NULL){
		return -1;
	}

	
	if(q->front == NULL){
		q->front = newqNode;
		q->size ++;
		return 0;
	}
	qnode_t* qtemp = q->front;
	while(qtemp->next != NULL){
		qtemp = qtemp->next;
	}
	qtemp->next = newqNode;
	q->size ++;
	return 0;

}

// method to dequeue
node_t* dequeue(queue_t* q){
	if(q->size == 0){
		return NULL;
	} else{
		qnode_t* qtemp = q->front->next;
		node_t* ret = q->front->data;
		free(q->front);
		q->front = qtemp;
		return ret;
	}
}

// method to check queue size
int queue_size(queue_t * q){
	if(q == NULL){
		return -1;
	}
	return q->size;
}

// Prints the the graph using BFS
// For NULL or empty graph it should print nothing. 
void graph_print(graph_t * g){
//	queue_t* q = create_queue();
//	node_t* temp = g->nodes;
//	
//	enqueue(q, temp);
//	temp->visited = 1;

//	while(temp->next != NULL){
//		node_t* tempNull = temp->next;
//		if(tempNull->inNeighbor == NULL){
//			enqueue(q, tempNull);
//			tempNull->visited = 1;
//		}
//		temp = temp->next;
//	}
	// checks if current queue has all nodes on it, then prints (case of no neighbors)
//	if(q->size == g->numNodes){
//		int i = 0;
//		while(i < q->size){
//			qnode_t* qtemp = q->front;
//			printf("%d", qtemp->data->data);
//			i ++;
//			dequeue(q);
//		}
//		printf("\n");
//		free(q);
//		return;

	if(g->numNodes == 0 || g == NULL){
		printf("");
	}

	node_t* temp = g->nodes;
	for(int i = 0; i < g->numNodes; i ++){
		printf("%d, ", temp->data);
		temp = temp->next;
	}		
	printf("\n");	

}



// is_rechable function to see if a node is reachable
//int is_reachable(graph_t* g, int source, int dest){
//	node_t* list[g->numNodes];
//	node_t* temp = g->nodes;
//	for(int i = 0; i < g->numNodes; i ++){
//		if(temp->data == source){
//			break;
//		}
//		temp = temp->next;
//	}
//
//	if(temp->outNeighbor == NULL){
//		return -1;
//	}
//	neighbor_t* temp2 = temp->outNeighbor;
//	while(temp2 != Null){
//		
//	}
//
//}


// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_graph(graph_t* g){

	while( g->numNodes > 0){
		node_t* temp = g->nodes;
		if(temp->outNeighbor != NULL){
			neighbor_t* outTemp = temp->outNeighbor;
			if(outTemp->next == NULL){
				free(temp->outNeighbor);
			}
			while(outTemp->next != NULL){
			neighbor_t* temp2 = outTemp->next;
				free(outTemp);
				outTemp = temp2;
				if(outTemp->next == NULL){
					free(outTemp);
					break;
				}
			}
		}

		if(temp->inNeighbor != NULL){
			neighbor_t* inTemp = temp->inNeighbor;
			if(inTemp->next == NULL){
				free(temp->inNeighbor);
			}
			while(inTemp->next != NULL){
				neighbor_t* temp3 = inTemp->next;
				free(inTemp);
				inTemp = temp3;
				if(inTemp->next == NULL){
					free(inTemp);
					break;
				}
			}
		}

		temp = g->nodes->next;
		free(g->nodes);
		g->nodes = temp;
		g->numNodes --;
	}

	free(g);
}



#endif
