// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You need to add sufficient testing.
void unitTest1(){

	stack_t* test1 = create_stack(MAX_DEPTH);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test1,1);	
	printf("Removing: %d\n",stack_dequeue(test1));	

	free_stack(test1);
}

void unitTest2(){ //this test shows the stack_full function works

	stack_t* test2 = create_stack(3);
	stack_enqueue(test2,1);
        stack_enqueue(test2,2);
	printf("Is the stack full? 1 = YES, 0 = NO: %d \n",stack_full(test2));
        stack_enqueue(test2,1);
        printf("Is the stack full? 1 = YES, 0 = NO: %d \n",stack_full(test2));

	free_stack(test2);	
}

void unitTest3(){ //this test shows that the stack_empty function works
	
	stack_t* test3 = create_stack(2);
        stack_enqueue(test3,1);
        stack_enqueue(test3,2);
	printf("Is the stack full? 1 = YES, 0 = NO: %d \n",stack_empty(test3));
	stack_dequeue(test3);
	stack_dequeue(test3);
        printf("Is the stack full? 1 = YES, 0 = NO: %d \n",stack_empty(test3));

	free_stack(test3);
}

void unitTest4(){ //this test shows that the stack_size functions works; and that a full stack cannot enquueue and an empty stack cannot dequeue
	
	stack_t* test4 = create_stack(2);
        stack_enqueue(test4,1); 
	printf("Current stack size: %d \n",stack_size(test4));
        stack_enqueue(test4,2); 
        printf("Current stack size: %d \n",stack_size(test4));
        stack_enqueue(test4,3); 
        printf("Current stack size: %d \n",stack_size(test4));
	stack_dequeue(test4);
        printf("Current stack size: %d \n",stack_size(test4));
	stack_dequeue(test4);
        printf("Current stack size: %d \n",stack_size(test4));
	stack_dequeue(test4);
        printf("Current stack size: %d \n",stack_size(test4));

	free_stack(test4);
}



// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();

	return 0;
}
