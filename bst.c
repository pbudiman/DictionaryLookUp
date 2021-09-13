/* bst.c
 *
 * By: Patricia Angelica Budiman (1012861)
 *
 * contains functions to insert to binary search tree,
 * search from binary search tree,
 * print the search keys and their information,
 * free the tree and linked list
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bst.h"
#include "support.h"

struct node{
    char **data;
    struct node *next;
};

struct bst {
    char *key;
    struct node *head;
    struct bst *left;
    struct bst *right;
};

/* insert each key and its informations in binary search tree
 * based on Worksheet 3 Week 4 workshop on JupyterHub
 */
void bstInsert(struct bst** parent, char* newKey,char** other){
    
    /* while root is not null, traverse down until location to insert the key is found */
    if(*parent!=NULL){
        int compare=strcmp(newKey,(*parent)->key);
        
        /* do recursion on left child when key is smaller tha parent's key */
        if(compare<0){
            bstInsert(&(*parent)->left,newKey,other);
        }
        /* do recursion on right child if key is bigger than parent's key */
        else if (compare>0){
            bstInsert(&(*parent)->right,newKey,other);
        }
        /* if key matches parent's key */
        else{
            /* store the data as a new node in the linked list */
            struct node *newNode;
            newNode=(struct node *)malloc(sizeof(struct node));
            newNode->data=other;
            newNode->next=(*parent)->head;
            (*parent)->head=newNode;
        }
    }else{
        /* if key is not present yet */
        /* store the key as a new parent node */
        (*parent) = (struct bst *)malloc(sizeof(struct bst));
        assert(*parent);
        
        (*parent)->key=malloc(strlen(newKey)+1);
        assert((*parent)->key);
        strcpy((*parent)->key,newKey);
        
        //store the information of the key
        (*parent)->head=(struct node *)malloc(sizeof(struct node));
        assert((*parent)->head);
        (*parent)->head->data=other;
        (*parent)->head->next=NULL;
        
        (*parent)->left = NULL;
        (*parent)->right = NULL;
        
    }
    
}


/* search the key in the binary search tree */
struct bst *bstSearch(struct bst* parent,char* findKey, int* compareCount){
    
    struct bst *tempParent=parent;
    
    if(tempParent!=NULL){
        /* compare the key with the parent's key */
        int compare=strcmp(findKey,tempParent->key);
        (*compareCount)++;
        
        /* do recursion from the left child if key is smaller than parent's key */
        if(compare<0){
            tempParent=bstSearch(tempParent->left,findKey,compareCount);
            
        } /* do recursion from the right child if key is bigger than parent's key */
        else if (compare>0){
            tempParent=bstSearch(tempParent->right,findKey,compareCount);
        }
    }else{
        /* if key is not in the tree */
        tempParent=NULL;
    }
    
    /* key found */
    return tempParent;
}

/* print the information of the key when found on the binary search tree */
void printResult(FILE *output,struct bst* parent,oneString searchKey,char *headers[]){
    
    /* if key is not found */
    if(parent==NULL){
        fprintf(output,"%s -->",searchKey);
        fprintf(output,"NOTFOUND\n");
    }else{
        
        if(parent!=NULL){
            struct node *list=parent->head;
            /* print every single node of the linked list */
            while(list!=NULL){
                fprintf(output,"%s -->",searchKey);
                
                /*print every single field of the information except the key field */
                for(int i=0;i<TOTALFIELD;i++){
                    if(i!=PU_DATETIME){
                        fprintf(output," %s: %s ||",headers[i],*(list->data+i));
                    }
                }
                list=list->next;
                fprintf(output,"\n");
            }
        }
    }
}

/* go down to the last child and free the child and the linked list
 * and return to parent to free the parent and do recursively until tree is free
 * based on Week 4 worksheet on Jupyterhub
 */
void freeTree(struct bst *parent){
    if(parent!=NULL){
        return;
    }
    freeTree(parent->left);
    freeTree(parent->right);
    freeList(parent->head);
    free(parent);
}

/* free linked list
 * based on listops.c Alistair Moffat, as an example for the book
 * "Programming, Problem Solving, and Abstraction with C" chapter 10 page 171
 * https://people.eng.unimelb.edu.au/ammoffat/ppsaa/c/
 */
void freeList(struct node *listHead){
    struct node *previous, *current;
    assert(listHead!=NULL);
    current=listHead;
    /* free all the nodes */
    while(current){
        previous=current;
        current=current->next;
        for(int i=0;i<TOTALFIELD;i++){
            free(*(previous->data+i));
        }
        free(previous->data);
        free(previous);
    }
    free(listHead);
}
