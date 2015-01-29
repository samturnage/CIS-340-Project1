struct mynode {
    int value;
    struct mynode *next;
    struct mynode *prev;
};

struct mynode* quicksort(struct mynode *);
void printlist(struct mynode *);
void freelist(struct mynode *);
