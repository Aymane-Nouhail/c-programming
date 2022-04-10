#include <stdio.h>  

int al_strlen(char* s){
    int len=0;
    while(*s != 0){
        s++;
        len++;
    }
    return len;
}

char* al_strcpy(char* s1, char* s2){
    int n = al_strlen(s2);
    for(int i=0;i<n;i++){
        s1[i] = s2[i];
    }
    s1[n] = '\0';
    return s1;
}

char* al_strcat(char* s1, char* s2){
    int n = al_strlen(s1);
    int m = al_strlen(s2);
    for(int i=0;i<m;i++){
        s1[n+i]=s2[i];
    }
    s1[n+m] = '\0';
    return s1;
}
void reverseString(char* s){
    int n=al_strlen(s); char temp;
    for(int i=0;i<n/2;i++){
        temp=s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;

    }
}

int main(){
    char word[10];
    printf("Enter the string : ");
    gets(word);
    reverseString(word);
    printf("the inverted string is : %s\n",word);
    char copy[10];
    al_strcpy(copy,word);
    printf("the copy of the previous string is : %s\n",copy);
    char concatenate[10]="hello";
    al_strcat(concatenate,concatenate);
    printf("the concatenation of the previous string is : %s\n",concatenate);
    return 0;
}