#include<stdio.h>
#include<stdlib.h>
#include<string.h>

///////////////////////////////////////////////

int nbOccurence(char s,char *str){
    int occurence = 0; 
    for(int i=0;i<strlen(str);i++){
        if(str[i] == s && str[i+1] != s) occurence++;
    }
    return occurence;
}

void trim(char *s, char delim)
{
    char* newstart = s;
    while (*newstart == delim) {
        ++newstart;
    }
    memmove( s, newstart, strlen( newstart) + 1);
    int i = strlen(s) - 1;
    while (i >= 0)
    {
    if (s[i] == delim) i--;
    else break;
    }
    s[i + 1] = '\0';
}

char** strsplit(char *str, char delim){
    //this function splits according to delim and doesn't include it in the split, it can be easily modified to include it
    //char* str =  cleanupString(strr,delim);
    //cleanupString(str,delim);
    trim(str, delim);
    int n = nbOccurence(delim,str)+1;
    printf("the number of words in the table is %d.\n",n);
    char ** newString = (char **)malloc(n*sizeof(char *));
    for(int i=0;i<n;i++)
        newString[i]=(char *)malloc(30*sizeof(char)); //words are usually shorter than 30 in size so i'll settle with that 
    int j=0, m=0, i=0;
    for(i=0;i<=(strlen(str));i++) //we place each word in a case in the table.
    {
        if( (str[i]==delim && str [i+1] != delim )|| str[i]=='\0') //if we encounter delim, we end the m-th element of the table of strings.
        {
            newString[m][j]='\0'; //ending the element
            m++; //moving to the next word
            j=0; //reset the counter for characters
        }
        else //else we just fill the m-th element with the letters from our string
        {
            if (str[i] != delim){
            newString[m][j]=str[i];
            j++;
            }
        }
    }
    printf("[");
    for(i=0;i<n;i++)
        printf("%s, ",newString[i]);
    printf("\b\b]");
    return newString;
}

int main(){
    char word[100] = "   I'm testing this program// great so far    ";
    char s = ' ';
    char** result = strsplit(word, s);
    return 0;
}
