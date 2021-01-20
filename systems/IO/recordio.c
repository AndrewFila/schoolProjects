#include "recordio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/* You must use this struct when constructing records. It is
 * expected that all binary data in the index file will follow
 * this format. Do not modify the struct.
 */
struct record_descriptor
{
	int position; //byte offset relative to the beginning of the data file
	int length;   //length of record in bytes
};

char rinx[] = ".rinx.";


struct record_descriptor rd;


/* rio_open
 * Open data file and index file. If create is requested, open both 
 * the data file and the index file with O_CREAT. If O_RDONLY or
 * O_RDWR is requested, make sure that the index file is present and 
 * return an error otherwise. On success the data file's descriptor
 * should be returned and the file descriptor for the index file
 * must be maintained within the abstraction.
 */
int rio_open(const char *pathname, int flags, mode_t mode){
    int fd = open(pathname, flags, mode);
    //int inxFD;

    char rinxOpen[7 + strlen(pathname)];
    strcpy(rinxOpen, rinx);
    strcat(rinxOpen, pathname);
    if ((flags&0xFCFF) == O_CREAT){
        char cmd[10 + strlen(pathname)];
        strcpy(cmd, "./indexer ");
        strcat(cmd, pathname);
        system(cmd);
        //inxFD = open(rinxOpen, flags - O_CREAT, mode);
        return fd;
        
    }
    else if ((flags&O_ACCMODE) == O_RDONLY || (flags&O_ACCMODE) == O_RDWR){
        if (access(rinxOpen, F_OK) != -1){
            //inxFD = open(rinxOpen, flags, mode); 

            return fd;
        }
        else {
            perror("rio_open() index not found");
            return -1;
        }
    }
    return 0;
}

/* rio_read
 * Allocate a buffer large enough to hold the requested record, read 
 * the record into the buffer and return the pointer to the allocated 
 * area. The I/O result should be returned through the return_value 
 * argument. On success this will be the number of bytes read into
 * the allocated buffer. If any system call returns an error, this
 * should be communicated to the caller through return_value.
 */
void *rio_read(int fd, int *return_value){
    
	return NULL; //replace with correct return value
}

/* rio_write
 * Write a new record. If appending to the file, create a record_descriptor 
 * and fill in the values. Write the record_descriptor to the index file and 
 * the supplied data to the data file for the requested length. If updating 
 * an existing record, read the record_descriptor, check to see if the new 
 * record fits in the allocated area and rewrite. Return an error otherwise.
 */
int rio_write(int fd, const void *buf, int count){

	return -1; //replace with correct return value
}

/* rio_lseek
 * Seek both files (data and index files) to the beginning of the requested 
 * record so that the next I/O is performed at the requested position. The
 * offset argument is in terms of records not bytes (relative to whence).
 * whence assumes the same values as lseek whence argument.
 *
 */
int rio_lseek(int fd, int offset, int whence){

	return -1; //replace with correct return value
}

/* rio_close
 * Close both files. Even though a single descriptor is passed along, 
 * your abstraction must close the other file as well. It is suggested 
 * that you return the descriptor obtained by opening the data file 
 * to the user and keep the index file descriptor number in the 
 * abstraction and associate them.
 */
int rio_close(int fd){

	return -1; //replace with correct return value
}
