#include <stdio.h>  
//#include <stdlib.h>

/********Prototypes*********/
int al_strlen(char*);
char* al_strcpy(char*, char*);
char* al_strcat(char*, char*);
void reverseString(char*);
void str_wreverse(char *);

int al_strlen(char* s){
    int len=0;
    while(s[len] != '\0'){
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

 void str_wreverse(char * str1){
    /*char ** newString = (char **)malloc(10*sizeof(char *));
    for(int i=0;i<10;i++)
        newString[i]=(char *)malloc(10*sizeof(char));*/
    char newString[10][10]; //we create a table of strings.
    int j=0, ctr=0, i=0;
    for(i=0;i<=(al_strlen(str1));i++) //we place each word in a case in the table.
    {
        if(str1[i]==' '||str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;
            j=0;
        }
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }
    }
    for(i=ctr;i<10;i++){
        for(j=0;j<10;j++) newString[i][j] = '\0';
    }
    for(i=0;i<10;i++) reverseString(newString[i]); //we then invert each element of the table.
    for(i=0;i<10;i++) printf("%s ",newString[i]); //and print out the result.
    return;
    //return newString;
}

int main(){
    char word[10];
    printf("Enter a string to get its size: ");
    gets(word);
    printf("=> the size of the previous string is : %d\n",al_strlen(word));
    printf("---------------------------\n");
    printf("Enter a string to reverse : ");
    gets(word);
    reverseString(word);
    printf("=> the inverted string is : %s\n",word);
    char copy[10];
    al_strcpy(copy,word);
    printf("=> the copy of the previous string is : %s\n",copy);
    printf("---------------------------\n");
    printf("Enter two strings to concatenate separated by enters : \n");
    char copy1[10], copy2[10];
    printf("1st string : "); gets(copy1); printf("2nd string : "); gets(copy2);
    al_strcat(copy1,copy2);
    printf("=> the concatenation of the previous two strings is : %s\n",copy1);
    printf("---------------------------\n");
    //next is what concerns inversing a string word by word.
    printf("Enter a string to inverse word by word : \n");
    char str1[50];
    gets(str1);
    char newString[10][10];
    str_wreverse(str1);
    printf("\n\nPress enter to quit the program...");
    gets(word); //this is just so the program waits for user input, the choice of using word is arbitrary.
    return 0;
}
