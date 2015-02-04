/*
Project 1
Class:          CIS 340
Authors :       Derek Morey, James Doherty, Sam Turnage
Description:    Accepts a number of integers, creates a doubly linked list, and then
                quickssorts and prints them before and after the sort.
*/

//declare headers for input and node manipulation
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

//main method
int main(void)
{
    struct mynode *list = (struct mynode *)malloc(sizeof(struct mynode)); //head of linked list
    struct mynode *node = list, *temp; //used to traverse linked list
        
    //populate a list of integers using input and the head of the linked list
    //stops if an input value is 0
    while (temp->value != 0) {
        scanf("%d", &(node->value));
        node->next = (struct mynode *)malloc(sizeof(struct mynode)); //create new node
        temp = node; //temp references current node
        node = node->next; //advance current node to next
        node->prev = temp; //link to previous node
    }
    
    printf("List before sort: \n");
    printlist(list);
    //sort the list
    list = quicksort(list);

    printf("List after sort: \n");
    printlist(list);
    
    //clears the list of its pointers, avoiding memory leaks
    freelist(list);
   
    return 0;
}
