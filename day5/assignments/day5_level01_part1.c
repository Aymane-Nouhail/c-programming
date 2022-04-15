#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void* al_memchr(void* array, int c, int n){
    char* array1 = (char*) array;
    for(int i=0;i<n;i++){
        if( array1[i] ==  c)
            return array + i;
    }
    return NULL;
}

void* al_memset(void *array, int c, int n){
    char* array1 = (char*) array;
    for(int i=0;i<n;i++){
        array1[i] = c;
    }
    return array1;
}

void* al_memcpy(void *dest, void * src, int n){
    char* dest1 = (char *) dest;
    char* src1 = (char *) src;
    for(int i=0;i<n;i++)
        dest1[i] = src1[i];
    return dest1;
}

void* al_memmove(void * dest, void * src,int n){
    char* dest1 = (char *) dest;
    char* src1 = (char *) src;
    char temp[n];
    for(int i=0;i<n;i++)
        temp[i] = src1[i];
    for(int i=0;i<n;i++)
        dest1[i] = temp[i];
    return dest1;
}


int main(){
    //this part concerns al_memchr
    printf("------------al_memchr part : ------------\n");
    char str[40] = "incredibly detailed.";
    char* result = al_memchr(str,'l',20);
    printf("%s\n",result); //as intended, it returns the adress of the element 'e'.
    int table[5] = {1,0,3,9,34}; 
    int* result1 = al_memchr(table,9,8*5); 
    printf("%d\n",*result1); //likewise, returns the adress of 3.
    //
    //this part concerns al_memset
    printf("\n------------al_memset part : ------------\n\n");
    char str1[50] = "Replacing the first few letters with N";
    printf("%s \n=> ",str1);
    al_memset(str1,'N',5);
    printf("%s\n",str1);
    //
    //this part concerns al_memcpy
    printf("\n------------al_memcpy part : ------------\n\n");
    char src[30] = "The quick brown fox";
    char dest[30] = "random stuff";
    al_memcpy(dest,src,3);
    printf("%s",dest);
    //
    //this part concerns al_memmove
    printf("\n------------al_memmove part : ------------\n\n");
    char src1[30] = "Here is a string";
    al_memmove(src1+3, src1, 3);
    printf("%s",src1);
    printf("%s",src1);
    //
    //this part concerns al_memmove
    printf("\n------------al_memmove part : ------------\n\n");
    return 0;
}