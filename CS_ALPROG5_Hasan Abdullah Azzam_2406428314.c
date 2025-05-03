#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;


typedef struct Queue{
	Node *front,*rear;
}Queue;

void enqueue(Queue *que, int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	
	 if(newNode == NULL){
	 	printf("error");
	 	return;
	 	
	 }else{
	 	
	 	newNode->data=data;
		newNode->next = NULL;
		
		if(que->front == NULL){
			que->front = que->rear = newNode;
		}else{
			que->rear->next =newNode;
			que->rear=newNode;
		}
	 }
}

void dequeue(Queue *que){	
	Node *temp;
	if(que->front == NULL){
		printf("Queue kasong");
	}else{
		temp = que->front;
		que->front = que->front->next; 
		free(temp);
	}
}

void printList(Queue *que){
	Node *temp = que->front;
	
	printf("Queue (dari first): ");
	if(temp == NULL){
		printf("Empty\n");
		return;
	}
	while(temp  != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
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
	int menu, data, n;
	
	Queue *list = (Queue*)malloc(sizeof(Queue));
	list->front =list->rear=NULL;
	
	if(list == NULL){
		printf("error");
		return 1;
	}
	
	scanf("%d",&n);
	
	for(int i = 0; i < n;i++){
		
		scanf("%d", &menu);
		
		if(menu == 1){

			scanf(" %d", &data);
			enqueue(list,data);
			
		}else if(menu == 2){
	
			dequeue(list);
		}
	}
	
	printList(list);
	
	freeList(list);
	return 0;	
}