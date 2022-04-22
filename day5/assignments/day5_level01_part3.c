#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//this function counts the number of non-repeat occurences of a character in a string
//nbOccurence("Hello     I am       Aymane" , ' ') = 3
int nbOccurence(char *str, char delim){
    int occurence = 0; 
    for(int i=0;i<strlen(str);i++){
        if(str[i] == delim && str[i+1] != delim) occurence++;
    }
    return occurence;
}
//removes spaces (or delim in general) from the start and end of a string.
void trim(char *str, char delim)
{
    char* newstart = str;
    while (*newstart == delim) {
        ++newstart;
    }
    memmove( str, newstart, strlen( newstart) + 1);
    int i = strlen(str) - 1;
    while (i >= 0)
    {
    if (str[i] == delim) i--;
    else break;
    }
    str[i + 1] = '\0';
    return;
}

char** strsplit(char *str, char delim){
    trim(str, delim); //removing any unnecessary delims at the start or end
    int n = nbOccurence(str,delim) + 1; //the number of words in the table
    printf("the number of words in the table is %d.\n",n);
    char ** newString = (char **)malloc(n*sizeof(char *)); 
    for(int i=0;i<n;i++)
        newString[i]=(char *)malloc(30*sizeof(char)); //words are usually shorter than 30 in size so i'll settle with that 
        //TODO : function that returns maximum length of a word in a string so i can ditch the arbitrary big size in favor of this.
    int j=0, m=0, i=0;
    for(i=0;i<=(strlen(str));i++) //we place each word in a case in the table.
    {
        if( (str[i]==delim && str [i+1] != delim )|| str[i]=='\0') //if we encounter delim, we end the m-th element of the table of strings.
        {
            newString[m][j] = '\0'; //ending the element
            m++; //moving to the next word
            j = 0; //reset the counter for characters
        }
        else //else we just fill the m-th element with the letters from our string
        {
            if (str[i] != delim){
            newString[m][j] = str[i];
            j++;
            }
        }
    }
    //printing the result.
    printf("[");
    for(i=0;i<n;i++)
        printf("%s|",newString[i]);
    printf("\b]");
    return newString;
}

int main(){
    char word[100] = "   I'm testing     this program It's   great so far.    ";
    char s = ' ';
    char** result = strsplit(word, s);
    return 0;
}
