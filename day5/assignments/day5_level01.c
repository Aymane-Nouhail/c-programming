#include<stdio.h>
#include<stdlib.h>

void* al_memchr(void* array, int c, int n){
    char* array1=(char*) array;
    for(int i=0;i<n;i++){
        if( array1[i] ==  c)
            return array + i;
    }
    return NULL;
}

int main(){
    char str[10] = "hello";
    char* result = al_memchr(str,'e',5);
    printf("%s\n",result); //as intended, it returns the adress of the element 'e'.
    int table[5] = {1,0,3,9,34}; 
    int* result1 = al_memchr(table,9,8*5); 
    printf("%d",*result1); //likewise, returns the adress of 3.
    return 0;
}