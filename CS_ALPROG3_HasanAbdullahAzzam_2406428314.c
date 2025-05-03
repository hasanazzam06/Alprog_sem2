//nama	: Hasan Abdullah Azzam
//NPM	: 2406428314
//Note	: case study pointer alprog 

#include <stdio.h>
#include <string.h>

void translasi(char *str, int panjang){
	
	char temp;
	
	for (int i = 0 ; i < (int)(panjang/2) ; i++){
		temp = *(str + 2*i);
		*(str + 2*i) = *(str + 1 + 2*i);
		*(str + 1 + 2*i) = temp; 
	}
	
}

int main(){
	char str[50];
	
	printf("masukkan string : ");
	scanf("%[^\n]s", str);
	
	int panjang = strlen(str);
	
	translasi(str,panjang);
	printf("----------\n");
	printf("hasil dari translasi : ");
	printf("%s", str);
	
	return 0;	
}