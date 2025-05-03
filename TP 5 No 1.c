// Nama: Hasan Abdullah Azzam
// NMP : 2406428314
// TP 5 No 1
// deskripsi : program untuk mencari 3 nilai terbesar menggunakkan linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct{
	int top1;
	int top2;
	int top3;
}Top;

void add(Node **head, int data){
	Node *temp = (Node *)malloc(sizeof(Node));
	
	if(temp == NULL){
		printf("error");
		return;
	}
	
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

Top cekTop(Node *head){
	
	Node *temp = head;
	Top data;
	
	data.top1 = 0;
	data.top2 = 0;
	data.top3 = 0;
	
	while(temp != NULL){
		
		if(temp->data > data.top1){
			
			data.top3 = data.top2;
			data.top2 = data.top1;
			data.top1 = temp->data;
			
		}else if(temp->data > data.top2){
			
			data.top3 = data.top2;
			data.top2 = temp->data;
			
		}else if(temp->data > data.top3){
			data.top3 = temp->data;
		}
	                    
		temp = temp->next;
	}
	
	return data;
}

void printTop(Top data){
	printf("\n----------\n\n");
	printf("inilah 3 angka tertinggi :\n\n");
	printf("Top 1 = %d\n", data.top1);
	printf("Top 2 = %d\n", data.top2);
	printf("Top 3 = %d\n", data.top3);
	printf("\n--------------------\n\n");
}

void freeList(Node **head){
	Node *temp;
	
	while(*head != NULL){
		temp = *head;
		*head =  (*head)->next;
		free(temp);
	}
	
	*head = NULL;
}

int main(){
	int n, nilai;
	
	Top nilaiTop;
	
	Node *head = NULL;
	
	while(1){
		
		printf("masukkan jumlah angka (-1 = exit): ");
		scanf(" %d", &n);
		printf("\n----------\n");
		
		if(n == -1){
			printf("\nParogram Telah selesai, Terimkasih!!\n");
			freeList(&head);
			break;
		}
		
		for(int i=0; i < n; i++){
			printf("\nmasukkan angka ke-%d (x > 0): ", i+1);
			scanf(" %d", &nilai);
			add(&head, nilai);
		}
		
		nilaiTop = cekTop(head);
		
		printTop(nilaiTop);
		
		freeList(&head);
	}

	return 0;
}