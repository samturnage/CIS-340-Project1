#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct mynode* quicksort(struct mynode *head)
{
    return head;
}

void printlist(struct mynode *head)
{
    struct mynode *node;
    node = head;

    while (node->next) {
        printf("%d\n", node->value);
        node = node->next;     
    }
}

void freelist(struct mynode *head)
{
    struct mynode *temp, *node = head;

    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
    head = NULL;
}
