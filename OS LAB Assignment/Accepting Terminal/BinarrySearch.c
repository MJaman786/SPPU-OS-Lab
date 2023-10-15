/*
PROBLEM : 
    B. Implement the C program in which main program accepts an array. Main program uses the FORK
    system call to create a new process called a child process. Parent process sorts an array and passes
    the sorted array to child process through the command line arguments of EXECVE system call. The
    child process uses EXECVE system call to load new program which display array in reverse order.

*/
#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[], int num, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (num == arr[mid]) {
            return mid;
        } else if (num < arr[mid]) {
            return BinarySearch(arr, num, low, mid - 1);
        } else {
            return BinarySearch(arr, num, mid + 1, high);
        }
    }
    
    return -1; // Return -1 if the element is not found
}

int main(int argc, char *argv[]) {
    int num;
    /*
    if (argc < 2) {
        printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }
    */
	// argc returns the number of argument from the array
    int arr[argc - 1], i, sum = 0;
    for (i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]); //(atoi) means assci-to-int
        sum = sum + arr[i - 1];
    }
    printf("sum = %d\n", sum);

    printf("Enter number to search = ");
    scanf("%d", &num);

    int result = BinarySearch(arr, num, 0, argc - 2);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
/*
sum = 21
Enter number to search = 3
Element found at index 2
*/

