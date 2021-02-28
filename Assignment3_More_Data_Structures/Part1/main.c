// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.



// ====================================================
// ================== Program Entry ===================
// ====================================================

void testZero(dll_t* l){
	printf("Is the dll empty? 1 = Yes; 0 = No: %d \n", dll_empty(l));
	printf("dll's current size: %d \n", dll_size(l));
	printf("Attemping to remove a node: %d \n", dll_remove(l, 1));
	printf("Attempting to get node: %d \n", dll_get(l, 1));
	printf("Attempting to insert node: %d \n", dll_insert(l, 2, 20));
	printf("Attempting to remove front node: %d \n", dll_pop_front(l));
	printf("Attempting to remove back node: %d \n", dll_pop_back(l));
	printf("Adding a node to the back: %d \n", dll_push_back(l, 20));
	printf("Removing back node: %d \n", dll_pop_back(l));
	printf("Adding a node to the front %d \n", dll_push_front(l, 10));
	printf("Removing node from the front: %d \n", dll_pop_front(l));
	printf("Test Zero Finished__________________________________________ \n");
}


void testFirst(dll_t* l){
	printf("Is the dll empty? Yes = 1: No = 0: %d \n", dll_empty(l));
	printf("Adding a node: %d \n", dll_push_front(l, 20));
	printf("Adding a node: %d \n", dll_push_back(l, 30));
	printf("Is the dll empty? Yes = 1: No = 0: %d \n", dll_empty(l));
	printf("Getting first node, node's data is: %d \n", dll_get(l, 0));
	printf("Test One Finished__________________________________________ \n");
}

void testSecond(dll_t* l){

	printf("dll's current size: %d \n", dll_size(l));
	printf("Adding node to back: %d \n", dll_push_front(l, 10));
	printf("Adding node to back: %d \n", dll_push_back(l, 40));
	printf("Retrieving node 3's data: %d \n", dll_get(l, 2));
	printf("dll's current size: %d \n", dll_size(l));
	printf("Removing last node, node's data is: %d \n", dll_pop_back(l));
	printf("Removing first node, node's data is: %d \n", dll_pop_front(l));
	printf("dll's current size: %d \n", dll_size(l));
	printf("All curent nodes' data: %d, %d \n", dll_get(l, 0), dll_get(l, 1));
	dll_push_front(l, 10);
	printf("Adding a node to the front \n");
	printf("Front node's data: %d \n", dll_get(l, 0));
	printf("dll's current size: %d \n", dll_size(l));
	printf("All current nodes' data: %d, %d, %d \n", dll_get(l, 0), dll_get(l, 1), dll_get(l, 2));
	dll_push_back(l, 40);
	printf("Adding a node to the back \n");
	printf("Back node's data: %d \n", dll_get(l, 3));
	printf("Test Two Finished__________________________________________ \n");
}

void testThird(dll_t* l){
	printf("dll's current size: %d \n", dll_size(l));
	printf("All curent nodes' data: %d, %d, %d, %d \n", dll_get(l, 0), dll_get(l, 1), dll_get(l, 2), dll_get(l, 3));
	printf("Inserting new node between nodes 2 and 3; 1 means success: %d \n", dll_insert(l, 2, 25));
	printf("All current nodes' data: %d, %d, %d, %d, %d \n", dll_get(l, 0), dll_get(l, 1), dll_get(l, 2), dll_get(l, 3), dll_get(l,4));
	printf("New nodes data, which is at postion 4, is: %d \n", dll_get(l, 3));
	printf("dll's current size: %d \n", dll_size(l));
	printf("Removing node 4, its data is: %d \n", dll_remove(l, 3));
	printf("All current nodes' data: %d, %d, %d, %d \n", dll_get(l, 0), dll_get(l, 1), dll_get(l, 2), dll_get(l, 3));
	printf("dll's current size: %d \n", dll_size(l));
	printf("Is dll empty? Yes = 1: No = 0: %d \n", dll_empty(l));	
	printf("Test Three Finished__________________________________________ \n");
}

void testFourth(dll_t* l){
	printf("dll's current size: %d \n", dll_size(l));
	printf("Attempting to retrieve the sizth item, -1 means failure: %d \n", dll_get(l, 5));
	printf("Attempting to retrieve the node at -3, -1 means failure: %d \n", dll_get(l, -3));
	printf("Attempting to insert node at postion 8, -1 means failure: %d \n", dll_insert(l, 8, 80));
	printf("Attempting to insert node at position -8, -1 means failure: %d \n", dll_insert(l,-8,10));
	printf("Attempting to remove node at postion 8, -1 means failure: %d \n", dll_remove(l,8));
	printf("Attempting to remove from node position -4, -1 means failure: %d \n", dll_remove(l, -4));
	printf("Test Four Finished__________________________________________ \n");
}

void testFifth(dll_t* l){
	printf("dll's current size: %d \n", dll_size(l));
	printf("Removing last node, node's data: %d \n", dll_pop_back(l));
	printf("Removing first node, node's data: %d \n", dll_pop_front(l));
	printf("dll's current size: %d \n", dll_size(l));
	printf("Printing remaining nodes' data.... \n");
	for(int i = 0; i != l->count; i ++){
		printf("Node %d's data: %d \n", i,  dll_get(l,i));
	}
	printf("Test Five Finished__________________________________________ \n");

}


int main(){
	dll_t * dll = create_dll();
	
	testZero(dll);
	testFirst(dll);
	testSecond(dll);
	testThird(dll);
	testFourth(dll);
	testFifth(dll);
	printf("Freeing nodes...");
	free(dll);


   return 0;
}
