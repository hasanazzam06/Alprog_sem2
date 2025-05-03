#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int semester;
	float ipk;
	char jurusan[50];
}InfoAkademik;

typedef struct{
	char name[50];
	char NPM[50];
	char alamat[100];
}Identitas;

typedef struct{
	InfoAkademik data;
	Identitas ID;
	char kesibukkan[50];
}Mahasiswa;

void printStruct(Mahasiswa *mhs){
	
	printf("Nama/NPM 	: %s / %s\n", mhs->ID.name, mhs->ID.NPM);
	printf("Alamat 		: %s\n", mhs->ID.alamat);
	printf ("Jurusan 	: %s\n",mhs->data.jurusan);
	printf("Semester 	: %d\n", mhs->data.semester);
	printf("IPK 		: %.2f\n", mhs->data.ipk);
	printf("Kesibukkan 	: %s\n", mhs->kesibukkan);
	printf("------------------\n\n");
	
}


void tampilkan(Mahasiswa *mhs, int jumlah){
	
	printf("\ndaftar Mahasiswa\n");
	printf("------------------\n");
	
	if (jumlah == 0) { 
        printf("\nDaftar Mahasiswa kosong.\n");
        printf("------------------\n");
        return;
    }
	for(int i = 0; i < jumlah; i++){
		printf("Mahasiswa ke-%d:\n", i + 1);
		printStruct(mhs+i);
	}
	
}

void tambah(Mahasiswa **mhs, int *jml){
	
	(*jml)++;
	
	*mhs = (Mahasiswa *)realloc(*mhs, (*jml) * sizeof(Mahasiswa));
	
	if(*mhs == NULL){
		printf("error");
		return;
	}
	
	
	printf("\nSilahkan isi data berikut :\n");
	printf("------------------\n");
	
	printf("Nama 		: ");
	scanf(" %[^\n]", (*mhs)[*jml - 1].ID.name);
	
	printf("NPM 		: ");
	scanf(" %[^\n]", (*mhs)[*jml - 1].ID.NPM);
	
	printf("Alamat 		: ");
	scanf(" %[^\n]", (*mhs)[*jml - 1].ID.alamat);
	
	printf ("Jurusan		: ");
	scanf(" %[^\n]", (*mhs)[*jml - 1].data.jurusan);
	
	printf("Semester	: ");
	scanf(" %d", &(*mhs)[*jml - 1].data.semester);
	
	printf("IPK 		: ");
	scanf(" %f", &(*mhs)[*jml - 1].data.ipk);
	
	printf("Kesibukkan 	: ");
	scanf(" %[^\n]", (*mhs)[*jml - 1].kesibukkan);
	
	printf("------------------\n\n");
}

int main(){
	
	int option, jumlah = 0;
	
	Mahasiswa *mhs = (Mahasiswa *)malloc(sizeof(Mahasiswa));
	
	if (mhs == NULL){
		printf("error");
		return 1;
	}
	
	while(1){
		int cek = 0;
		
		printf("Database Mahasiswa\n");
		printf("------------------\n");
		printf("1. Tampilkan daftar Mahasiswa\n");
		printf("2. Tambah Mahasiswa\n");
		printf("3. Exit\n");
		printf("masukkan pilihan anda : ");
		scanf(" %d", &option);
		
		switch(option){
			case 1:
				tampilkan(mhs,jumlah);
				break;
			case 2:
				tambah(&mhs,&jumlah);
				break;
			case 3:
				cek = 1;
				break;
			default:
				printf("masukkan input yang sesuai!!");
		}
		
		if(cek != 0){
			break;
		}
			
	}
	
	printf("Program telah selesai, Terimakasih!!!");
	
	free(mhs);
	
	return 0;
}