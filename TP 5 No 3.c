// Nama: Hasan Abdullah Azzam
// NMP : 2406428314
// TP 5 No 3
// deskripsi : program untuk mengecek apakah suatu deret yng diberikkan WEll balance atau tidak, sesuai kriteria yang diberikkan dan menggunakkan stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int size;
	int top;
	char *s;
}Stack;

void push(Stack *stack, char data){
	if(stack->top == stack->size - 1){
		printf("stack penuh!!\n");
	}else{
		stack->top++;
		stack->s[stack->top] = data;
	}
}

int balance(char a , char b){
	if(a == '1' && b == '9') return 1;
	if(a == '2' && b == '8') return 1;
	if(a == '3' && b == '7') return 1;
	if(a == '4' && b == '6') return 1;
	if(a == '5' && b == '5') return 1;
	return 0;
}

int main(){
	char input[50];
	int balanced;
	
	Stack *deret = (Stack *)malloc(sizeof(Stack));
	
	if(deret == NULL){
		printf("error");
		return 1;
	}
	
	while(1){
		
		printf("\nmasukkan deret angka (1-9)(-1 = exit): ");
		scanf("%s",input);
		
		if(strcmp(input,"-1") == 0){
			printf("\nParogram Telah selesai, Terimkasih!!\n");
			break;
		}
		
		int len = strlen(input);
		
		deret->size = len;
		deret->top = -1;
		deret->s = (char * )malloc(len * sizeof(char));
		
		if(deret->s == NULL){
			printf("error");
			continue;
		}
		
		char temp = '\0';
		
		for(int i = 0; i < len; i++){
			
			if( input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'){
				push(deret,input[i]);
			}else if(input[i] == '5' && deret->s[deret->top] != '5'){
				push(deret,input[i]);
			}else{
				if(deret->top == -1){
					temp = input[i];
					printf("Deret tidak well-balanced karena ada angka %c diakhir\n",input[i]);
					break;
				}else{
					if(balance(deret->s[deret->top],input[i]) == 1){
						deret->top--;
					}else{
						temp = input[i];
						break;
					}
				}
			}
			temp = input[i];
//			printf(" %c--%c\n", temp, input[i]);
		}
		
		if(deret->top == -1){
			
			printf("Output : True\n");
			printf("deret well-balanced\n");
			
		}else if(deret->top == 0){
			
			int x = 10 - (deret->s[deret->top] - '0'); 
			printf("Output : Fasle\n");
			printf("Deret tidak well-balanced karena tidak diakhiri %d untuk menutup %c",x,deret->s[deret->top]);
			
		}else if(deret->top == len-1){
			
			printf("Output : Fasle\n");	
			printf("Deret tidak well-balanced karena tidak ada yang menutup setiap angka");
			
		}else{
			
			int x = 10 - (deret->s[deret->top] -'0');
			printf("Output : Fasle\n");
			printf("Deret tidak well-balanced karena tidak diakhiri %d sebelum %c", x, temp);
			
		}

		printf("\n----------\n");
		free(deret->s);
	}
	
	free(deret);
	return 0;
}