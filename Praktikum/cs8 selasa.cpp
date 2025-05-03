#include "header_CS8_selasa.h"

using namespace std;

int main() {
	
	Library library;
	
	while(1){
		int option = menu();
		int cek = 0;
		switch(option){
			case 1:
				library.addBook();
				break;
			case 2:
				library.showbooks();
				break;
			case 3:
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