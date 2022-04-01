#include<stdio.h>
#include<stdlib.h>

struct intString
{
    int number;
    char* word;
};

typedef struct intString intString;


void switchh(intString* a, intString* b){
	int temp1 = a->number;
	a->number = b->number;
	b->number = temp1;
	char* temp2 = a->word;
	a->word = b->word;
	b->word = temp2;
	return;
}

int main(){
	
	intString a,b;
	a.number = 1;
	//a.word = (char*)malloc(5*sizeof(char));
	a.word = "abcde";
	b.number = 2;
	//b.word = (char*)malloc(5*sizeof(char));
	b.word = "fghij";
	printf("before : \n");
	printf("a = %d ; %s\n",a.number,a.word);
	printf("b = %d ; %s\n",b.number,b.word);
	switchh(&a,&b);
	printf("after : \n");
	printf("a = %d ; %s\n",a.number,a.word);
	printf("b = %d ; %s\n",b.number,b.word);
	//free(a.word);
	//free(b.word);
	return 0;
}


