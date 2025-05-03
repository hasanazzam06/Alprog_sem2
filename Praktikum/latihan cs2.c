
#include <stdio.h>
#include <math.h>

#define SIZE 3

void transpose(float trp[SIZE][SIZE], float arr[SIZE][SIZE]){
	for(int i = 0;i < SIZE; i++){
		for(int j = 0;j < SIZE; j++){
			trp[i][j] = arr[j][i];
		}
	}
}

int det2(float arr[2][2]){
	
	int det = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	return det;
}

int det3(float matrix[3][3]){
	int det;
    
    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    return det;	
}

void cofactor( float addj[SIZE][SIZE], float arr[SIZE][SIZE]){
	float temp[2][2];
	for(int i = 0;i<SIZE;i++){
		for(int j = 0; j<SIZE;j++){
			//batas minor
			int m=0,n=0;
			for(int k = 0; k<SIZE;k++){
				if(k != i){
					for(int l=0; l < SIZE; l++){
						if(l != j){
							temp[m][n] = arr[k][l];
							n++;
						//	printf("[%.2f]",temp[m][n]);
						}
					}
					m++;
					n = 0;
					
				}
			}
			float s = pow(-1,i+j);
			addj[i][j] = s*det2(temp);
//			printf("(%.1f)",s*det2(temp));
			//printf("[%.1f]",addj[i][j]);
		}
		//printf("\n");
	}
}

void invers(int det, float adj[SIZE][SIZE], float inv[SIZE][SIZE]){
	for(int i = 0; i< SIZE;i++){
		for(int j = 0; j < SIZE; j++){
			inv[i][j] = adj[i][j]/det;
		}
	}
}

void printmatriks(float arr[SIZE][SIZE]){
	for(int i = 0; i < SIZE;i++){
		for(int j = 0; j < SIZE; j++){
			printf("%.1f ", arr[i][j]);
		}
		printf("\n");
	}
}

int  main(){
	int size = 3;
	float B[3][3] = {
        {2, 1, 1},
        {3, 2, 1},
        {1, 1, 2}
    };
    
    float inv[SIZE][SIZE], addj[SIZE][SIZE], coef[SIZE][SIZE];	  
	
	int det = det3(B);
	          
    cofactor(coef,B);
    
    transpose(addj,coef);
    
    invers(det,addj,inv);
    
    printmatriks(inv);
	return 0;
}