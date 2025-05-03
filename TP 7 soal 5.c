#include<stdio.h>
#include<string.h>

typedef struct{
    char string[100];
    int number;
}Object;

void insertionInt_Up(Object arr[], int n){
	for(int i = 1; i < n; i++){
		Object curr = arr[i];
		int j = i-1;
		while(j>=0 && curr.number < arr[j].number){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = curr;
	}
}
void insertionInt_Down(Object arr[], int n){
	for(int i = 1; i < n; i++){
 		Object curr = arr[i];
 		int j = i-1;
		while(j>=0 && curr.number > arr[j].number){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = curr;
	}
}

void insertionString_Up(Object arr[], int n){
	for(int i = 1; i < n; i++){
		Object curr = arr[i];
		int j = i-1;
		while(j>=0 && strcmp(curr.string,arr[j].string) < 0){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = curr;
	}
}
void insertionString_Down(Object arr[], int n){
	for(int i = 1; i < n; i++){
		Object curr = arr[i];
		int j = i-1;
		while(j>=0 && strcmp(curr.string,arr[j].string) > 0){
			arr[j + 1] = arr[j];
			j--;
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
	   Object arr[5] = {
        {"Jeruk", 20},
        {"Apel", 15},
        {"Mangga", 25},
        {"Anggur", 10},
        {"Pisang", 30}
    };
	
	printf("data awal\n");
	print(arr,5);
	
	printf("berdasarkan string naik\n\n");
	insertionString_Up(arr,5);
	print(arr,5);
	
	printf("berdasarkan string turun\n\n");
	insertionString_Down(arr,5);
	print(arr,5);
	
	printf("berdasarkan integer naik\n\n");
	insertionInt_Up(arr,5);
	print(arr,5);
	
	printf("berdasarkan integer turun\n\n");
	insertionInt_Down(arr,5);
	print(arr,5);
}