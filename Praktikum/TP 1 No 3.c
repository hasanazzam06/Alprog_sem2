#include <stdio.h>

int main(){
	int lenght;
	printf("masukan panjang bangunan : ");
	scanf("%d", &lenght);
	
	int i = 0, j = 0;
	
	while(i < lenght){
		while (j  < lenght){
			if (j == lenght-(i+1)){
				printf("*");
			}else{
				printf(" ");
			}
			j++;	
		}
		if(i != 0){
			printf("*");
		}
		printf("\n");
		j = 0;
		i++;
	}
	
	while(i > 1){
		while (j  < lenght){
			if (j == lenght-(i-1)){
				printf("*");
			}else{
				printf(" ");
			}
			j++;
		}
		if(i != 2){
			printf("*");
		}
		printf("\n");
		j = 0;
		i--;
	}
	
	return 0;
}