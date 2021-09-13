/* dict1.c
 * 
 * By: Patricia Angelica Budiman (1012861)
 *
 * Insert records from a file into
 * a dictionary using binary search tree
 * and look up records by key
 *
 * To run the program:
 * make dict1
 * ./dict1 inputfile outputfile < testfile
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "bst.h"
#include "support.h"

int main(int argc, char **argv) {
    
    char* headers[]= {"VendorID", "passenger_count", "trip_distance", "RatecodeID",
					  "store_and_fwd_flag", "PULocationID", "DOLocationID", "payment_type",
					  "fare_amount", "extra", "mta_tax", "tip_amount", "tolls_amount",
					  "improvement_surcharge", "total_amount", "PUdatetime" , "DOdatetime",
					  "trip_duration"};

    char **infoArray;
    char *line = NULL;
    size_t bufferLength = 0;
    int compareCount;
    struct bst *bst = NULL;
    oneString searchKey;
    
    char *inputFile = argv[1];
    char *outputFile= argv[2];
    
    FILE *input=fopen(inputFile,"r");
    FILE *output=fopen(outputFile,"w");
    
    /* read the input file line by line */
    while(getline(&line,&bufferLength,input)>0){
        /* storing each record and its informations in an array */
        infoArray = getarray(line);
		/* insert each record to binary search tree */
        bstInsert(&bst,infoArray[PU_DATETIME],infoArray);
    }
    
    /* reading each key to be searched from the file */
    while(readline(searchKey,MAXLEN)>0){
        struct bst *foundLoc;
        compareCount=0;

        /* search the key in the tree and print the information */
        foundLoc=bstSearch(bst,searchKey,&compareCount);
        printResult(output,foundLoc,searchKey,headers);
        printf("%s --> %d\n",searchKey,compareCount);
    }
    fclose(input);
    fclose(output);
	/* free the binary search tree */
	freeTree(bst);
}
