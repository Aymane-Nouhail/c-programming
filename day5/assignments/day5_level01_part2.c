#include<stdio.h>
#include<stdlib.h>


void printArray(int* arr, int n){
    printf("[");
    for(int i=0;i<n;i++)
        printf("%d, ",arr[i]);
    printf("\b\b]");
}


void isort(int **arr, size_t length){
    //selection sort
    double temp;
	for(int i = 0 ; i<length ; i++){
		for(int j = 0 ; j<length ; j++){
			if((*arr)[i] < (*arr)[j]){
				temp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = temp;
			}
		}
	}
}

int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Unsorted : ");
    printArray(arr,n);
    isort(&arr,n);
    printf("\nSorted   : ");
    printArray(arr,n);
    free(arr);
    return 0;
}