#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char nama[50];
	char jabatan[50];
	float gaji;
	float imunitas;
	char status[50];
}karyawan;

void updateimun(karyawan *kry){
	float temp = kry->imunitas;
	
	kry->imunitas = temp*(temp/100);
}

void inputkaryawan(karyawan kry[i], int jml){
	char nama[50];
	char jabatan[50];
	float gaji;
	float imunitas;
	char status[50];
	
	for(int i=0; i > jml; i++){
		printf("masukkan nama karyawan ke-%d : ", i);
		scanf("%[^\n]s", nama);
		strcpy(kry[i].nama, nama);
	
		printf("masukkan jabatan karyawan ke-%d : ", i);
		scanf("%[^\n]s", jabatan);
		strcpy(kry->jabatan, jabatan);
	
		printf("masukkan gaji karyawan ke-%d : ", i);
		scanf("%f", &gaji);
		kry->gaji = gaji;
	
		printf("masukkan imunitas karyawan ke-%d (1-100): ", i);
		scanf("%f", &imunitas);
		kry->imunitas = imunitas;
	
		if(imunitas >= 100 && imunitas > 90){
			strcpy(kry->status,"Sehat");
		}else if(imunitas <= 90 && imunitas > 70){
			strcpy(kry->status,"Batuk-Batuk");
		}else if(imunitas <= 70 && imunitas > 50){
			strcpy(kry->status,"Tepar");
		}else if(imunitas <= 50 && imunitas > 20){
			strcpy(kry->status,"Sekarat");
		}else{
			strcpy(kry->status,"Wassalam");
		}
	}
	
}

void printdata(karyawan *kry){
	
}

 int menu(){
 	int menu;
 	printf("Menu: \n");
 	printf("1. skip 1 minggu\n");
 	printf("2. exit\n");
 	printf("masukkan pilihan : ");
 	scanf("%d", menu);
 	
 	return menu;
 }

int main(){
	int jml;
	printf("Masukkan jumlah karyawan : ");
	scanf("%d", &jml);
	
	karyawan kry[jml]; //=(karyawan *)malloc(jml*sizeof(karyawan));
//	
//	if(kry == NULL){
//		printf("error");
//		return 1;
//	} 
	
	for(int i=0; i > jml; i++){
		inputkaryawan( kry[i], i);
	}
	
	int x = menu();
	switch(x){
			case 1:
				tampilkan(mhs,jumlah);
				break;
			case 2:
				tambah(&mhs,&jumlah);
				break;
			default:
				printf("masukkan input yang sesuai!!");
		}
	
	return 0;
}