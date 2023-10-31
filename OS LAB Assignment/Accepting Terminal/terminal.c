#include<stdio.h>
#include<stdlib.h>

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

int main(){
	int size;
	printf("Enter Size of the array = ");
	scanf("%d",&size);	
	
	int arr[size];
	printf("Enter the array elements = ");
	for(int i=0; i<size; i++){
		scanf("%d",&arr[i]);
	}
	
	int key;
	printf("Enter the number to find : ");
	scanf("%d",&key);
	
	//bubblesort:
	bubble(arr,size);
	printf("-> After sorting = ");
	for(int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
	
	
	int result = BinarySearch(arr,size,0,size-1,key);
	if(result == -1){
	  printf("Element not found !\n");
	}
	else{
	  printf("\n-> Element found at index : %d\n",result);
	}
	return 0;
}
