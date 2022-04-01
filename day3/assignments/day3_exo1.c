#include<stdio.h>
#include<stdlib.h>

struct complex
{
    float real;
    float imaginary;
};
typedef struct complex complex;


void printComplex(complex a){
	printf("%f + %f i\n",a.real,a.imaginary);
	return;
}
complex add(complex a, complex b){
	complex c;
	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;
	return c;
}

complex sub(complex a,complex b){
	complex c;
	c.real = a.real - b.real;
	c.imaginary = a.imaginary - b.imaginary;
	return c;
}

complex mul(complex a, complex b){
	complex c;
	c.real = a.real*b.real - a.imaginary*b.imaginary;
	c.imaginary = a.imaginary*b.real + a.real*b.imaginary;
	return c;
}

complex div1(complex a, complex b){
	if(b.real == 0 && b.imaginary == 0){
		printf("division by zero\n");
		complex c = {0,0};
		return c;
	}
	complex c;
	c.real = (a.real*b.real + a.imaginary*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
	c.imaginary = (a.imaginary*b.real-a.real*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
	return c;
}
int main(){
	complex a = {1,2};
	complex b = {2,3};
	complex c = add(a,b);
	complex d = sub(a,b);
	complex e = mul(a,b);
	complex f = div1(a,b);
	printf("a = "); printComplex(a);
	printf("b = "); printComplex(b);
	printf("a + b = ") ; printComplex(c);
	printf("a - b = ") ; printComplex(d);
	printf("a * b = ") ; printComplex(e);
	printf("a / b = ") ; printComplex(f);
	return 0; 
}
