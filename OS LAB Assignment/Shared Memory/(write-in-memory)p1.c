#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

struct shm{

	char buffer[100];
	int flag;

};

int main(){
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, sizeof(struct shm), 0666 | IPC_CREAT);
	struct shm *str = (struct shm *) shmat(shmid,(void*)0,0);
	str->flag = 0;
	printf("Enter data : ");
	gets(str->buffer);
	printf("Data enterd in memory : %s\n",str->buffer);
	str->flag = 1;
	while(str->flag != 0){
		printf("Waiting for data read from memory ...\n");
		sleep(3);
	}
	printf("\n*****Data read from memory*****\n");
	shmdt(str);
	return 0;
}
