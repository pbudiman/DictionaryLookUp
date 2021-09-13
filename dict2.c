/* Insert records from a file into
 * a dictionary using binary search tree
 * and retrieve information which contain the key to be searched
 *
 *
 * By: Patricia Angelica Budiman (1012861)
 * To run the program:
 * make dict2
 * ./dict2 inputfile outputfile < testfile
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bst2.h"
#include "support.h"

int main(int argc, char **argv) {
    char **infoArray;
    char *line = NULL;
    size_t bufferLength = 0;
    struct bst *bst = NULL;
    oneString searchKey;
    int compareCount;
    
    char *inputFile = argv[1];
    char *outputFile= argv[2];
    
    FILE *input=fopen(inputFile,"r");
    FILE *output=fopen(outputFile,"w");

    /* read the file line by line */
    while(getline(&line,&bufferLength,input)>0){
        /* storing each record and its informations in an array */
        infoArray=getarray(line);
        /* insert each record to binary search tree */
        bstInsert(&bst,infoArray[PU_DATETIME],infoArray);
    }
    
    /* reading for every taxi zone ID to be searched */
    while(readline(searchKey,MAXLEN)>0){
        compareCount=0;
        /* print the result in temporal order by in order traversal*/
        printNodeInOrder(output,bst,searchKey,&compareCount);
        printf("%s --> %d\n",searchKey,compareCount);
    }
    fclose(input);
    fclose(output);
    /* free the binary search tree */
    freeTree(bst);
}
