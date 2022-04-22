#include<stdio.h>
#include<stdlib.h>

int al_strlen(const char* s){ //to avoid using string.h
    int len=0;
    while(s[len] != '\0'){
        len++;
    }
    return len;
}

///////////////////////////////////////////////

int nbOccurence(char s,char *str){
    int occurence = 0; 
    for(int i=0;i<al_strlen(str);i++){
        if(str[i] == s && str[i+1] != s) occurence++;
    }
    return occurence;
}

char* cleanupString(char delim, char *str){

    int a = 0, n = strlen(str)-1;
    while(str[a] == delim) a++;
    while(str[n] == delim ) n--;
    str[n+1] = '\0';
	m = str + a;
    printf("[%s]\n %d \n",str);
    return str;
    
}

char** strsplit(char *str, char delim){
    //this function splits according to delim and doesn't include it in the split, it can be easily modified to include it
    int n = nbOccurence(delim,str)+1;
    char ** newString = (char **)malloc(n*sizeof(char *));
    for(int i=0;i<10;i++)
        newString[i]=(char *)malloc(10*sizeof(char)); //words are usually shorter than 10 in size so i'll settle with that 
    int j=0, m=0, i=0;
    for(i=0;i<=(al_strlen(str));i++) //we place each word in a case in the table.
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
    return newString;
}

int main(){
    char word[20] = "This  is   a test";
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
