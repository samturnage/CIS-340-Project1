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
    int i;

    for (i=1; node->next; i++) {
        printf("%3d ", node->value);
        node = node->next;     
        if (i % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
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
