//CSC 332 Group Project
//Authors: Leah Meza
//Due: 5/8/20

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define N 10000
#include "list.h"
#include "tree.h"
//#include "path.h" #rei
#include "exit.h"

int main(void)
{
    char* buffer = calloc (N, sizeof (char*)); //array of char from user input including whitespace
    char history[4][7]; //hold history of commands
    int count = 0;
    int FLAG = 0; //only display environment if shell* was entered

    if(buffer == NULL) //check buffer for successful memory allocation
    { 
        printf("Memory Allocation failed.");
        free(buffer);
        exit(1);
    }
//input stream loop; infinite loop broken by 'return' key 
    for(;;){ 
    //input validation
        if(FLAG == 1)
            printf("==> ");
        if (fgets(buffer, N, stdin) != NULL ) //reads line including whitespace from stdin
        {   
        //break condition
            if(strlen(buffer) == 1) //check length of buffer (1 because of nullpointer)
            { 
                printf("Exited.\n");
                break;
            } 
        //valid options
            if(!((strncmp("shell*\n", buffer, 6) == 0) || (strncmp("tree*\n", buffer, 6) == 0) || (strncmp("list*\n", buffer, 6) == 0) || 
                (strncmp("path*\n", buffer, 6) == 0) || (strncmp("exit*\n", buffer, 6) == 0)))
            {
                printf("You didn't enter a valid option!\nOptions: tree*\tlist*\tpath*\texit*\n");
                continue; //want to continue out of this loop (prevent a child)
            }
        }
    //Event Handeling
        if(strncmp("shell*\n", buffer, 6) == 0) //need to enter shell first to access 
        {
            FLAG = 1;
            strcpy(history[count++], "shell*");
        }
        if(strncmp("tree*\n", buffer, 6) == 0)
        {
            tree();
            strcpy(history[count++], "tree*");
        }
        if(strncmp("list*\n", buffer, 6) == 0)
        {
            list();
            printf("\n"); 
            strcpy(history[count++], "list*");
        }
        if(strncmp("path*\n", buffer, 6) == 0)
        {
            //path();
            printf("You chose path*\n"); //debugging purposes
            strcpy(history[count++], "path*");
        }
        if(strncmp("exit*\n", buffer, 6) == 0)
        {
            exit_(history);
            FLAG = 0;
        }
    }
    free(buffer);
    return 0;
}
