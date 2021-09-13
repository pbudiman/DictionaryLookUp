#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "support.h"

/* store the fields of each record as 2d array */
char** getarray(char* line){
    
    int field=0,length=0;
    
    oneString newString;
    
    char**strArray=(char **)malloc(TOTALFIELD*sizeof(char *));
    
    /* separate the fields by comma of each record and store them in an array */
    for(int i=0;i<TOTALFIELD;i++){
        strArray[field]=getInfo(line+length,newString);
        field++;
        length=length+strlen(newString)+1;
    }
    return strArray;
    
}

/* separate one line into each word separated by comma */
char* getInfo(char* line,char oneInfo[]) {
    
    int character=0, len=0;
    
    while (line[character]!=COMMA && line[character]!='\n') {
        /* store next character */
        oneInfo[len++] = line[character];
        character++;
    }
    oneInfo[len] = '\0';
    
    char *str_ptr;
    
    /* pointing to the string */
    str_ptr=(char*)malloc(strlen(oneInfo));
    strcpy(str_ptr,oneInfo);
    
    return str_ptr;
}

/* read a string into oneLine */
int readline(oneString oneLine,int max){
    int oneChar,i=0,count=0;
    
    /* read each character and store them in the array */
    while((oneChar=getchar())!=EOF && (oneChar!='\n')){
        oneLine[i]=oneChar;
        i++;
        count++;
    }
    oneLine[i]='\0';
    return count;
}
