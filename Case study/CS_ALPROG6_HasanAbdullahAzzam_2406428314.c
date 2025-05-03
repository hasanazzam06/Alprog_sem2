#include<stdio.h>
#include<string.h>

typedef struct {
    char nama[100];
    char nomorTelepon[15];
} Kontak;

int search(Kontak data[], int n,char key[],int hasil[]){
	int lenghKey = strlen(key);
	int id = 0;
	
	//tiap kontak
	for(int i = 0;i < n;i++){
		
		int lenghName = strlen(data[i].nama);
		int lenghKontak = strlen(data[i].nomorTelepon);
		
		//cek name
		for(int j = 0; j < lenghName; j++){
			int cek = 0;
			
			if((data[i].nama)[j] == key[0]){
				int cek = 0;
				
				for(int k = 1; k < lenghKey;k++){
					cek = 1;
					
					if((data[i].nama)[j + k] != key[k]){
						cek = -1;
						break;
					}		
				}
				
				if(cek == 1){
					hasil[id] = i;
					id++;
					break;
				}
				
			}
		}
		
		//cek kontak
		for(int j = 0; j < lenghKontak; j++){
			int cek = 0;
			
			if((data[i].nomorTelepon)[j] == key[0]){
				int cek = 0;
				
				for(int k = 1; k < lenghKey;k++){
					cek = 1;
					
					if((data[i].nomorTelepon)[j + k] != key[k]){
						cek = -1;
						break;
					}		
				}
				
				if(cek == 1){
					hasil[id] = i;
					id++;
					break;
				}
				
			}
		}
	}
	
	return id;
}

int main(){
	int n;
	printf("masuukkan jumlah kontak (n <= 10): ");
	scanf("%d",&n);
	printf("\n");
	
	if(n > 10){
		printf("jumlah data terlalu besar!!!!");
		return 1;
	}
	
	Kontak data[n];
	
	for(int i = 0;i < n;i++){
		printf("masukkan nama orang ke-%d: ",i+1);
		scanf(" %[^\n]", data[i].nama);
		printf("masukkan nomor telpon orang ke-%d:",i+1);
		scanf(" %[^\n]", data[i].nomorTelepon);
		printf("\n");
	}
	
	char target[50];
	printf("masukkan kata kunci : ");
	scanf(" %[^\n]", target);
	
	int hasil[n];
	
	int jumlah = search(data,n, target, hasil);
	
	printf("====================\n");
	
	if(jumlah == 0){
		printf("Tidak ditemukkan data dengan kata kunci: %s\n",target);
	}else{
		printf("\nKontak yang ditemukan : \n\n");
		for(int j = 0; j < jumlah ; j++){
			printf("%d. Nama: %s, No.Tlp: %s\n", j+1 , data[hasil[j]].nama, data[hasil[j]].nomorTelepon);			
		}
	}

	return 0;
}