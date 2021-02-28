// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

typedef struct node{
	int year;
	int wins;
	struct node* next;
}node_t;

node_t* create_List(){
	node_t* year2018 = malloc(sizeof(node_t));
	node_t* year2017 = malloc(sizeof(node_t));
	node_t* year2016 = malloc(sizeof(node_t));
	node_t* year2015 = malloc(sizeof(node_t));
	node_t* year2014 = malloc(sizeof(node_t));

	year2018->year = 2018;
	year2017->year = 2017;
	year2016->year = 2016;
	year2015->year = 2015;
	year2014->year = 2014;
     
	year2018->wins = 108;
	year2017->wins = 93;
	year2016->wins = 93;
	year2015->wins = 78;
	year2014->wins = 71;

	year2018->next = year2017;
	year2017->next = year2016;
	year2016->next = year2015;
	year2015->next = year2014;
	year2014->next = NULL;

	return year2018;
}

void print_List(node_t* iterator){
	while(iterator != NULL){
		printf("Year: %d, Wins: %d\n", iterator->year,  iterator->wins);
		iterator = iterator->next;
	}
}	

void free_List(node_t* iterator) {
	while(iterator != NULL){
		node_t* iterator2 = iterator;
		iterator = iterator->next;
		free(iterator2);
	}

}


int main(){
	node_t* redsox = NULL;
	redsox = create_List();
	node_t* iterator = redsox;

	print_List(iterator);
	free_List(iterator);
	 

    return 0;
}

// references used:
// youtube video provided in lab readme
// zentut.com/c-tutorial/c-linked-list/
// www.geeksforgeeks.org/linked-list-set-1-introduction/amp/
// time taken: 1 hour
// most liked: the linking with pointers, next*
// most dislike: wrapping my head around pointers
