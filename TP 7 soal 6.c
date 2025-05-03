#include<stdio.h>
#include<string.h>

typedef struct{
    char string[100];
    int number;
}Object;

int conversion(char string[]){
	if (!strcmp(string,"Apel")){
		return 1;
	}else if (!strcmp(string,"Jeruk")){
		return 2;
	}else if (!strcmp(string,"Mangga")){
		return 3;
	}else if (!strcmp(string,"Pisang")){
		return 4;
	}else {
		return -1;
	}
}


void insertionString_Up(Object arr[], int n){
	
	for(int i = 1; i < n; i++){
		
		Object curr = arr[i];
		int j = i-1;
		
		while(j >= 0){
			int cmp = conversion(curr.string) - conversion(arr[j].string);
			if(cmp < 0 || (cmp == 0 && curr.number > arr[j].number)){
				arr[j + 1] = arr[j];
				j--;
			} else {
				break;
			}
		}
		
		arr[j+1] = curr;
	}
}


void print(Object arr[], int n){
 for (int i = 0; i < n; i++) {
        printf("%s, %d\n", arr[i].string, arr[i].number);
    }
	printf("\n");
}

int main(){
	   Object arr[8] = {
        {"Jeruk", 20},
        {"Apel", 15},
        {"Mangga", 25},
        {"Apel", 10},
        {"Pisang", 30},
        {"Apel", 40},
        {"Mangga", 5},
        {"Pisang", 20}		
    };
	
	printf("data awal\n\n");	
	print(arr,8);
	
	printf("hasil pengurutan berdasarkan string naik dan angka turun\n\n");
	insertionString_Up(arr,8);
	print(arr,8);
	

}