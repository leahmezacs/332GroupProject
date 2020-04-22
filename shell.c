//CSC 332 Group Project
//Authors: Leah Meza, _, _, _
//Due: 5/8/20

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define N 10000
#include "list.h"
#include "tree.h"

int main(void)
{
    char* buffer = calloc (N, sizeof (char*)); //array of char from user input including whitespace
    if(buffer == NULL) //check buffer for successful memory allocation
    { 
        printf("Memory Allocation failed.");
        free(buffer);
        exit(1);
    }
//input stream loop; infinite loop broken by 'quit' input
    printf("Enter a command in shell*.\nOptions: tree*\tlist*\tpath*\texit*");
    printf("\nEnter 'quit' to end.\n");
    for(;;){ 
        printf("==> ");
    //input validation
        if (fgets(buffer, N, stdin) != NULL ) //reads line including whitespace from stdin
        {   
            if(strlen(buffer) == 1){ //check length of buffer (1 because of nullpointer)
                printf("You didn't enter anything!\nOptions: tree*\tlist*\tpath*\texit*\n");
                continue; //want to continue out of this loop (prevent a child)
            }
        //break condition
            if (strncmp("quit\n", buffer, 5) == 0) //buffer is matched to 'quit\n' by 5 characters
            {
                printf("Exited.\n");
                break;//return 0; //this is before forking to prevent a child
            }
        //valid options
            if(!((strncmp("tree*\n", buffer, 6) == 0) || (strncmp("list*\n", buffer, 6) == 0) || 
                (strncmp("path*\n", buffer, 6) == 0) || (strncmp("exit*\n", buffer, 6) == 0)))
            {
                printf("You didn't enter a valid option!\nOptions: tree*\tlist*\tpath*\texit*\n");
                continue; //want to continue out of this loop (prevent a child)
            }
        }
    //Event Handeling
    /* 
    *  Whether you prefer to make it within this for loop or an outside function, just let
    *  everyone know so our code can be uniform. Feel free to change anything.
    *  I will also do exit* in May if we don't get another member. 
    *  - Leah 
    */
        if(strncmp("tree*\n", buffer, 6) == 0)
        {
            // printf("You chose tree*\n"); //debugging purposes
            tree();
            //Afsana :)
        }
        if(strncmp("list*\n", buffer, 6) == 0)
        {
            // printf("You chose list*\n"); //debugging purposes
            list();
            //YuTing :)
        }
        if(strncmp("path*\n", buffer, 6) == 0)
        {
            printf("You chose path*\n"); //debugging purposes
            //Rei :)
        }
        if(strncmp("exit*\n", buffer, 6) == 0)
        {
            printf("You chose exit*\n"); //debugging purposes
        }
    }
    free(buffer);
    return 0;
}
