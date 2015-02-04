//include header files
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

//quicksort method
//takes one node pointer and recursively sorts in acending order, returning the head node
struct mynode* quicksort(struct mynode *head)
{
	/*
	I'm pretty sure we need a case where only one node is being passed
	if(head->next == NULL)
	{
		return head;
	}
	hopefully this will fix something, I have no way of compiling any of this so let me know
	
	Also I think the below code would create a node with no value in it, and then later pass
	a list with a dummy node in it. Maybe create the node first in l_current, add a value in
	it, and then later ignore the first node in Left. Hopefully that make sense.
	good luck,	
	-Sam
	*/
	int pivot = head->value;
	struct mynode *current, *left, *right, *l_current, *r_current;
	left = (struct mynode *)malloc(sizeof(struct mynode));
	right = (struct mynode *)malloc(sizeof(struct mynode));
	l_current = left;
	r_current = right;

	for (current=head; current; current=current->next) {
		if (current->value < pivot) {
			l_current->value = current->value;
			l_current->next = (struct mynode *)malloc(sizeof(struct mynode));
			l_current = l_current->next;
		} else {
			r_current->value = current->value;
			r_current->next = (struct mynode *)malloc(sizeof(struct mynode));
			r_current = r_current->next;
		}
	}

	left = quicksort(left);
	right = quicksort(right);

	for (current=left; current; current=current->next) {	
	}

	current->next = right;
    return left;
}

//printlist method
//loops through a given linked list and prints the data in each node
void printlist(struct mynode *head)
{
    struct mynode *node = head;
    int i;

    for (i=1; node->next; i++) {
        printf("%3d ", node->value);
        node = node->next;  
        //goes down a line if the number of data poins printed exceeds 20 per line
        if (i % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

//freelist method
//deletes all the nodes of a iven head, effectively erasing the linked list
void freelist(struct mynode *head)
{
    struct mynode *temp, *node = head;
    //deletes all nodes after the head
    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
    //deletes the head node
    head = NULL;
}
