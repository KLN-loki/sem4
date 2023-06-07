// 4. Implementation of open (), fork () system calls.

#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid == -1){
        perror("fork");
        return 1;
    }
    if(pid == 0){
        printf("Child process.\n");
    }
    else{
        printf("Parent process.\n");
    }
    return 0;
}