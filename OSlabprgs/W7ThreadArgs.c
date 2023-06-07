// 7. ii) Program to create a thread. The thread prints numbers from zero to n, where value of
// n is passed from the main process to the thread. The main process also waits for the
// thread to finish first and then prints from 20-24.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *printFun(void *args){
    int n = *(int*)args;
    int i;
    for(i = 0; i <= n; i++){
        printf("%d\n", i);
    }
    pthread_exit(NULL);
}

int main(){
    int n, res;
    printf("Enter n : ");
    scanf("%d", &n);
    pthread_t tid;
    res = pthread_create(&tid, NULL, printFun, &n);
    if(res){
        perror("thread error");
        exit(EXIT_FAILURE);
    }
    pthread_join(tid, NULL);
    for(n = 20; n < 25; n++){
        printf("%d\n", n);
    }
    pthread_exit(NULL);
}