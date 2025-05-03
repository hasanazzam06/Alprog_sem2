// Nama		 : Hasan Abdullah Azzam
// NPM		 : 2406428314
// Note		 : TP 3 alprog
// Deskirpsi : program menghitung nilai ASCII dari suatu string, mengganti nilai string menggunakkan realloc.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate(int *value, char *arr){
	*value = 0;
	
	for(int i = 0; arr[i] != '\0'; i++){
		*value += (int) arr[i];
	}
}

void changename(char **arr){
	char temp[50];
	
	printf("masukkan nama : ");
	
	scanf(" %49s", temp);	
	
	int panjang = strlen(temp) + 1;
	
	*arr = (char *) realloc(*arr, panjang * sizeof(char));
	
	if(*arr == NULL){
		printf("Error");
		return;
	}
	
	strcpy(*arr,temp);
}

int main(){
	int value;
	char *arr = (char *) malloc(1 * sizeof(char));
	
	if(arr == NULL){
		printf("error");
		return 1;
	}
	
	changename(&arr);
	
	while(1){
		char opsi;
		printf("\n==========\n");
		printf("nama saat ini : %s\n", arr);
		printf("pilihan :\n");
		printf("a. Nilai ASCII dari nama\n");
		printf("b. Ganti nama\n");
		printf("c. Exit\n");
		printf("Masukkan opsi : ");
		
		scanf(" %c", &opsi);
		printf("\n==========\n");
		
		switch(opsi){
			case 'a':
				calculate(&value, arr);
				printf("total nilai ASCII : %d\n",value);
				break;
			case 'b':
				changename(&arr);
				break;
			case 'c':
				printf("program telah selesai");
				break;
			default:
				printf("masukkan angka yang benar!!\n");
		}
		
		if(opsi == 'c'){
			break;
		} 
	}
	
	free(arr);
	
	return 0;
}