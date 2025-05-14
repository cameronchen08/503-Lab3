/* Cameron Chen and Axel Sundstrom
   CSS 503 - Lab 3: Files
   The purpose of this lab is to help you get familiarized with Linux and C/C++ Standard I/O
   Implement a program that reads a given file using Linux read() system call as well as C/C++ fgetc()/fread() functions.  
*/

/* System Calls
   * open() - a unix system call that opens a given file
   * read() - a unix system call that reads a file into a given buffer
   * close() - a unix system calal that closes a given file
   * fopen() - a C/C++ standard I/O function that opens a given file
   * fgetc() - a C/C++ standard I/O function that reads one byte from a file
   * fread - a C/C++ standard I/O function that reads a file into a given data structure
   * fclose() - a C/C++ standard I/O function that closes a given file
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/time.h>
using namespace std;

struct timeval start, end2;
void startTimer() {
    gettimeofday(&start, NULL);
}
void stopTimer(const char *str) {
    gettimeofday(&end2, NULL);
    cout << str << "'s elpased time\t= " << ((end2.tv_sec - start.tv_sec) * 1000000 + (end2.tv_usec - start.tv_usec)) << endl;
}
int main (int argc, char *argv[]) {
    
} 