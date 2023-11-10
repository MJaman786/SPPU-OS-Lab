#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int in = 0;
int out = 0;

sem_t empty;
sem_t full;

int buffer[10];

void *producer(void *arg) {
  while (1) {
    // Wait for the buffer to have an empty slot
    sem_wait(&empty);

    // Produce an item
    int item = rand() % 100;

    // Check if the buffer is full
    if (in == out) {
      // Wait for the buffer to have an empty slot
      sem_wait(&empty);
    }

    // Store the item in the buffer
    buffer[in] = item;
    in = (in + 1) % 10;

    // Signal that the buffer has a new item
    sem_post(&full);

    printf("Producer with ID = %ld Produced item = %d\n", pthread_self(), item);
    sleep(2);
  }

  return NULL;
}

void *consumer(void *arg) {
  while (1) {
    // Wait for the buffer to have an item
    sem_wait(&full);

    // Check if the buffer is empty
    if (in == out) {
      // Wait for the buffer to have an item
      sem_wait(&full);
    }

    // Get the item from the buffer
    int item = buffer[out];
    out = (out + 1) % 10;

    // Signal that the buffer has an empty slot
    sem_post(&empty);

    printf("Consumer with ID = %ld Consumed item = %d\n", pthread_self(), item);
    printf("\n");
    sleep(2);
  }

  return NULL;
}

int main() {
  // Initialize the semaphores
  sem_init(&empty, 0, 10);
  sem_init(&full, 0, 0);

  // Create the producer and consumer threads
  pthread_t producer_thread, consumer_thread;
  pthread_create(&producer_thread, NULL, producer, NULL);
  pthread_create(&consumer_thread, NULL, consumer, NULL);

  // Join the producer and consumer threads
  pthread_join(producer_thread, NULL);
  pthread_join(consumer_thread, NULL);

  return 0;
}
/*
 ------------------------ output --------------------
 
 Producer with ID = 139896102581824 Produced item = 83
Consumer with ID = 139896094189120 Consumed item = 83

Producer with ID = 139896102581824 Produced item = 86
Consumer with ID = 139896094189120 Consumed item = 86

Producer with ID = 139896102581824 Produced item = 77
Consumer with ID = 139896094189120 Consumed item = 77

Producer with ID = 139896102581824 Produced item = 15
Consumer with ID = 139896094189120 Consumed item = 15

Producer with ID = 139896102581824 Produced item = 93
Consumer with ID = 139896094189120 Consumed item = 93

Producer with ID = 139896102581824 Produced item = 35
Consumer with ID = 139896094189120 Consumed item = 35

Producer with ID = 139896102581824 Produced item = 86
Consumer with ID = 139896094189120 Consumed item = 86

Producer with ID = 139896102581824 Produced item = 92
Consumer with ID = 139896094189120 Consumed item = 92

Producer with ID = 139896102581824 Produced item = 49
Consumer with ID = 139896094189120 Consumed item = 49

*/
