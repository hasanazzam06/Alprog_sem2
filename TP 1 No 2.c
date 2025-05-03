#include <stdio.h>

int main(){
	int him_A[20], i = 1, j = 0, k = 0;
	
	while (i <= 50){
		if(i % 3 == 0 && i % 5 == 0){
			him_A[j]=i;
			j++;
			// j merupakan panjang array  
		}
		i++;
	}
	
	printf("A : ");
	while(k < j){
		if (k >= 5){
			printf("%d ", him_A[k]);
		}
		k++;
	}
	return 0;
}