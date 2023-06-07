// 6. ii) Create two child process C1 and C2. Make sure that only C2 becomes an Orphan
// process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1 == -1){
        perror("fork");
        return 1;
    }
    if(pid1 == 0){
        printf("C1 created\n");
        pid2 = fork();
        if(pid2 == -1){
            perror("fork");
            return 1;
        }
        if(pid2 == 0){
            printf("C2 created.\n");
            printf("C2 sleeping.\n");
            sleep(2);
            printf("C2 exiting.\n");
        }
        else{
            printf("C1 waiting.\n");
            sleep(1);
            printf("C1 exiting.\n");
            exit(0);
        }
    }
    else{
        printf("C waiting\n");
        sleep(4);
        printf("C exiting\n");
    }
    return 0;
}