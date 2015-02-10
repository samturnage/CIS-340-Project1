//include header files
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

//quicksort method
//takes one node pointer and recursively sorts in acending order, returning the head node
struct mynode* quicksort(struct mynode **head, struct mynode *last)
{
    int intPivot;
    struct mynode *pivot = *head;
    intPivot = pivot->value;
    
    struct mynode *current=pivot->next;
    struct mynode *previous = pivot;
    struct mynode *temp;
    

    if (*head == last) {
        return 0;
    } else {
        while (current != last) {
            if (current->value <= intPivot) {
                temp = current->next;
                current->next = *head;
                previous->next = temp;
                *head = current;
                current = temp;
            } else {
                previous = current;
                current = current->next;
            }
        }
    }
 
    
    quicksort(head, pivot);
    quicksort(&pivot->next, last);
    
    return *head;

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
