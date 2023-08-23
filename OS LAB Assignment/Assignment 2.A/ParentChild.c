/*
PROBLEM :
    A. Implement the C program in which main program accepts the integers to be sorted. Main program
    uses the FORK system call to create a new process called a child process. Parent process sorts the
    integers using sorting algorithm and waits for child process using WAIT system call to sort the integers
    using any sorting algorithm. Also demonstrate zombie and orphan states.
*/
/*
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main(){
	pid_t pid,cpid;
	int status;
	pid=fork();
	
	if(pid==0){
	// Context of clid process
		printf("\nThis is child process with ID  = %d",getpid());
		printf("\nThis is child process with parent process id = %d",getppid());
		printf("\nIn child process pid value reveived is = %d",pid);
	}
	else{
	// Context of parent process
		sleep(3);
		system("ps");
		cpid=wait(&status);
		system("ps");
		printf("\nTerminated child is = %d",cpid);
		printf("\nThis parent process wit id = %d",getpid());
		printf("\nThis is parent process with parent process id = %d",getppid());
		printf("\nIn parent process pid value recived is = %d",pid);
	}
}
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> // Include the necessary header for the wait function

int main() { // Use int instead of void for main
    pid_t pid, cpid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Context of child process
        printf("\nThis is child process with ID = %d", getpid());
        printf("\nThis is child process with parent process id = %d", getppid());
        printf("\nIn child process pid value received is = %d\n", pid);
    } else if (pid > 0) {
        // Context of parent process
        sleep(3);
        //system("ps");
        cpid = wait(&status); // Use wait to wait for child process to complete
        //system("ps");
        printf("\nTerminated child is = %d", cpid);
        printf("\nThis parent process with id = %d", getpid());
        printf("\nThis is parent process with parent process id = %d", getppid());
        printf("\nIn parent process pid value received is = %d\n", pid);
    } else {
        // Error handling if fork fails
        perror("Fork failed");
        return 1;
    }

    return 0;

}

/*
Certainly! Let's break down the code step by step and explain each part in detail.

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
```

- `#include` directives are used to include necessary header files. In this code, you're including standard C libraries (`stdio.h`, `unistd.h`) and system-specific libraries (`sys/types.h`, `sys/wait.h`) that provide functions and data types for various system operations.

```c
int main() {
    pid_t pid, cpid;
    int status;

    pid = fork();
```

- The `main()` function is the entry point of the program. It returns an integer (`int`) to indicate the exit status of the program.

- `pid_t` is a data type used for process IDs. In this code, `pid` and `cpid` are variables of type `pid_t`.

- `fork()` is a system call that creates a new process (child process) by duplicating the current process (parent process). After `fork()`, there are two identical processes running, and they differ only in their process IDs (`pid`). The value of `pid` helps us determine whether the code is being executed in the parent or child process.

```c
    if (pid == 0) {
        // Context of child process
        printf("\nThis is child process with ID = %d", getpid());
        printf("\nThis is child process with parent process id = %d", getppid());
        printf("\nIn child process pid value received is = %d\n", pid);
    } else if (pid > 0) {
```

- This block of code checks the value of `pid` to determine if the current process is the parent or the child process.

- If `pid` is 0, this means we are in the child process. The child process prints its own process ID using `getpid()` and its parent process ID using `getppid()`.

- If `pid` is greater than 0, this means we are in the parent process. The parent process will move to the next part of the code.

```c
        sleep(3);
        system("ps");
```

- The `sleep(3)` function call causes the parent process to pause execution for 3 seconds. During this time, the child process continues to execute.

- `system("ps")` is used to run the "ps" command, which displays information about running processes. This is done to observe the processes before and after the child process termination.

```c
        cpid = wait(&status);
```

- The `wait(&status)` system call is used by the parent process to wait for the child process to complete. The `&status` parameter is a pointer to an integer where the exit status of the child process will be stored.

```c
        system("ps");
        printf("\nTerminated child is = %d", cpid);
        printf("\nThis parent process with id = %d", getpid());
        printf("\nThis is parent process with parent process id = %d", getppid());
        printf("\nIn parent process pid value received is = %d\n", pid);
    } else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}
```

- After the child process terminates, the parent process continues executing. `system("ps")` is used again to display process information after the child process terminates.

- `cpid` now contains the process ID of the terminated child process, which is printed using `printf`.

- The parent process also prints its own process ID and its parent process ID.

- Finally, the `return 0;` statement indicates a successful execution of the program, and `return 1;` is used in the error handling block if the `fork()` call fails.

This code demonstrates the basic concepts of process creation using `fork()` and the use of `wait()` to synchronize between parent and child processes. It also illustrates the distinction between the parent and child processes using their respective process IDs.
*/

