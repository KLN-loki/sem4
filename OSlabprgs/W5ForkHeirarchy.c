// 5. Implement a program using fork () system call to create a hierarchy of 3 process such that
// P2 is the child of P1 and P1 is the child of P.

#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1 == -1){
        perror("fork");
        return 1;
    }
    if(pid1 == 0){
        printf("pid1 process %d\n", getpid());
        pid2 = fork();
        if(pid2 == -1){
            perror("fork");
            return 1;
        }
        if(pid2 == 0){
            printf("pid2 process %d\n", getpid());
        }
        else{
            printf("pid1 parent process %d\n", getpid());
        }
    }
    else{
        printf("pid parent process %d", getpid());
    }
    return 0;
}