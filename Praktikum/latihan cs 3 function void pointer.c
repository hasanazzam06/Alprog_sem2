#include <stdio.h>
#include <math.h>

void function1(int *x, int *y, int*z,int *hasil) {
	double temp = (pow(*x,3)+8*pow(*y,2)-pow(*z,2)+10);
	*hasil = (int)temp;
}

void function2(int *x, int *y, int*z,int *hasil) {
	double temp = (*x) * (*y) * (*z)/2;
	*hasil = (int)round(temp);
}

void function3(int *x, int *y, int*z,int *hasil) {
	double temp = sqrt(pow(*x,2)+pow(*y,2)+pow(*z,2));
	*hasil = (int)temp;
}

int main() {
	int x,y,z;

	int hasil1,hasil2,hasil3;
	printf("masukkan X : ");
	scanf("%d", &x);
	printf("masukkan Y : ");
	scanf("%d", &y);
	printf("masukkan Z : ");
	scanf("%d", &z);

	function1(&x,&y,&z,&hasil1);
	function2(&x,&y,&z,&hasil2);
	function3(&x,&y,&z,&hasil3);
	
	printf("%d %d %d",hasil1,hasil2,hasil3);

	return 0;
}