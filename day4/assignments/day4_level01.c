#include <stdio.h>  
//#include <stdlib.h>
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

/*char** reverseInPlace(char* str1){
    char ** newString = (char **)malloc(10*sizeof(char *));
    for(int i=0;i<10;i++)
        newString[i]=(char *)malloc(10*sizeof(char));
    int j=0, ctr=0;
    for(int i=0;i<=(al_strlen(str1));i++)
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
    for(int i=0;i<10;i++) reverseString(newString[i]);
    return newString;
}*/

int main(){
    char word[10];
    printf("Enter the string : ");
    gets(word);
    printf("the size of the previous string is : %d\n",al_strlen(word));
    reverseString(word);
    printf("the inverted string is : %s\n",word);
    char copy[10];
    al_strcpy(copy,word);
    printf("the copy of the previous string is : %s\n",copy);
    al_strcat(copy,copy);
    printf("the concatenation of the previous string is : %s\n",copy);
    //next is what concerns inversing a string word by word.
    //instead of using a function I had to do the thing in main because i cannot use malloc.
    //please do input one extra space before inputting your word for this to work properly.
    //this can be fixed by replacing while(str1[i] != '\0') with for(i=0;i<al_strlen(str1);i++)
    printf("Enter the string to inverse word by word : \n");
    char str1[100];
    char newString[10][10]; 
    int i=0,j,ctr;
    gets(str1);
    j=0; ctr=0;
    while(str1[i] != '\0')
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
        i++;
    }
    for(i=ctr;i<10;i++){
        for(j=0;j<10;j++) newString[i][j] = '\0';
    }
    for(i=0;i<10;i++) reverseString(newString[i]);
    /*char str1[100];
    gets(str1);
    char newString[10][10];
    printf("%s",reverseInPlace(str1)[1]);*/
    for(i=0;i<10;i++) printf("%s ",newString[i]);
    return 0;
}
