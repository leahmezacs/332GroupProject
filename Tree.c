//Afsana Akter
//for the Tree portion

#include<stdio.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<stdlib.h> 
#include"tree.h"

void tree()
{ 
     // creating directory dir0 
     struct stat st = {0}; 
     if(stat("./Dir0", &st) == -1)
     { 
          mkdir("./Dir0", 0700); 
     } 

    // changing directory to Dir0 
    chdir("Dir0"); 

    // Creating files inside Dir0 
    int fileDescriptor = open("t1.txt", O_RDWR | O_APPEND | O_CREAT, 0666); 
    if(fileDescriptor < 0)
    { 
           perror("Error creating file"); 
           exit(-1); 
    } 
    fileDescriptor = open("t2.txt", O_RDWR | O_APPEND | O_CREAT, 0666); 
    if(fileDescriptor < 0)
    { 
           perror("Error creating file"); 
           exit(-1); 
    } 
    fileDescriptor = open("t3.txt", O_RDWR | O_APPEND | O_CREAT, 0666); 
    if(fileDescriptor < 0)
    { 
           perror("Error creating file"); 
           exit(-1); 
     } 
     // creating directory dir1 
     if(stat("./Dir1", &st) == -1)
     { 
           mkdir("./Dir1", 0700); 
     } 
     
} 
