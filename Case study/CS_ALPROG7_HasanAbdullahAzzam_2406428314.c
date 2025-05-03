#include<stdio.h>
#include<string.h>

typedef struct{
	char jenis[50];
	char angka[50];
}Kartu;

int prioritasAngka(char string[]){
	if (!strcmp(string,"As")){
		return 1;
	}else if (!strcmp(string,"King")){
		return 2;
	}else if (!strcmp(string,"Queen")){
		return 3;
	}else if (!strcmp(string,"Jack")){
		return 4;
	}else if (!strcmp(string,"10")){
		return 5;
	}else if (!strcmp(string,"9")){
		return 6;
	}else if (!strcmp(string,"8")){
		return 7;
	}else if (!strcmp(string,"7")){
		return 8;
	}else if (!strcmp(string,"6")){
		return 9;
	}else if (!strcmp(string,"5")){
		return 10;
	}else if (!strcmp(string,"4")){
		return 11;
	}else if (!strcmp(string,"3")){
		return 12;
	}else if (!strcmp(string,"2")){
		return 13;
	}else {
		return -1;
	}
}

int prioritasJenis(char string[]){
	if (!strcmp(string,"Sekop")){
		return 1;
	}else if (!strcmp(string,"Hati")){
		return 2;
	}else if (!strcmp(string,"Keriting")){
		return 3;
	}else if (!strcmp(string,"Wajik")){
		return 4;
	}else {
		return -1;
	}
}

void sortJenis(Kartu arr[], int n){
	
	for(int i = 1; i < n; i++){
		
		Kartu curr = arr[i];
		
		int j = i-1;
		
		while(j >= 0){
			int ujiJenis = prioritasJenis(curr.jenis) - prioritasJenis(arr[j].jenis);
			int ujiAngka = prioritasAngka(curr.angka) - prioritasAngka(arr[j].angka);
			
			if(ujiJenis < 0 || (ujiJenis == 0 && ujiAngka <= 0)){
				arr[j + 1] = arr[j];
				j--;
			} else {
				break;
			}
		}
		
		arr[j+1] = curr;
	}
}

void sortAngka(Kartu arr[], int n){
	
	for(int i = 1; i < n; i++){
		
		Kartu curr = arr[i];
		
		int j = i-1;
		
		while(j >= 0){
			int ujiAngka = prioritasAngka(curr.angka) - prioritasAngka(arr[j].angka);
			int ujiJenis = prioritasJenis(curr.jenis) - prioritasJenis(arr[j].jenis);
			if(ujiAngka < 0 || (ujiAngka == 0 && ujiJenis <= 0)){
				arr[j + 1] = arr[j];
				j--;
			} else {
				break;
			}
		}
		
		arr[j+1] = curr;
	}
}

void print(Kartu arr[],int n){
	for(int i = 0 ; i < n; i++){
		printf("%s %s\n", arr[i].jenis, arr[i].angka);
	}
}

int main(){
	int n, pil;
	Kartu data[1000];
	
	printf("masukkan jumlah kartu: ");
	scanf(" %d",&n);

	printf("Ururtkan berdasarkan : 1. jenis 2. angka : ");
	scanf("%d", &pil);
	
	printf("Masukkan kartu :\n");
	
	for(int i = 0; i < n;i++){
		scanf(" %s %s", data[i].jenis, data[i].angka);
	}
	
	if(pil == 1){
		sortJenis(data,n);
	}else{
		sortAngka(data,n);
	}
	printf("=======================\n");
	printf("\nhasil keluaran kartu yang telah terurut:\n\n");
	print(data,n);
		
	return 0;
}