#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// Tulis function-function berkaitan sama stack di sini

typedef struct Stack{
	int top;
	int *s;
}Stack;

void push(Stack *stack, int data){
	stack->top++;
	stack->s[stack->top] = data;
}

int peek(Stack *stack){
	int data = stack->s[stack->top];
	return data;
}

void pop(Stack *stack){
	if (stack->top == -1) {
	  	
        printf("Stack Underflow\n");
        
    } else {
    	
        stack->top--;
    }
}


int main()
{
    FILE *f = fopen("complex.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Inisialisasi stack di sini
    
    Stack *data = (Stack*)malloc(sizeof(Stack));
    if(data == NULL){
    	printf("error");
    	return 1;
	}
	
    data->top=-1;
    data->s = (int*)malloc(sizeof(int));
    

    int start, end;
    char tempstr[100];
    char str[500][100];

    scanf("%d %d", &start, &end);
    int index;
    while (fscanf(f, "%d\t%99[^\n]", &index, tempstr) == 2)
    {
        strcpy(str[index], tempstr);
    }

    fclose(f);

    // Lengkap logic di sini sesuai deskripsi soal
//    printString(start,end,str);
	
	int i = start;
	
	for(int i = start;i <= end;i++){
		if(i == end && data->top  != -1){
			printf("%s ",str[i]);
			start = peek(data);
			pop(data);
			end = peek(data);
			pop(data);
			
			i = start - 1;
			continue;
		}
		if((str[i][0] == 'x' || str[i][0] == 'y') && str[i][1] == ' '){
    		int j = 0;
    		int newStart,newEnd;
    		
    		if(str[i][0] == 'x'){
    			sscanf(str[i],"x %d %d", &newStart, &newEnd); 
			}else{
				sscanf(str[i],"y %d %d", &newEnd, &newStart); 
			}
			
			push(data,end);
			push(data,i+1);
			start = newStart;
			end = newEnd;
			i = start - 1;
			continue;
		}else{
			printf("%s ",str[i]);
		}
	}
	
	free(data->s);
	free(data);
  

    return 0;
}
