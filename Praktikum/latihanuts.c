#include<stdio.h>

#define SIZE 5

void modif(int arr[SIZE]){
	for(int i = 0; i < SIZE; i++){
		arr[i]*=2;
	}
}
int main(){
	int arr[SIZE] = {1,2,3,4,5};
	for(int i = 0; i < SIZE; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	modif(arr);
	
	for(int i = 0; i < SIZE; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
}
