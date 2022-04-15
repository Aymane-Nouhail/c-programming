#include<stdio.h>
#include<stdlib.h>
#include<string.h> //for strlen


int nbOccurence(char s,char *str){
    int occurence = 0; 
    for(int i=0;i<strlen(str);i++){
        if(str[i] == s) occurence++;
    }
    return occurence;
}
char** strsplit(char *str, char delim){
    //this function splits according to delim and doesn't include it in the split, it can be easily modified to include it
    int n = nbOccurence(delim,str)+1;
    char ** newString = (char **)malloc(n*sizeof(char *));
    for(int i=0;i<10;i++)
        newString[i]=(char *)malloc(10*sizeof(char)); //words are usually shorter than 10 in size so i'll settle with that 
    int j=0, ctr=0, i=0;
    for(i=0;i<=(strlen(str));i++) //we place each word in a case in the table.
    {
        if(str[i]==delim||str[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;
            j=0;
        }
        else
        {
            newString[ctr][j]=str[i];
            j++;
        }
    }
    return newString;
}

int main(){
    char word[20] = "This is a test";
    char s = ' ';
    char ** splitWord = strsplit(word,s);
    int n = nbOccurence(s,word)+1;
    printf("[");
    for(int i=0;i<n;i++){
        printf("%s, ",splitWord[i]);
    }
    printf("\b\b]");
    return 0;
}