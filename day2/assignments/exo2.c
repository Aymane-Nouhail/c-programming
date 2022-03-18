#include<stdio.h>

int main(){
	int a, b, temp;
	printf("Entrer a et b : ");
	scanf("%d%d",&a,&b);
	printf("Before a = %d and b = %d\n",a,b);
	temp = a; 
	a = b; 
	b = temp;
	printf("After a = %d and b = %d\n",a,b); 
}
