#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct shem {
    char buffer[100];
    int flag;
};

int main() {
    // ftok to generate a unique key
    key_t key = ftok("shmfile", 65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key, sizeof(struct shem), 0666 | IPC_CREAT);

    // shmat to attach to shared memory
    struct shem *str = (struct shem *)shmat(shmid, (void *)0, 0);

    while (str->flag == 0) {
        printf("Waiting...\n");
        //sleep(1); // Sleep for a while before checking the flag again
    }

    // Print data read from memory
    printf("Data read from memory: %s\n", str->buffer);

    str->flag = 0;

    // Detach from shared memory
    shmdt(str);

    // Destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
/*
------- output ----------

student@student:~$ gcc shared_memory_client.c -o clent.out
student@student:~$ ./clent.out
Data read from memory: Shared Memory 

*/
