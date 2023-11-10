#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

int in = 0, out = 0;
int buffer[5];
sem_t s, e, f;

void *producer(void *arg)
{
    int data;
    sem_wait(&e);
    sem_wait(&s);
    data = rand() % 1000;
    buffer[in] = data;
    printf("Producer %ld has entered data : %d\n", pthread_self(), data);
    in = (in + 1) % 5;
    sem_post(&s);
    sem_post(&f);
}

void *consumer(void *arg)
{
    int val, data;

    do
    {
        sem_wait(&f);
        sem_wait(&s);
        data = buffer[out];
        printf("Product has consumed by %ld : %d\n", pthread_self(), data);
        out = (out + 1) % 5;
        sem_post(&s);
        sem_post(&e);
        sem_getvalue(&e, &val);
    } while (val != 5);
}

int main()
{

    pthread_t tid[5], cid;

    sem_init(&e, 0, 5);
    sem_init(&f, 0, 0);
    sem_init(&s, 0, 1);

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&tid[i], NULL, producer, NULL);
    }
    pthread_create(&cid, NULL, consumer, NULL);

    for (int i = 0; i < 2; i++)
    {
        pthread_create(&tid[i], NULL, producer, NULL);
    }

    pthread_create(&cid, NULL, consumer, NULL);

    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_join(cid, NULL);

    return 0;
}

/*

Producer 1408193144 has entered data : 23
Producer 1408193144 has entered data : 83
Producer 1408193144 has entered data : 54
Producer 1408193144 has entered data : 7
Producer 1408193144 has entered data : 67
Consumer has consumed by 1408193145 : 23
Producer 1408193145 has entered data : 62
Consumer has consumed by 1408193145 : 83
Producer 1408193145 has entered data : 45
Consumer has consumed by 1408193145 : 54
Producer 1408193145 has entered data : 99
Consumer has consumed by 1408193145 : 7
Producer 1408193145 has entered data : 13
Consumer has consumed by 1408193145 : 67

*/