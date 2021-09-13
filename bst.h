/*
 * bst.h
 *
 * header file for bst.c
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

struct node;
struct bst;

typedef char oneString[MAXLEN];

/* insert each key and its informations in binary search tree*/
void bstInsert(struct bst** parent, char* key,char** other);

/* search the key in the binary search tree */
struct bst *bstSearch(struct bst* parent,char* findKey,int* compareCount);

/* print the informations of the key when found in the binary search tree */
void printResult(FILE *output,struct bst* parent, oneString searchKey,char *headers[]);

/* free the binary search tree*/
void freeTree(struct bst *parent);

/* free linked list inside the binary search tree */
void freeList(struct node *listHead);
