#include <stdio.h>

int main(){
	//membuat var dengan maximal 50 carakter
	char name[50];
	printf("masukkan nama anda : ");
	scanf("%[^\n]s",name);
	//input nama,[^\n] -> digunakan untuk membatasi akhir input oleh enter
	printf("Hello %s", name);
	// mencetak hasil
	return 0;
}