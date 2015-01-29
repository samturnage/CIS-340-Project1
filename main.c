#include <stdlib.h>
#include <stdio.h>
#include "node.h"

int main(void)
{
    struct mynode *list = (struct mynode *)malloc(sizeof(struct mynode)); //head of linked list
    struct mynode *node = list, *temp; //used to traverse linked list
        
    while (temp->value != 0) {
        scanf("%d", &(node->value));
        node->next = (struct mynode *)malloc(sizeof(struct mynode)); //create new node
        temp = node; //temp references current node
        node = node->next; //advance current node to next
        node->prev = temp; //link to previous node
    }

    printlist(list);
    list = quicksort(list);
    printlist(list);
    freelist(list);
   
    return 0;
}
