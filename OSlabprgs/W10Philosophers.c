// 10.2 Solution to Dining Philosopher Problem

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define n 5

sem_t s[n];

void *DiningPhilo(void *args){
    int i = *(int*)args;
    sem_wait(&s[i]);
    sem_wait(&s[(i+1)%n]);
    printf("%d eating...\n", i);
    sleep(1);
    printf("%d stooped eating...\n", i);
    sem_post(&s[(i+1)%n]);
    sem_post(&s[i]);
    return NULL;
}

int main(){
    int i, val[n];
    pthread_t t[n];
    for(i = 0; i < n; i++){
        sem_init(&s[i], 0, 1);
    }
    for(i = 0; i < n; i++){
        val[i] = i;
        pthread_create(&t[i], NULL, DiningPhilo, &val[i]);
    }
    for(i = 0; i < n; i++){
        pthread_join(t[i], NULL);
    }
    pthread_exit(NULL);
}
