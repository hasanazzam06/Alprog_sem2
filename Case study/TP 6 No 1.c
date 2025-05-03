#include<stdio.h>

int binarySearch(int arr[], int l, int h, int target){
	int middle,hasil;

	while(l <= h){
		middle = (l + h)/2; 
		
		if(arr[middle] == target){
			break;
		}
		
		if(arr[middle] < target){	
			l = middle + 1;
		}else{
			h = middle - 1;
		}
	}
	
	if(l > h){
		hasil = -1;
		printf("angka %d tidak ditemukan\n",target);
	}else{
		hasil = middle;
		printf("angka %d ditemukan di indeks ke-%d\n",target,hasil);
	}
	
	return hasil;
}

int main(){
	int arr[] = {77, 78, 83, 83, 90, 98, 100};
	int size = sizeof(arr)/sizeof(arr[0]);
	int target = 100;
	int hasil = binarySearch(arr,0, size-1,target);
	return 0;
}