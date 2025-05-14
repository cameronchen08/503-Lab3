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

// maintain start and finish wall time
struct timeval start, end2;

void startTimer() {
    gettimeofday(&start, NULL);
}

void stopTimer(const char *str) {
    gettimeofday(&end2, NULL);
    cout << str << "'s elpased time\t= " << ((end2.tv_sec - start.tv_sec) * 1000000 + (end2.tv_usec - start.tv_usec)) << endl;
}

int main (int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "usage: lab3 filename bytes" << endl;
        return -1;
    }
    int bytes = atoi(argv[2]);
    if (bytes < 1) {
        cerr << "usage: lab3 filename bytes" << endl;
        cerr << "where bytes > 0" << endl;
        return -1;
    }
    char *filename = argv[1];
    char *buf = new char[bytes];

    // Linux I/O
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        cerr << filename << "not found" << endl;
        return -1;
    }
    startTimer();
    while (read(fd, buf, bytes) > 0);
    stopTimer("Unix read");
    close(fd);

    // Standard I/O - use fopen(), fgetc(), fread(), fclose()
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        cerr << filename << "not found" << endl;
        return -1;
    }
    startTimer();
    
    // if bytes == 1, use fgetc() to read one byte at a time
    if (bytes == 1) {
        while (fgetc(fp) != EOF);
    }
    else {
        while (fread(buf, sizeof(char), bytes, fp) > 0);
    }
    stopTimer("Standard fread");
    fclose(fp);
    delete[] buf;
    return 0;
} 