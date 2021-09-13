/*
 * support.h
 *
 * header file for support.c
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

typedef char oneString[MAXLEN] ;

/* separate the information of each record by comma and store in array */
char* getInfo(char* line,char oneInfo[]);

/* store the all fields of each record in one array*/
char** getarray(char*);

/* read one line and put in one array */
int readline(oneString,int);
