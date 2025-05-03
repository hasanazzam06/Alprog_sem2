// Nama: Hasan Abdullah Azzam
// NMP : 2406428314
// Deskripsi : program untuk menghitung perkalian dari 2 buah matriks yang memiliki dimensi sama
// note: untuk mengatur ukuran matriks bisa dengan mengatur besar var size.
// tugas pendahuluan alprog 2 no 1

#include <stdio.h>

//fungsi input, berfungsi untuk memasukkan  ke dua matriks yang ingin di hitung.
void input(int size, int arr[2][size][size]){
	for(int k = 0; k<2;k++){
		printf("\nMatriks ke-%d\n",k+1);
		printf("Masukkan elemen matrikx %d X %d\n", size,size);
		printf("-------------------------------\n");
		for(int i = 0; i < size;i++){
			for(int j = 0; j < size; j++){
				scanf("%d", &arr[k][i][j]);
			}
		}	
	}
}
// fungsi perkalian,untuk menghitung hasil perkalian matriks
void perkalian(int size, int arr[2][size][size]){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size;j++){
			arr[2][i][j] = 0;
			for(int k = 0; k < size;k++){
				arr[2][i][j] += arr[0][i][k]*arr[1][k][j];
			}
		}
	}
}

// fungsi untuk menampilkan matriks
void printmatriks(int size, int arr[2][size][size]){
	for(int i = 0; i < size;i++){
		for(int j = 0; j < size; j++){
			printf("%d ",arr[2][i][j]);
		}
		printf("\n");
	}
}

int  main(){
	int size = 2;// var untuk menentukan ukuran matriks
	int arr[2][size][size];// var matriks, 3 dimensi
	// diambil indeks = 2 untuk membuat 3 matriks, 2 matriks awal untuk perhitungan dan 1 matrik hasil
	int quit = 0;
	int condition = 1;
	
	printf("kalkulator perkalian matriks\n");
	
	while(condition == 1){
		printf("\n============================\n");
		
		input(size, arr);
		
		perkalian(size, arr);
		
		printf("\nberikut hasil perkalian matriks %d X %d\n",size,size);
		printf("-------------------------------\n");

		printmatriks(size,arr);
		
		printf("-------------------------------\n");
		printf("\nApakah ingin melanjutkan perhitungan (1 = Ya, 0 = Tidak):  ");
        scanf("%d", &condition);
	}
	
	return 0;
}