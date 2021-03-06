// =================== Support Code =================
// Binary Search Tree ( BST ).
//
//
//
// - Implement each of the functions to create a working BST.
// - Do not change any of the function declarations
//   - (i.e. bst_t* create_bst() should not have additional arguments)
// - You should not have any 'printf' statements in your BST functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYBST_H
#define MYBST_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


// Create a node data structure to store data within
// our BST. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* rightChild;
  	struct node* leftChild;
}node_t;

// Create a BST data structure
// Our BST holds a pointer to the root node in our BST called root.
typedef struct BST{
	int count;		// count keeps track of how many items are in the BST.
	node_t* root;		// root points to the root node in our BST.
}bst_t;

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values.
bst_t* create_bst(){
	// Modify the body of this function as needed.
	bst_t* myBST= (bst_t*)malloc(sizeof(bst_t));	
	myBST->count = 0;
	myBST->root = NULL;
	return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element enqueued)
int bst_empty(bst_t* t){
	if(t->count == 0){
		return 1;
	}
	return 0;
}



void add_helper(node_t* t, node_t* newNode){
	if(newNode->data < t->data){
		if(t->rightChild != NULL){
			add_helper(t->rightChild, newNode);
		} else{
			t->rightChild = newNode;
		}
	} else if(newNode->data > t->data){
		if(t->leftChild != NULL){
			add_helper(t->leftChild, newNode);
		} else{
			t->leftChild = newNode;
		}
	}	
}




// Adds a new node containng item in the correct place of the BST.
// If the data is less then the current node we go right, otherwise we go left.
// Same as described in the README.md file. 
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// It should run in O(log(n)) time.
int bst_add(bst_t* t, int item){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = item;
	newNode->rightChild = NULL;
	newNode->leftChild = NULL;
	if(newNode == NULL){
		return -1;
	}
	if(t->root == NULL){
		t->root = newNode;
		t->count ++;
		return 0;
	} else {
		add_helper(t->root, newNode);
		t->count ++;
		return 0;
	}

	return -1;
}


void print_helper(node_t* t, int order){
	if(order == 0){
		if(t->rightChild != NULL){
			print_helper(t->rightChild, order);
		}
		printf("%d \n",t->data);

		if(t->leftChild != NULL){
			print_helper(t->leftChild, order);
		}
	} else{
		if(t->leftChild != NULL){
			print_helper(t->leftChild, order);
		}
		printf("%d \n",t->data);

		if(t->rightChild != NULL){
			print_helper(t->rightChild, order);
		}
	}

}


// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree it should print nothing. 
// It should run in O(n) time.
void bst_print(bst_t* t, int order){
	if(t == NULL){
		printf("");
	} else{
		//printf("%d", t->root->leftChild->rightChild->leftChild->data);
		print_helper(t->root, order);
	}

}

int sum_helper(node_t* t){
	int left;
	int right;
	int sum = 0;
	if(t != NULL){	
		left = sum_helper(t->leftChild);
		right = sum_helper(t->rightChild);
		sum = (t->data) + left + right;
	}

	return sum;
	
}


// Returns the sum of all the nodes in the tree. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int sum(bst_t* t){	
	return sum_helper(t->root);
}




int find_helper(node_t* t, int value){
	if(value < t->data){
		if(t->rightChild == NULL){
			return 0;
		} else{
			int check = find_helper(t->rightChild, value);
			return check;
		}
	} else if(value > t->data){
		if(t->leftChild == NULL){
			return 0;
		} else{
			printf("check1");
			int check2 = find_helper(t->leftChild, value);
			return check2;
		}
	} else{
		return 1;
	}
}


// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int find(bst_t * t, int value){
	int check = find_helper(t->root, value);
	if(check == 1){
		return 1;
	}
	return check;
}

// BST Size
// Queries the current size of the BST
// A BST that has not been previously created will crash the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
	return t->count;
}


void free_helper(node_t* t){
	if(t->rightChild != NULL){
		free_helper(t->rightChild);
	}
	if(t->leftChild != NULL){
		free_helper(t->leftChild);
	}
	free(t);
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_bst(bst_t* t){

	free_helper(t->root);
	free(t);
}



#endif
