#include<stdio.h>

void insertionUp(int arr[], int n){
	for(int i = 1; i < n; i++){
		int curr = arr[i];
		int j = i-1;
		while(j>=0 && curr < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = curr;
	}
}
void insertionDown(int arr[], int n){
	for(int i = 1; i < n; i++){
		int curr = arr[i];
		int j = i-1;
		while(j>=0 && curr > arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = curr;
	}
}
void print(int arr[], int n){
	for(int i = 0 ; i < n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}

int main(){
	int arr[]={5,2,4,3,1};
	
	printf("data awal\n");
	print(arr,5);
	
	printf("urut naik\n");
	insertionUp(arr,5);
	print(arr,5);
	
	printf("urut turun\n");
	insertionDown(arr,5);
	print(arr,5);
}