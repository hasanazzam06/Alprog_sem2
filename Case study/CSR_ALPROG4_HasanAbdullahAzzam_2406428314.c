#include<stdio.h>
#include<string.h>

typedef struct {
	char nama[50];
	char jabatan[50];
	float gaji;
	float imunitas;
	char status[50];
} karyawan;

void inputkaryawan(karyawan kry[], int jml) {
	char nama[50];
	char jabatan[50];
	float gaji;
	float imunitas;
	char status[50];

	for(int i=0; i < jml; i++) {
		printf("masukkan nama karyawan ke-%d : ", i+1);
		scanf(" %[^\n]s", nama);
		strcpy(kry[i].nama, nama);

		printf("masukkan jabatan karyawan ke-%d : ", i+1);
		scanf(" %[^\n]s", jabatan);
		strcpy(kry[i].jabatan, jabatan);

		printf("masukkan gaji karyawan ke-%d : ", i+1);
		scanf("%f", &gaji);
		kry[i].gaji = gaji;

		printf("masukkan imunitas karyawan ke-%d (1-100): ", i+1);
		scanf("%f", &imunitas);
		kry[i].imunitas = imunitas;
		
		printf("\n--------------------\n\n");


		if(imunitas <= 100 && imunitas > 90) {
			strcpy(kry[i].status,"Sehat");
		} else if(imunitas <= 90 && imunitas > 70) {
			strcpy(kry[i].status,"Batuk-Batuk");
		} else if(imunitas <= 70 && imunitas > 50) {
			strcpy(kry[i].status,"Tepar");
		} else if(imunitas <= 50 && imunitas > 20) {
			strcpy(kry[i].status,"Sekarat");
		} else {
			strcpy(kry[i].status,"Wassalam");
		}
	}

}

void printdata(karyawan kry[], int jml) {
    printf("Data Karyawan :\n\n");
    for (int i = 0; i < jml; i++) {
    	printf("ke-%d\n",i+1);
        printf("Nama: %s\n", kry[i].nama);
        printf("Jabatan: %s\n", kry[i].jabatan);
        printf("Gaji: %.2f\n", kry[i].gaji);
        printf("Imunitas: %.2f%%\n", kry[i].imunitas);
        printf("Status: %s\n", kry[i].status);
        printf("--------------------\n\n");
    }
}

void updateimun(karyawan kry[],int jml) {
	for(int i = 0; i < jml;i++){
		float temp = kry[i].imunitas;
		kry[i].imunitas = temp*(temp/100);
		
		float imunitas = kry[i].imunitas;
		
		if(imunitas <= 100 && imunitas > 90) {
			strcpy(kry[i].status,"Sehat");
		} else if(imunitas <= 90 && imunitas > 70) {
			strcpy(kry[i].status,"Batuk-Batuk");
		} else if(imunitas <= 70 && imunitas > 50) {
			strcpy(kry[i].status,"Tepar");
		} else if(imunitas <= 50 && imunitas > 20) {
			strcpy(kry[i].status,"Sekarat");
		} else {
			strcpy(kry[i].status,"Wassalam");
			kry[i].gaji = 0;
		}
	}

}

int menu() {
	int menu;
	printf("Menu: \n");
	printf("1. skip 1 minggu\n");
	printf("2. exit\n");
	printf("masukkan pilihan : ");
	scanf("%d", &menu);
	printf("--------------------\n\n");

	return menu;
}

int main() {
	int jml;
	printf("Masukkan jumlah karyawan : ");
	scanf("%d", &jml);
	printf("\n");

	karyawan kry[jml];

	inputkaryawan(kry, jml);
	printdata(kry,jml);

	int option;
	
	while(1){
		int cek = 0;
		
		option = menu();
		
		switch(option){
			case 1:
				updateimun(kry,jml);
				printdata(kry,jml);
				break;
			case 2:
				cek = 1;
				printf("program telah selesai terimkasih!!");
				break;
			default:
				printf("masukkan input yang sesuai!!");
		}
		
		if(cek != 0){
			break;
		}
	}
	
	return 0;
}