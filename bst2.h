/*
 * bst2.h
 *
 * header file for bst2.c
 *
 * By: Patricia Angelica Budiman (1012861)
 *
 */

#define COMMA ','
#define COMMALEN 1
#define MAXLEN 128
#define PU_DATETIME 15
#define PU_LOCATION_ID 5
#define TOTALFIELD 18

struct bst;
struct node;

typedef char oneString[MAXLEN] ;

/* print the PUdatetime which match the searched PUlocationID by in order traversal*/
void printNodeInOrder(FILE *output,struct bst* parent, char* location,int* compareCount);

/* insert each key and its informations in binary search tree */
void bstInsert(struct bst** parent, char* key,char** other);

/* free the binary search tree */
void freeTree(struct bst *parent);

/* free linked list */
void freeList(struct node *listHead);

