// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You need to add sufficient testing.
void unitTest1(){

	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);
	printf("Current size: %d \n",queue_size(test1));
	printf("Removing: %d\n",queue_dequeue(test1));		

	free_queue(test1);
}

void unitTest2(){ //this test should show that can not overwrite an already filled queue
		
	queue_t* test2 = create_queue(5);
	printf("Attempting to add %d, %d, %d, %d, and %d \n",1,2,3,4,5);
	queue_enqueue(test2,1);
        queue_enqueue(test2,2);  
        queue_enqueue(test2,3);
        queue_enqueue(test2,4);
        queue_enqueue(test2,5);
	printf("Attempting to add %d \n",6);
	queue_enqueue(test2,6);
	
	free_queue(test2);

}

void unitTest3(){ //this test should show that you can not dequeue on an empty buffer
	
	queue_t* test3 = create_queue(1);
	printf("Attempting to add %d \n",1);
	queue_enqueue(test3,1);
	printf("Attempting to remove %d \n",queue_dequeue(test3));
	printf("Attempting to remove another %d \n",1);
	queue_dequeue(test3);

	free_queue(test3);
}

void unitTest4(){ //this test shows if the queue_full check function is working
	
	queue_t* test4 = create_queue(3);
        queue_enqueue(test4,1);
        queue_enqueue(test4,2); 
        queue_enqueue(test4,3);
	printf("Is the queue full? 0 = NO, 1 = YES: %d \n",queue_full(test4));
        queue_dequeue(test4);
        printf("Is the queue full? 0 = NO, 1 = YES: %d \n",queue_full(test4)); 

	free_queue(test4);	
}

void unitTest5(){ //this test shows that the queue_empty function is working
	
        queue_t* test5 = create_queue(2);
        queue_enqueue(test5,1); 
        queue_enqueue(test5,2);
	printf("Is the queue empty? 0 = NO, 1 = YES: %d \n",queue_empty(test5));
        queue_dequeue(test5);
        queue_dequeue(test5);
	printf("Is the queue empty? 0 = NO, 1 = YES: %d \n",queue_empty(test5));

	free_queue(test5);
}

void unitTest6(){ //this test shows that the queue_size function is working, and we can fill, empty, and refill queues
	
	queue_t* test6 = create_queue(3);
        queue_enqueue(test6,1);
        queue_enqueue(test6,2);
	printf("Current queue size: %d \n",queue_size(test6));
        queue_enqueue(test6,3); 
        printf("Current queue size: %d \n",queue_size(test6));
        queue_dequeue(test6); 
        queue_dequeue(test6);
        printf("Current queue size: %d \n",queue_size(test6));
        queue_dequeue(test6); 
        printf("Current queue size: %d \n",queue_size(test6));
        queue_enqueue(test6,1); 
        queue_enqueue(test6,2); 
        queue_enqueue(test6,3); 
        printf("Current queue size: %d \n",queue_size(test6));

	free_queue(test6);
}

//=====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();
	unitTest5();
	unitTest6();
	return 0;
}
