#include "bitsy.h"
#include <unistd.h>
#include <stdio.h>
/* Add any global variables or structures you need.*/

/* readByte
 * Abstraction to read a byte.
 * Relys on readBit.
 */
unsigned char byteOut = 0x0;
unsigned short readByte(){ 
    /* This function should not call read() directly.
     * If we are buffering data in readBit, we dont want to skip over
     * that data by calling read again. Instead, call readBit and 
     * construct a byte one bit at a type. This also allows us to read
     * 8 bits that are not necessarily byte alligned. */
    unsigned char temp;
    for (int i = 0; i < 8; i++){
        temp = readBit();
        if (temp < 256){
            temp = temp << (7 - i);
            byteOut = byteOut ^ temp;
        }
        else {
            return 666;
        }
    }
    return byteOut; 
    //Do NOT call read here. Instead rely on readBit.

    //I suggest returning a unique value greater than the max byte value
    //to communicate end of file. We need this since 0 is a valid byte value
    //so we need another way to communicate eof. These functions are typed
    //as short to allow us to return a value greater than the max byte value.
}

/* readBit
 * Abstraction to read a bit.
 * */
unsigned int pos = 8;
unsigned char in;
unsigned short readBit(){
    /* This function is responsible for reading the next bit on the
     * input stream from stdin (fd = 0). To accomplish this, keep a 
     * byte sized buffer. Each time read bit is called, use bitwise
     * operations to extract the next bit and return it to the caller.
     * Once the entire buffered byte has been read the next byte from 
     * the file. Once eof is reached, return a unique value > 255
     *
     */	
    if (pos > 7){
        read(0, &in, 1);
        pos = 0;
    }
    if (in != 0x10){
        unsigned char out = in;
        out = out >> (7 - pos);
        out = out & 0x01;
        pos++;
        return out; 
    }else{
        return 256;
    }

    //You will need to call read here

    //I suggest returning a unique value greater than the max byte value
    //to communicate end of file. We need this since 0 is a valid byte value
    //so we need another way to communicate eof. These functions are typed
    //as short to allow us to return a value greater than the max byte value.
    return 0; //placeholder
}

/* writeByte
 * Abstraction to write a byte.
 */
void writeByte(unsigned char byt){
    /* Use writeBit to write each bit of byt one at a time. Using writeBit
     * abstracts away byte boundaries in the output.*/
    unsigned char temp;
    for (int i = 0; i < 8; i++){
        temp = byt >> (7 - i);
        temp = temp & 0x01;
        writeBit(temp);
    }
    //Do NOT call write, instead utilize writeBit()
}

/* writeBit
 * Abstraction to write a single bit.
 */
int wPos = 0;
unsigned char buf = 0x0; 
void writeBit(unsigned char bit){
    /* Keep a byte sized buffer. Each time this function is called, insert the 
     * new bit into the buffer. Once 8 bits are buffered, write the full byte
     * to stdout (fd=1).
     */
    char tempBit = bit;
    if (wPos >= 7){
        write(1, &buf, 1);
        wPos = 0;
    }
    else {
        tempBit = tempBit << (7 - pos);
        buf = tempBit & buf;
        wPos++;
    }
    //You will need to call write here eventually.

}

/* flushWriteBuffer
 * Helper to write out remaining contents of a buffer after padding empty bits
 * with 1s.
 */
void flushWriteBuffer(){
    /* This will be utilized when finishing your encoding. It may be that some bits
     * are still buffered and have not been written to stdout. Call this function 
     * which should do the following: Determine if any buffered bits have yet to be 
     * written. Pad remaining bits in the byte with 1s. Write byte to stdout
     */

}
