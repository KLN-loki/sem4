// 9. Implement process synchronization using Semaphores (use any one real time example
// application)

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int buffer = 10;

void *producer(void *args){
    int x = buffer;
    x++;
    sleep(1);
    buffer = x;
    printf("By producer buffer : %d\n", buffer);
}

void *consumer(void *args){
    int y = buffer;
    y--;
    sleep(1);
    buffer = y;
    printf("By consumer buffer : %d\n", buffer);
}

int main(){
    pthread_t t1, t2;
    printf("Initial Buffer size : %d\n", buffer);
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final Buffer size : %d\n", buffer);
    pthread_exit(NULL);
}