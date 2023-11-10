#include <stdio.h>
#include <stdlib.h>

int bubble(int arr[], int size){
  int temp;
  for(int i=0; i<size-1; i++){
    for(int j=0; j<size-i-1; j++){
      if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int BinarySearch(int arr[], int size, int start, int end, int key){
	int mid;
	if(start<=end){
		mid = (start + end)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]>key){
			return BinarySearch(arr, size, start, (mid-1), key);
		}
		else{
			return BinarySearch(arr, size, (mid+1), end, key);
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {

    int size = argc - 1;
    int arr[size];
    int sum = 0;
    
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
        sum = sum + arr[i - 1];
    }

	bubble(arr,size);
	//bubblesort:
	bubble(arr,size);
	printf("-> After sorting = ");
	for(int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	//binarrySearch
	int key;
	printf("\nEnter the element to serch = ");
	scanf("%d",&key);
	int result = BinarySearch(arr,size,0,size-1,key);
	if(result == -1){
	  printf("Element not found !\n");
	}
	else{
	  printf("\n-> Element found at index : %d\n",result);
	}
    printf("\nSum = %d\n", sum);

    return 0;
}

