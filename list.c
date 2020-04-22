//CSC 332 Group Project
//Authors: Yu Ting Yang
//Due: 5/8/20

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "list.h"

void list() {
    // clear the terminal screen
    system("clear");

    // open the file t1.txt, if file not exist, create one
    int fd = open("t1.txt",  O_RDWR|O_CREAT,0666);

    // fork a child process to run ls -l
    int child = fork();

    if (child < 0) {
        // error occurred, fork failed, exited
        fprintf(stderr, "fork failed\n");
        exit(0);
    } else if (child == 0) {
        // child perform ls -l

        // copy the file descriptor fd into standard output
        dup2(fd, STDOUT_FILENO);

        // execl replaces the current process image with a new process image specified by path
        // so it will run ls -l and copy to t1.txt
        execl( "/bin/ls" , "ls" , "-l" , (char *) 0 );

        // following code will only run if execl run fail
        fprintf(stderr, "run ls -l fail\n");
        exit(0);
    } else {
        // close the file descriptor as we don't need it more
        close(fd);
        // parent will wait for childs to complete
        wait(NULL);

        // open the t1.txt file to reading mode
        FILE *file;
        file = fopen("t1.txt", "r");
        if (file == NULL) {
            // error occurred, t1.txt failed to open, exited
            printf("error opening file.\n");
            exit(0);
        } else {
            // read each character from the file, and write to the terminal, then close the file
            char c;
            c = fgetc(file);
            while (c != EOF) {
                printf("%c", c);
                c = fgetc(file);
            }
            fclose(file);
        }
        // rename file name to tree.txt
        rename("t1.txt", "tree.txt");
    }
}
