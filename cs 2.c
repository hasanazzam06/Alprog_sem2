// Nama		 : Hasan Abdullah Azzam
// NPM		 : 2406428314
// Note		 : Case Study 2 Alprog
// Deskirpsi : program operasi matriks yang menghitung determinan dan trasnpose dari matriks 3 x 3 

#include <stdio.h>

#define DIM 3

int det(float arr[DIM][DIM]){
	int det = (
		arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])
		- arr[0][1]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0])
		+ arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][1])
	);
	return det;
}

void transpose(float arr[DIM][DIM], float trp[DIM][DIM]){
	for(int i = 0; i < DIM;i++){
		for(int j = 0; j<DIM;j++){
			trp[i][j] = arr[j][i];
		}
	}
}

void print(float arr[DIM][DIM]){
	for(int i = 0; i < DIM; i++){
		for(int j = 0; j < DIM; j++){
			printf("%.1f ", arr[i][j]);
		}
		printf("\n");
	}
}

void hasil(float arr[DIM][DIM],float nilai[DIM][DIM]){
	for(int i = 0; i < DIM; i++){
		for(int j = 0; j < DIM; j++){
			nilai[i][j] = arr[i][j]/det(arr);
		}
	}
}
 
int main(){
	float A[3][3] = {
    {2, 1, 1},
    {3, 2, 1},
    {1, 1, 2}
	};
	float trp[DIM][DIM], nilai[DIM][DIM];
	
	printf("Matriks awal A : \n");
	print(A);
	printf("-----------\n");
	
	printf("Hasil transpose  dari A: \n");
	transpose(A, trp);
	print(trp);	
	printf("-----------\n");
	
	printf("Nilai determinan dari matriks A : \n");
	printf("%d",det(trp));//det A dan trp nya sama
	printf("\n-----------\n");
	
	printf("hasil dari perhitungan rumus : \n");
	hasil(trp, nilai);
	print(nilai);
	printf("-----------\n");
	printf("program telah selesai");
	
	return 0;
}