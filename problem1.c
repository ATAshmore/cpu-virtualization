//  project1 CPU virtualization
//  problem 1

/*
    PROJECT PDF REQUIREMENTS
    Takes an input from the command line. This input can be a sequence of characters without separators, 
    such as date or ls, or a sequence that contains separators (e.g., space or -), such as ls -l. Lets 
    refer to this input as cmd if only one word, or cmd and params if more than one word. If the input 
    has multiple separators, cmd is the sequence of characters before the first separator, and params is 
    the rest of the input. For example, if the input is: ls -a -l then cmd is ls and params is -a -l.

    Creates a new process (using fork());

    Makes the new process execute cmd with params as parameters, if given.

    Waits for the new process to finish executing, and then prints ++++ on a new line
*/
/*
    new process exectutes cmd and paramters.
    parent process prints ++++
    use wait() to let parent process finish. put on newlineS
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

//  "notes"
//  execl is list
//  execv is vector

int main (int argc, char *argv[]){
    
    int child1 = fork();
    //  parent process
    if (child1 > 0){
        //  int status;
        //  waitpid(pid, &status, 0);
        //  wait for child process to finish
        wait(NULL);
        //  print ++++
        printf("++++\n");

    }
    //  child
    else{
        execvp(argv[1], &argv[1]);
    }
    
    return 0;
}
