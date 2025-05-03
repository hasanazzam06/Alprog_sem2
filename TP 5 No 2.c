// Nama: Hasan Abdullah Azzam
// NMP : 2406428314
// TP 5 No 2
// deskripsi : program untuk mencari hasil dari function F=(MIN  + MAX)/2 menggunakkan queue
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef  struct Queue{
	Node *front, *rear;
}Queue;

void enqueue(Queue *que, int data){
	Node *temp = (Node *)malloc(sizeof(Node));
	
	if(temp == NULL){
		printf("error");
		return;
	}
	
	temp->data = data;
	temp->next = NULL;
	
	if(que->rear == NULL){
		que->front = que->rear = temp;
	}else{
		que->rear->next = temp;
		que->rear = temp;
	}
}

int higher(Queue *que){
	
	Node *sign = que->front;
	int max = sign->data;
	
	while(sign != NULL){
		
		if(max < sign->data){
			max = sign->data;
		}
		
		sign = sign->next;
		
	}
	
	return max;
}

int lower(Queue *que){

	Node *sign = que->front;
	int min = sign->data;
	
	while(sign != NULL){
		
		if(min > sign->data){
			min = sign->data;
		}
		
		sign = sign->next;
		
	}
	
	return min;
}

float rumus(int min, int max){
	float hasil = (min + max) / 2.00;
	
	return hasil;
}

void freeList(Queue *que){
	Node *temp;
	
	while(que->front != NULL){
		temp = que->front;
		que->front = que->front->next;
		free(temp);
	}
	
}


int main(){
	
	int n, nilai,max,min;
	float hasil;
	
	Queue *angka = (Queue *)malloc(sizeof(Queue));
	
	if(angka == NULL){
		printf("error");
		return 1;
	}
	
	angka->front = angka->rear = NULL;
	
	
	while(1){
		
		printf("masukkan jumlah angka (-1 = exit): ");
		scanf(" %d", &n);
		printf("\n----------\n");
		
		if(n == -1){
			printf("\nParogram Telah selesai, Terimkasih!!\n");
			break;
		}else if(n <= 0){
			printf("jumlah angka tidak boleh kurang dari sama dengan 0!!\n");
			continue;
		}
		
		for(int i=0; i < n; i++){
			printf("\nmasukkan angka ke-%d (x > 0): ", i+1);
			scanf(" %d", &nilai);
			enqueue(angka, nilai);
		}
		
		max = higher(angka);
		min = lower(angka);
		
		hasil = rumus(min, max);
		
		printf("\nhasil akhir dari rumus : %.2f \n",hasil);
		printf("\n--------------------\n\n");
		
		freeList(angka);
		angka->front = angka->rear = NULL;
		
	}
	
	free(angka);

	return 0;
}



