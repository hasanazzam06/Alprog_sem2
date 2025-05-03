#include <math.h>
#include <stdio.h>

#define condition 0

int main(){	

	int  menu, num1, num2, hasil;
	
	while(condition == 0){
		printf("==========MENU==========\n");
		printf("1. Tambah\n");
		printf("2. Kurang\n");
		printf("3. Kali\n");
		printf("4. Bagi\n");
		printf("5. Pangkat\n");
		printf("6. Quit\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d", &menu);
		printf("------------------------\n");
			
		if(menu > 6 || menu < 1){
			printf("\nMohon Masukkan Angka yang Benar!!\nSilahkan Ulangi\n\n");
			continue;
		}	
		
		if(menu == 6){
			printf("\nProgram shape calculator telah selesai!! terimakasih\n");
			break;
		}
		
		printf("\nmasukkan angka ke-1 : ");
		scanf("%d", &num1);
		printf("masukkan angka ke-2 : ");
		scanf("%d", &num2);
		
	
		switch(menu){
			case 1:	
				hasil= num1 + num2;
				break;
			case 2:
				hasil = num1 - num2;
				break;
			case 3:
				hasil = num1 * num2;
				break;
			case 4:	
				hasil = (int) num1 / num2;
				break;
			case 5:
				hasil = pow(num1,num2);
				break;
		}	
		printf("\n========================\n");
		printf("hasil perhitangan adalah : %d\n",hasil);
		printf("berikut adalah bentuk huruf C dengan panjang %d",hasil);
		printf("\n========================\n\n");
		
		printf(" ");
		for(int j = 0;j<hasil;j++){
					printf("*");
		}
		printf("\n");
		
		for(int i = 0;i  < hasil; i++){
			printf("*\n");
		}
		printf(" ");
		for(int k = 0;k<hasil;k++){
			printf("*");
		}
		printf("\n\n");
	}	 
	
	
	return 0;
}