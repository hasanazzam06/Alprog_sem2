// Nama: Hasan Abdullah Azzam
// NMP : 2406428314
// Deskripsi : program enkripsi string dengan men-shifthing-nya dengan hruruf selanjutnya.
// tugas pendahuluan alprog 2 no 1

#include <stdio.h>
#include <string.h>

int main(){
	// var stirng yang sudah ditentukkan.
	char hero[5][10] = {"gusion", "fanny", "yin", "johnson", "nana"};
	
	int len;
	
	//pengulangan untuk setiap string
	for( int i = 0; i < 5;i++){
		// len sebagai variabel yang menyimpan panjang string dari fungsi strlen yang ada di string.h
		// diperbarui di setiap pengulangan.
		len = strlen(hero[i]);
		printf("hero %d : ",i+1);
		// pengulangan untuk setiap char di satu string
		for (int j = 0; j < len;j++){
			//shifting tiap char dengan menggantikanya dengan huruf selanjutnya
			// char merujuk pada ASCII, sehingga hany perlu (+1)
			hero[i][j]=hero[i][j]+1;
			printf("%c",hero[i][j]);
		}
		printf("\n");
	}
	return 0;
}