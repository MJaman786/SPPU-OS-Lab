#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	int fd;
	
	char * myfifo = "/tmp/myfifo";
	
	char arr1[100], arr2[100];
	
	mkfifo(myfifo, 0666);
	
	while(1){
		
		//reading part
		
		fd = open(myfifo, O_RDONLY);
		
		read(fd, arr1, sizeof(arr1));
		
		printf("\nUser1 : %s",arr1);
		int i = 0, word = 0, character = 0, line = 0;

        while (arr1[i] != '\0') {
            if (arr1[i] == ' ') {
                word++;
            } else if (arr1[i] == '\n') {
                line++;
            } else {
                character++;
            }
            i++;
        }
        
        printf("Number of words   : %d\n", word);
        printf("Number of lines   : %d\n", line);
        printf("Number of characters: %d\n", character);
		
		close(fd);
		
		//writing part
		
		fd = open(myfifo, 0666);
		printf("\nYou(User2) : ");
		fgets(arr2, 100, stdin);	
		write(fd, arr2, strlen(arr2)+1);
		int word1 = 0, character1 = 0, line1 = 0;
        while(arr2[i] != '\0'){
        	if(arr2[i] == ' '){
        		word1 ++;
        	}
        	else if(arr2[i] == '\n'){
        		line1 ++;
        	}
        	else{
        		character1 ++;
        	}
        	i++;
        }
        printf("Number of words   : %d\n", word);
        printf("Number of lines   : %d\n", line);
        printf("Number of characters: %d\n", character);
        close(fd);
		close(fd);
	
	}

	return 0;

}

