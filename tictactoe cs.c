#include<stdio.h>
#define SIZE 3

void printt(char status[SIZE][SIZE]){
	for(int i = 0;i < SIZE;i++){
		for(int j = 0; j < SIZE; j++){
			printf("%c ",status[i][j]);
			if(j != SIZE-1){
				printf("|");
			}
		}
		printf("\n");
		if(i != SIZE-1){
			printf("----------\n");
		}
	}
}

void nol(char arr[SIZE][SIZE]){
	for(int i = 0;i < SIZE;i++){
		for(int j = 0; j < SIZE; j++){
			arr[i][j] = '-';
		}
	}
}

int main(){
	int kordinat[1][1];
	char papan[SIZE][SIZE];
	char status;
	nol(papan);

	int menang = 0;
	
	printt(papan);
	
	
	for(int i = 0; i < 9; i++){
		int m=0,n=0;
		int user = i%2;
		
		status = (user == 0) ? 'X':'O';
		
		printf("\nPemain %c, masukkan baris dan kolom\n",status);
		scanf("%d", &m);
		scanf("%d", &n);
		
		if(m >= SIZE || n>= SIZE){
			printf("Kordinat tidak tepat\n");
			i--;
			continue;
		}
		
		if(papan[m][n] == '-'){
			papan[m][n] = status;
		}else{
			printf("tempat kordinat sudah terisi\n");
			i--;
			continue;
		}
		printf("\n");
		printt(papan);
		
		if(papan[m][0] == papan[m][1] && papan[m][1] == papan[m][2]){
			menang = 1;
			break;
		}
		if(papan[0][n] == papan[1][n] && papan[1][n] == papan[2][n]){
			menang = 1;
			break;
		}
		if((m==n || m==2 || n==2) && papan[1][1] != '-'){
			if(papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2]){
				menang = 1;
				break;
			}
			if(papan[0][2] == papan[1][1] && papan[2][0] == papan[1][1]){
				menang = 1;
				break;
			}
		}	
	}
	if (menang == 1){
		printf("selamat kepada %c telah memenangkan permainan\n",status);
	}else{
		printf("permainan seri\n");
	}
	
	printf("game telah selesai");
}