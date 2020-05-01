//CSC 332 Group Project
//Authors: Leah Meza
//Due: 5/8/20

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "exit.h"
const int X = 4; 
const int Y = 7; 

void exit_(char history[X][Y]) {
    pid_t child; //pid of children processes

    child = fork(); //parent creates a duplicate child1
    if(child == -1){ //fork failed
        printf("\nERROR: first child fork failed.\n");
        perror("fork");
        exit(1);
    }
    if(child == 0){ //child process
        for(int i=0; i<X; i++)
            printf("%d - %s\n", i, history[i]);
    
        execlp( "ls", "ls", "-l", (char*)NULL);  //execute ls -l
        perror("execlp"); //only prints if execlp failed
    }
    else{ //parent process
        wait(NULL); //wait for child end
    }
}