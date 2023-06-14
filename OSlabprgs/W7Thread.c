// 7. Implement the following:
// i) Program to create threads in Linux. Thread prints 0-4 while the main process prints
// 20-24

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *printFun(void *args){
    int i;
    for(i = 0; i < 5; i++){
        printf("%d\n", i);
    }
    pthread_exit(NULL);
}

//For execution use command : gcc <filename> -o thread -lpthread
//For output : ./thread

int main(){
    pthread_t tid;
    int res, i;
    res = pthread_create(&tid, NULL, printFun, NULL);
    if(res){
        perror("thread error");
        exit(EXIT_FAILURE);
    }
    for(i = 20; i < 25; i++){
        printf("%d\n", i);
    }
    pthread_join(tid, NULL);
    return 0;
}
