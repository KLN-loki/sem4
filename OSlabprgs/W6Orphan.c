// 6. Implement the following:
// i) Program to create an Orphan process.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid == -1){
        perror("fork");
        return 1;
    }
    if(pid == 0){
        printf("child created.\n");
        printf("child sleeping.\n");
        sleep(2);
        printf("child exiting.\n");
    }
    else{
        printf("parent waiting.\n");
        sleep(1);
        printf("parent exiting.\n");
        exit(0);
    }
    return 0;
}