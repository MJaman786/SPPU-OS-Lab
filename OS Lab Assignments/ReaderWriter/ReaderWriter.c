#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

// Create two semaphore
sem_t write_semaphore;
sem_t read_semaphore;

// Create a counting variable
int rd_count = 0;

// writing function
void *WriterFunction(void *arg){
	
	sem_wait(&write_semaphore);
		printf("Writer is doing writing operation %ld\n",pthread_self());
	sem_post(&write_semaphore);

}

// reading function
void *ReaderFunction(void *arg){
	sem_wait(&read_semaphore);
		rd_count++;
		// if it is first reader then lock the writer
			if(rd_count == 1){
				sem_wait(&write_semaphore);
			}
	sem_post(&read_semaphore);
	// -------------
	printf("Reader is performing reading operation %ld\n",pthread_self());
	// -------------
	sem_wait(&read_semaphore);
		rd_count--;
		// if it is last reader then unlock the writer
			if(rd_count == 0){
				sem_post(&write_semaphore);
			}
	sem_post(&read_semaphore);
}

int main(){
	
	// initalize the semahore
	sem_init(&write_semaphore,0,1);
	sem_init(&read_semaphore,0,1);
	
	// Create 3 threads for writer and reader
	pthread_t writer_thread[3], reader_thread[3];
	
	for(int i=0; i<3; i++){
		pthread_create(&writer_thread[i],NULL,WriterFunction,NULL);
		sleep(1);
	}
	
	for(int i=0; i<3; i++){
		pthread_create(&reader_thread[i],NULL,ReaderFunction,NULL);
		sleep(1);
	}
	
	for(int i=0; i<3; i++){
		pthread_join(writer_thread[i],NULL);
		pthread_join(reader_thread[i],NULL);
	}
	//sleep(1);
	return 0;

}
/*
----------------- output ------------------
window@window-virtual-machine:~$ ./RW.out
Writer is doing writing operation 139912252749376
Writer is doing writing operation 139912244356672
Writer is doing writing operation 139912235963968
Reader is performing reading operation 139912227571264
Reader is performing reading operation 139912219178560
Reader is performing reading operation 139912210785856

window@window-virtual-machine:~$ gcc RW.c -o RW.out
window@window-virtual-machine:~$ ./RW.out
Writer is doing writing operation 140280867059264
Writer is doing writing operation 140280858666560
Writer is doing writing operation 140280850273856
Reader is performing reading operation 140280841881152
Reader is performing reading operation 140280833488448
Reader is performing reading operation 140280825095744

window@window-virtual-machine:~$ gcc RW.c -o RW.out
window@window-virtual-machine:~$ ./RW.out
Writer is doing writing operation 140202540529216
Writer is doing writing operation 140202532136512
Writer is doing writing operation 140202523743808
Reader is performing reading operation 140202515351104
Reader is performing reading operation 140202506958400
Reader is performing reading operation 140202429380160
*/
