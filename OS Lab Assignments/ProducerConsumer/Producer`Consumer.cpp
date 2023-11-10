/*
 Produser - Consumer Problem

    - Consider Buffer of size[7];
    
            |-------------------|
    1   -   |                   |
            |-------------------|
    2   -   |                   |
            |-------------------|
    3   -   |                   |
            |-------------------|
    4   -   |                   |
            |-------------------|
    5   -   |                   |
            |-------------------|
    6   -   |                   |
            |-------------------|
    7   -   |                   |
            |-------------------|

    sudo code for Producer :

    void producer(void){
        int itemp;
        while(true){
            produce_item(itemp);
            while(count == n);
                Buffer[in] = itemp;
                in = (in + 1) mod n;
            count = count + 1;
        }
    }
  
    void consumer(void){
        while(true){
                while(count == 0);
            itemc = Buffer[out];
            out = (out + 1) mod n;

            count = count + 1; 
        }
    }

*/
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Added for sleep function

// Initializing buffer-size
int buffer[10];

// Indexes
int in = 0;
int out = 0;

// Semaphores
sem_t empty;
sem_t full;

// Producer
void *producer(void *arg) {
    while (1) {
    //wait for empty space in buffer
        sem_wait(&empty); //(empty --)
		    int item = rand() % 100;
		    buffer[in] = item;
		    in = (in + 1) % 10; // Wrap around if the buffer is full
        sem_post(&full);//(full --)
        printf("Produced item = %d\n", item);
        sleep(3); // Sleep for a short time to simulate work
    }
}

void *consumer(void *arg) {
    while (1) {
    // wait for fill the buffer
        sem_wait(&full);//(full --)
		    int item = buffer[out];
		    out = (out + 1) % 10; // Wrap around if the buffer is empty
        sem_post(&empty);//(empty --)
        printf("Consumed item = %d\n", item);
        printf("\n");
        sleep(3); // Sleep for a short time to simulate work
    }
}

int main() {
    sem_init(&empty, 0, 10);
    sem_init(&full, 0, 0);

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL); // Create a consumer thread

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
/*
------------ output -------------
Produced item = 83
Consumed item = 83

Produced item = 86
Consumed item = 86

Produced item = 77
Consumed item = 77

Produced item = 15
Consumed item = 15

Produced item = 35
Consumed item = 35

Produced item = 86
Consumed item = 86

Produced item = 92
Consumed item = 92

Produced item = 49
Consumed item = 49

Produced item = 21
Consumed item = 21

*/