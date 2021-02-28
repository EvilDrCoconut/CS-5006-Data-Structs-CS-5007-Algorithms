// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
#include <stddef.h>

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    bst_t * testBST = create_bst();
    printf("Is the tree empty? Yes = 1, No = 0: %d \n", bst_empty(testBST));
    
    bst_add(testBST, 30);
    bst_add(testBST, 20);
    printf("Tree's size: %d \n", bst_size(testBST));
    printf("Tree current sum is: %d \n", sum(testBST));
    
    bst_add(testBST, 25);
    bst_add(testBST, 15);
    printf("Tree's size: %d \n", bst_size(testBST));
    printf("Tree current sum is: %d \n", sum(testBST));
    
    bst_add(testBST, 10);
    bst_add(testBST, 5);
    bst_add(testBST, 50);
    bst_add(testBST, 45);
    printf("Tree's size: %d \n", bst_size(testBST));
    printf("Tree current sum is: %d \n", sum(testBST));
    
    bst_add(testBST, 40);
    printf("Is the tree empty? Yes = 1, No = 0: %d \n", bst_empty(testBST));
    printf("Tree's size: %d \n", bst_size(testBST));
    printf("Tree current sum is: %d \n", sum(testBST));

    
    bst_print(testBST, 1);
    bst_print(testBST, 0);


    printf("Is 45 inside the tree? 1 = Yes, 0 = No: %d \n", find(testBST,45));
    printf("Is 32 inside the tree? 1 = Yes, 0 = No: %d \n", find(testBST,32));
    printf("Is 5 inside the tree? 1 = Yes, 0 = No: %d \n", find(testBST,5));
    printf("Is -1 inside the tree? 1 = Yes, 0 = No: %d \n", find(testBST,-1));
    printf("Is 15 inside the tree? 1 = Yes, 0 = No: %d \n", find(testBST,15));

    free_bst(testBST);    
    return 0;
}
