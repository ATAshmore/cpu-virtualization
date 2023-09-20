//  project1 
//  problem 2
/*
    CITING
    I was following a video tutorial that explained pipe().
    It explained a rough outline of how | operator works by pinging. Link below
    https://www.youtube.com/watch?v=6xbLgZpOBi8&list=RDCMUC6qj_bPq6tQ6hLwOBpBQ42Q&index=3
*/

/*  
    PROJECT PDF REQUIREMENTS
    This problem builds significantly on the previous problem. Specifically, it asks you to again use fork() to 
    create processes and exec() (or one of the many variants) to assign the newly created processes what to do. 
    In addition, however, it asks you to mimic the behavior of a shell command such as:
    ls | wc
    What happens in the case above is the output of the first command (’ls’) becomes the input to the second 
    command (’wc’). (Try it in a terminal on a Unix machine). Thus, you are required to write another program:

    Expects an input of the form: cmd1 | cmd2
    Creates two processes

    Makes the first process run cmd1

    Makes the second process run cmd2

    Makes sure that the output of the first process becomes the input of the second process (using the 
    function pipe()).

    Waits for the two processes to finish before it ends by printing ++++ on a new line.
*/

/*
    NOTES
    2 forks
    main prints ++++. waits for children to finish
    child1 child of main
    child2 child of child1
    first cmd completed by child1
    second cmd completed by child2
    output of first cmd piped to child2

    after reading or writing from file, close the pipe

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]){ 

    int fd[2];
    pipe(fd);
    int child1, child2;

    child1 = fork();
    if(child1 == 0){
        //  CHILD PROCESS 1, CMD1
        
        //  make stdout to write side of pipe
        dup2(fd[1], STDOUT_FILENO);
        //  close read of pipe because not used
        close(fd[0]);
        //  close write end of pipe cause dupped
        close(fd[1]);
        //  execute cmd1
        execlp(argv[1], argv[1], NULL);
    }

    child2 = fork();
    if(child2 == 0){
        //  CHILD PROCESS 2, cmd2
        
        //  make stdin to read end
        dup2(fd[0], STDIN_FILENO);
        //  close write end cause not used
        close(fd[1]);
        //  close read cause dupped
        close(fd[0]);
        //  execute cmd2
        execlp(argv[3], argv[3], NULL);
    }

    //  PARENT PROCESS

    //  close both sides of the pipe
    close(fd[0]);
    close(fd[1]);
    //  wait for child process 1 and 2 to finish
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);
    //  both cmd1,2 executed, print ++++\n
    printf("++++\n");


    return 0;
}
