#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/******** Prototypes ***********/
int nbOccurence(char *, char);
void trim(char *, char);
int longestWord(char *, char);
char** strsplit(char *, char);


//this function counts the number of non-repeat occurences of a character in a string
//nbOccurence("Hello     I am       Aymane" , ' ') = 3
int nbOccurence(char *str, char delim){
    int n = 0; 
    for(int i=0; str[i]!='\0' ;i++){
        if(str[i] == delim && str[i+1] != delim) n++;
    }
    return n;
}


//removes spaces (or delim in general) from the start and end of a string.
void trim(char *str, char delim)
{
    //PART 1 : removing the spaces (delims) from the start.
    char* newstart = str;
    while (*newstart == delim)
        ++newstart;
    memmove(str, newstart, strlen( newstart) + 1);
    //PART 2 : removing the spaces (delims) from the end.
    int n = strlen(str) - 1;
    while (n >= 0){
        if (str[n] == delim) n--;
        else break;
    }
    str[n + 1] = '\0';
    return;
}


//returns the size of the longest word in a string
int longestWord(char* str, char delim){
    int n=strlen(str), biggest = 0, temp=0;
    for(int i=0;i<=n;i++){
        if(str[i] != delim && str[i]!='\0') temp++;
        else{
            if(temp>biggest){
                biggest = temp;
            }
            temp = 0;
        }
    }
    return biggest;
}


char** strsplit(char *str, char delim){
    trim(str, delim); //removing any unnecessary delims at the start or end
    int n = nbOccurence(str,delim) + 1; //the number of words in the table
    int len = longestWord(str, delim); //the size of the longest word in the string
    //printf("the size of the longest word in the string is %d\n", len);
    printf("the number of words in the table is %d.\n",n);
    char ** newString = (char **)malloc(n*sizeof(char *)); 
    for(int i=0;i<n;i++)
        newString[i]=(char *)malloc(len*sizeof(char));  
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
