// 9. Implement process synchronization using Semaphores (use any one real time example
// application)

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int buffer = 10;
sem_t s;

void *producer(void *args){
    sem_wait(&s);
    int x = buffer;
    x++;
    sleep(1);
    buffer = x;
    printf("By producer buffer : %d\n", buffer);
    sem_post(&s);
}

void *consumer(void *args){
    sem_wait(&s);
    int y = buffer;
    y--;
    sleep(1);
    buffer = y;
    printf("By consumer buffer : %d\n", buffer);
    sem_post(&s);
}

int main(){
    pthread_t t1, t2;
    sem_init(&s, 0, 1);
    printf("Initial Buffer size : %d\n", buffer);
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final Buffer size : %d\n", buffer);
    pthread_exit(NULL);
}