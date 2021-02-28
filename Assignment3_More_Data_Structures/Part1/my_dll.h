// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
  	struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
        node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
dll_t* create_dll(){
	// Modify the body of this function as needed.
	dll_t* myDLL= (dll_t*)malloc(sizeof(dll_t));	
	myDLL->count = 0;
	myDLL->head = NULL;
	myDLL->tail = NULL;
	return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t* l){
	if(l == NULL){
		return -1;
	} else if(l->count == 0){
		return 1;
	} else if(l->count > 0){
		return 0;
	}

	return 9;
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns a -1 if the operation fails ( and if the DLL is NULL), otherwise returns 1 on success.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){	
	if(l == NULL){
		return -1;
	} else{
		node_t* node = (node_t*)malloc(sizeof(node_t));
		node->data = item;
		node->next = NULL;
		node->previous = NULL;
		if(node == NULL){
			return -1;
		}
		if(l->count == 0){
			l->head = node;
			l->tail = node;
			l->count ++;
			return 1;
		}
		node->next = l->head;
		l->head->previous = node;
		l->head = node;
		l->count ++;
		return 1;
	}
	return 9; 
}
// push a new item to the end of the DLL (after the last node in the list).
// Returns a -1 if the operation failsm (and if the DLL is NULL), otherwise returns 0 on success.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){
	if(l == NULL){
		return -1;
	} else{
		node_t* node = (node_t*)malloc(sizeof(node_t));
		node->data = item;
		node->next = NULL;
		node->previous = NULL;
		if(node == NULL){
			return -1;
		}
		if(l->count == 0){
			l->tail = node;
			l->head = node;
			l->count ++;
			return 1;
		}
		node->previous = l->tail;
		l->tail->next = node;
		l->tail = node;
		l->count ++;
		return 1;
	}

	return 9; 
}

// Returns the first item in the DLL and also removes it from the list.
// Returns a -1 if the operation fails (and if the DLL is NULL). Assume no negative numbers in the list.
int dll_pop_front(dll_t* t){
	if(t == NULL || t->count == 0){
		return -1;
	} else if(t->count ==1){
			int data = t->head->data;
			free(t->head);
			t->count --;
			return data;
		} else{
		node_t* temp = t->head;
		int data = t->head->data;
		t->head = t->head->next;
		free(temp);
		t->count --;
		return data;
	}
		return 9999999; // Note: This line is a 'filler' so the code compiles.
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the operation fails (and if the DLL is NULL). Assume no negative numbers in the list.
int dll_pop_back(dll_t* t){
	if(t == NULL || t->count == 0){
		return -1;
		} else if(t->count == 1){
			int data = t->tail->data;
			free(t->tail);
			t->count --;
			return data;
		} else{
		node_t* temp = t->tail;
		int data = t->tail->data;
		t->tail = t->tail->previous;
		free(temp);
		t->count --;
		return data;
	}

		return 9999999; // Note: This line is a 'filler' so the code compiles.
}
// Inserts a new node before the node at the specified position.
// Returns a -1 if the operation fails (and if the DLL is NULL), otherwise returns 1 on success.
// (i.e. the memory allocation for a new node failed or trying to insert at a negative position or at 
//  a position past the size of the DLL ). Think testcases here.
int dll_insert(dll_t* l, int pos, int item){
	if(l == NULL || pos > (l->count - 1) || 0 > pos){
		return -1;
	} 
	node_t* temp = l->head;
	node_t* temp2;
	for(int i = 0; i != pos; i ++){
		temp2 = temp->next;
		temp = temp2;
	}
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = item;
	newNode->next = NULL;
	newNode->previous = NULL;
	if(temp == l->head){
		newNode->next = l->head;
		l->head->previous = newNode;
		l->head = newNode;
		l->count ++;
		return 11;
	} else if(temp == l->tail){
		newNode->previous = l->tail;
		l->tail->next = newNode;
		l->tail = newNode;
		l->count ++;
		return 12;
	} else{
	newNode->next = temp;
	newNode->previous = temp->previous;
	temp->previous->next = newNode;
	temp->previous = newNode;
	l->count ++;
	return 13;
	}
	return -9;
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns a -1 if the operation fails (and if the DLL is NULL). Assume no negative numbers are in the list.
// (i.e. trying to get at a negative position or at a position past the size of the DLL ). 
// Think testcases here.
int dll_get(dll_t* l, int pos){
	if(l == NULL || pos > l->count || 0 > pos){
		return -1;
	} else{
		node_t* temp = l->head;
		for(int i = 0; i != pos; i ++){
			temp = temp->next;
		}
		int data = temp->data;
		return data;
	}

		return -1; 
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns a -1 if the operation fails (and if the DLL is NULL). 
// (i.e. trying to remove at a negative position or at a position past the size of the DLL ). 
// Think testcases here.
int dll_remove(dll_t* l, int pos){
	if(l == NULL || pos > (l->count - 1) || 0 > pos){
		return -1;
	} else{
		node_t* temp = l->head;
		for(int i = 0; i != pos; i ++){
			node_t* temp2 = temp->next;
			temp = temp2;
		} 
		int data = temp->data;
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		if(temp->next == NULL){
			l->tail = temp->previous;
		}
		if(temp->previous == NULL){
			l->head = temp->next;
		}
		free(temp);
		l->count --;
		return data;
	}


		return -1; // Note: you should have two return statements in this function.
		

}

// DLL Size
// Queries the current size of a DLL
// A DLL that has not been previously created will crash the program.
// Returns -1 if the DLL is NULL.
unsigned int dll_size(dll_t* t){
	if(t == NULL){
		return -1;
	} else {return t->count;}

	return 0;
}

// Free DLL
// Removes a DLL and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
	if(t->count != 0){
		node_t* temp = t->head;
		while(temp != NULL){
			node_t* temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
	}
	free(t);
}



#endif
