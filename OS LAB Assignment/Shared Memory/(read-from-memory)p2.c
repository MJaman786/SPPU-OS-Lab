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
	while(str->flag == 0){
		printf("Waiting.....\n");
		sleep(5);
	}
	printf("Data read : %s\n",str->buffer);
	str->flag = 0;
	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
