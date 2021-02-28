// Compile : clang adjacencymatrix.c -o adjacencymatrix 
//           ^ Note: You may get a few warnings for passing pointers around, this is okay for this lab.
// Run with: ./adjacencymatrix
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// These defines do a text replacement
// everytime the string 'ROWS' and 'COLUMNS'
// are found in this specific source file.
// You can play with these values.
#define ROWS 5
#define COLUMNS 5

/*  ============= Tutorial on Graph format ============
    You are given a randomly generated graph that looks 
    of the form:

    0 0 1 1 1
    1 0 0 1 1
    0 1 0 1 1
    1 0 0 0 0
    1 0 1 1 0

    You can think of the graph with labels for each of
    the nodes (sometimes called vertices) more clearly below:

               0 1 2 3 4
               ---------  
    node 0:    0 0 1 1 1
    node 1:    1 0 0 1 1
    node 2:    0 1 0 1 1
    node 3:    1 0 0 0 0
    node 4:    1 0 1 1 0

    A '1' represents a connection to a node, and a 0
    means it is not connected.

               0 1 2 3 4
               ---------  
    node 0:    0 0 1 1 1
    node 1:    1 0 0 1 1
    node 2:    0 1 0 1 1
    node 3:    1 0 0 0 0
    node 4:    1 0 1 1 0

    In the above, '0' is connected to 2, 3, and 4.
    '1' is connected to '0', '3', and '4'.
    etc.

    The number of connections a node has is its 'degree'
*/



// This function generates a random graph
// Note: For the purpose of this lab,
//       we do not seed the random number generator
//      so we can generate the same graph over
//      and over again.
void generateGraph(int* g){
    // Uncomment the line below if you want
    // to generate a random graph each time.
    //srand(time(NULL));  
    int i,j;
    for(i=0; i < ROWS; i++){
        for(j=0; j < COLUMNS; j++){
            if(i==j){
                g[i*COLUMNS+j] = 0; // Why this condition?
            }else{
                g[i*COLUMNS+j] = rand() % 2;
            }
        }
    }
}

// This function will print out the adjaceny
// matrix for a graph.
void printGraph(int* g){ 
    int i,j;
    for(i=0; i < ROWS; i++){
        for(j=0; j < COLUMNS; j++){
            printf("%d ",g[i*COLUMNS+j]);
        }
        printf("\n");
    }
}

// Compute 'degree' of a node
// For a given node 'n' in an adjaceny matrix,
// compute the degree.
int nodeDegree(int* g, int node){
	int number_Degrees = 0;
	for(int j = 0; j < COLUMNS; j ++){
		if(g[node*ROWS+j] == 1){
			number_Degrees ++;
		}
	}
    return number_Degrees;
}


// Figure out if two nodes are connected
// Returns a 1 if node1 is connected to node 2
int isConnected(int* g, int node1, int node2){
	if(g[node1*ROWS+node2*COLUMNS] == 1){
		return 1;
	} else{
	    return 0;
	}
}

int main(){
 
    int g_testgraph[ROWS][COLUMNS];
    // Generate a random graph
    generateGraph((&g_testgraph[0][0]));
    // Print out the graph
    printGraph((&g_testgraph[0][0]));
    // Print out the degree of each of the
    // five nodes
    int i;
    for(i = 0; i < COLUMNS; ++i){
        printf("node %d degree= %d\n",i,nodeDegree(&g_testgraph[0][0],i));
    }
    // Check which nodes '0' is connected to
    printf("Node 0 connections:");
    int j;
    for(j =0; j < COLUMNS; ++j){
        printf("%d ",isConnected(&g_testgraph[0][0],0,j));
    }

    return 0;
}
