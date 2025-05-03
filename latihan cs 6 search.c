#include<stdio.h>
#include<string.h>

 int hitungChar(char *str, int sizeStr, char target){
 	int n = 0;
 	
 	for(int i = 0; i< sizeStr; i++){
 		if(str[i] == target){
 			n++;
		}
	 }
	 
 	return n;
 }
 
 int main(){
 	char name[] = "hasanhhh";
 	char target = 'h';
 	
 	int hasil = hitungChar(name,8,target);
 	printf("%d",hasil);
 	
 	return 0;
 }