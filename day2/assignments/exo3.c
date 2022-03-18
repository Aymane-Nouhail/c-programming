#include<stdio.h>

int main(){
	int   i =  8;
	int   j =  5;
	float x =  0.005f;
	float y = -0.01f;
	char  c = 'c';
	char  d = 'd';
	printf("%d\n",(3*i - 2*j)%(2*d - c));
	printf("%f\n",2*(((float)(i)/5) + (float)((4*(j-3))%(i + j - 2))));
}
