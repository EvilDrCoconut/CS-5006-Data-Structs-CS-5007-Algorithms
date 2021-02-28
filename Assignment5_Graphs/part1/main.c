// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// ====================================================
// ================== Program Entry ===================
// ====================================================

void testFirst(graph_t* g){
	printf("Is graph empty? -1 = No:  0 = Yes: %d \n", graph_empty(g));
	printf("Adding a new node; 0 means success: %d \n", graph_add_node(g, 1));
	printf("Number of nodes in graph: %d \n", graph_num_nodes(g));
	printf("Adding a new node; 0 means success: %d \n", graph_add_node(g, 2));
	printf("Adding a new node; 0 means success: %d \n", graph_add_node(g, 3));
	printf("Is graph empty? -1 = No:  0 = Yes: %d \n", graph_empty(g));
	printf("Number of nodes in graph: %d \n", graph_num_nodes(g));
	printf("Printing graph's nodes------------------------- \n");
	graph_print(g);
	printf("----------------------------------------------- \n");
	printf("Does graph have a node 3? 0 = Yes: %d \n", contains_node(g, 3));
	printf("Removing node 3; 0 means success: %d \n", graph_remove_node(g, 3));	
	printf("Number of nodes in graph: %d \n", graph_num_nodes(g));
	printf("Removing node 2; 0 means success: %d \n", graph_remove_node(g, 2));	
	printf("Does graph have a node 2? 0 = Yes: %d \n", contains_node(g, 2));
	printf("Removing node 1; 0 means success: %d \n", graph_remove_node(g, 1));
	printf("Is graph empty? -1 = No:  0 = Yes: %d \n", graph_empty(g));
	printf("Freeing graph.... \n");

}

void testSecond(graph_t* g){
	printf("Adding a new node; 0 means success: %d \n", graph_add_node(g, 1));
	printf("Adding a new node; 0 means success: %d \n", graph_add_node(g, 2));
	printf("Adding a new node; 0 means success: %d \n", graph_add_node(g, 3));
	printf("Adding a new node; 0 means success: %d \n", graph_add_node(g, 4));
	printf("Number of nodes in graph: %d \n", graph_num_nodes(g));
	printf("Printing graph's nodes------------------------- \n");
	graph_print(g);
	printf("----------------------------------------------- \n");
	printf("Number of edges in node 1; -1 means no nodes: %d \n", numNeighbors(g, 1));
	printf("Adding a new edge to node 1; 0 means success: %d \n", graph_add_edge(g, 1, 2));
	printf("Adding a new edge to node 1; 0 means success: %d \n", graph_add_edge(g, 1, 3));
	printf("Adding a new edge to node 1; 0 means success: %d \n", graph_add_edge(g, 2, 4));
	printf("Adding a new edge to node 1; 0 means success: %d \n", graph_add_edge(g, 3, 4));
	printf("Number of out neighbors for node 1: %d \n", numNeighbors(g, 1));
	printf("Number of out neighbors for node 2: %d \n", numNeighbors(g, 2));
	printf("Number of out neighbors for node 3: %d \n", numNeighbors(g, 3));
	int* neighbors1 = getNeighbors(g, 1);
	int* neighbors2 = getNeighbors(g, 2);
	int* neighbors3 = getNeighbors(g, 3);
	printf("The neighbors of node 1 is: %d and %d \n", neighbors1[0], neighbors1[1]);
	printf("The neighbors of node 2 is: %d \n", neighbors2[0]);
	printf("The neighbors of node 3 is: %d \n", neighbors3[0]);
	printf("Does edge exist between 1 and 2: 0 is a Yes, 1 is a No: %d \n", contains_edge(g, 1, 2));
	printf("Does edge exist between 1 and 3: 0 is a Yes, 1 is a No: %d \n", contains_edge(g, 1, 3));
	printf("Does edge exist between 1 and 4: 0 is a Yes, 1 is a No: %d \n", contains_edge(g, 1, 4));
	printf("Does edge exist between 2 and 4: 0 is a Yes, 1 is a No: %d \n", contains_edge(g, 2, 4));
	printf("Does edge exist between 2 and 3: 0 is a Yes, 1 is a No: %d \n", contains_edge(g, 2, 3));
	printf("Printing graph's nodes------------------------- \n");
	graph_print(g);
	printf("----------------------------------------------- \n");
	printf("Removing an edge from node 1; 0 means success: %d \n", graph_remove_edge(g, 1, 3));
	printf("Number of out neighbors for node 1: %d \n", numNeighbors(g, 1));
	printf("Removing an edge from node 1; 0 means success: %d \n", graph_remove_edge(g, 1, 2));	
	printf("Removing an edge from node 2; 0 means success: %d \n", graph_remove_edge(g, 2, 4));
	printf("Number of out neighbors for node 2: %d \n", numNeighbors(g, 2));


	printf("Freeing graph.... \n");

}


int main(){
    graph_t * testGraph = create_graph();
    testFirst(testGraph);
    free_graph(testGraph);    
    graph_t * testGraph2 = create_graph();
    testSecond(testGraph2);
    free_graph(testGraph2);    

    return 0;
}
