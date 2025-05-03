#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef  struct Node{
	char data[50];
	struct Node *next;
}Node;

void addNode(Node **head, char data[50]){
	Node *newNode = (Node *)malloc(sizeof(Node));
	
	if (newNode == NULL){
		printf("error");
		return;
	} 
	
	strcpy(newNode->data, data);
	newNode->next = *head;
	*head = newNode;
}

void deleteFirst(Node **head){
	Node *temp = *head;
	*head = (*head)->next;
	free(temp);
}

void deleteLast(Node **head){
	Node *temp = *head;
	
	while(temp->next->next != NULL){
		temp = temp->next; 
	}
	free(temp->next);
	temp->next = NULL;
}

void printNode(Node *head){
	Node *temp = head;
	
	while(temp != NULL){
		printf("%s \n", temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}

int menu() {
	int menu;
	printf("Menu: \n");
	printf("1. Add History\n");
	printf("2. Delete first history\n");
	printf("3. Delete last history\n");
	printf("4. Print all history\n");
	printf("5. exit\n");
	printf("masukkan pilihan : ");
	scanf("%d", &menu);
	printf("--------------------\n\n");

	return menu;
}

int main(){
	int option;
	
	Node *head = NULL;
	
	
	while(1){
		int cek = 0;
		char data[50];
		option = menu();
		
		switch(option){
			case 1:
				printf("masukkan History : ");
				scanf(" %[^\n]", data);
				printf("\n");
				
				addNode(&head,data);
				break;
			case 2:
				deleteFirst(&head);
				break;
			case 3:
				deleteLast(&head);
				break;
			case 4:
				printNode(head);
				break;
			case 5:
				cek = 1;
				break;
			default:
				printf("masukkan input yang sesuai!!");
		}
		if(cek == 1){
			printf("program telah selesai\n");
			break;
		}
	}
	return 0;
}