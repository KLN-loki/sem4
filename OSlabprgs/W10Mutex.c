// 10.1 Program for Process Synchronization using mutex locks

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int buffer = 10;
pthread_mutex_t mutex;

void *producer(void *args){
    pthread_mutex_lock(&mutex);
    int x = buffer;
    x++;
    sleep(1);
    buffer = x;
    printf("By producer buffer : %d\n", buffer);
    pthread_mutex_unlock(&mutex);
}

void *consumer(void *args){
    pthread_mutex_lock(&mutex);
    int y = buffer;
    y--;
    sleep(1);
    buffer = y;
    printf("By consumer buffer : %d\n", buffer);
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);
    printf("Initial Buffer size : %d\n", buffer);
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final Buffer size : %d\n", buffer);
    pthread_exit(NULL);
}