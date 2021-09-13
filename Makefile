dict1: dict1.o bst.o support.o
	gcc -Wall -o dict1 dict1.c bst.o support.o -g

dict2: dict2.o bst2.o support.o
	gcc -Wall -o dict2 dict2.c bst2.o support.o -g

dict1.o: dict1.c bst.h
	gcc -Wall dict1.c -c -g -o dict1.o

dict2.o: dict2.c bst2.h
	gcc -Wall dict2.c -c -g -o dict2.o

bst.o: bst.c bst.h support.h
	gcc -Wall bst.c -c -g -o bst.o

bst2.o: bst2.c bst2.h support.h
	gcc -Wall bst2.c -c -g -o bst2.o

support.o: support.c support.h
	gcc -Wall support.c -c -g -o support.o