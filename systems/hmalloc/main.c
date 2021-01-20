#include "hmalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*You may include any other relevant headers here.*/


/*	main()
 *	Use this function to develop tests for hmalloc. You should not 
 *	implement any of the hmalloc functionality here. That should be
 *	done in hmalloc.c
 *	This file will not be graded. When grading I will replace main 
 *	with my own implementation for testing.*/
int main(int argc, char *argv[]){
	// some calls to hmalloc
    
        char * buffer1 = (char *)hmalloc(20);
        strcpy(buffer1,"hello world\n");
        write(1,buffer1, strlen(buffer1));
        hfree(buffer1);




	// ...
	// some calls to hfree
	
	return 0;
}
