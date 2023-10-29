#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

struct shem {
    char buffer[100];
    int flag;
};

int main() {
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key, sizeof(struct shem), 0666 | IPC_CREAT);

    // shmat to attach to shared memory
    struct shem *str = (struct shem *)shmat(shmid, (void *)0, 0);
    str->flag = 0;
    printf("Write Data : ");
    gets(str->buffer); // Note: gets is unsafe, consider using fgets
    str->flag = 1;

    while (str->flag != 0) {
        printf("Waiting...\n");
        //sleep(1); // Sleep for a while before checking the flag again
    }

    printf("Data written in memory: %s\n", str->buffer);

    // Detach from shared memory
    shmdt(str);

    // Remove the shared memory segment (optional)
    //shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

/*
------- output ---------
student@student:~$ gcc shared_memory_server.c -o server.out
student@student:~$ ./server.out
Waiting...
Waiting...
Waiting...
Waiting...
Waiting...
Data written in memory: Shared Memory 

*/


