#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct contact
{
    int phoneNumber;
    int id;
    char fullName[20];
};

typedef struct contact contact;

int main(){
    int userPick=0, order=0, i ; char c;
    contact book[8];
    printf("\t Choose one of the following by typing in the corresponding number: \n----------------------------------\n");
    printf("\t1. Add a contact.\n");
    printf("\t2. List contacts\n");
    printf("\t3. Quit.\n ----------------------------------\n\t");
    while(userPick != 3){
    scanf("%d",&userPick);
        if(userPick == 1){
            /*this part is just to be able to scan a string with spaces, couldn't get "gets" and "fgets" to work 
            so i used this section of code from https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
            printf("\tEnter the full name : ");
            scanf("%s",book[order].fullName);
            i = strlen(book[order].fullName);
            do
            {
                scanf("%c", &c);
                (book[order].fullName)[i++] = c;
            } while (c != '\n');
            (book[order].fullName)[i - 1] = 0;
            //////section of scanning the name ends here.
            printf("\t----------------------------------\n");
            printf("\tEnter the phone number : ");
            scanf("%d",&book[order].phoneNumber);
            printf("----------------------------------\n");
            book[order].id=order;
            order++;
        }
        if(userPick == 2){
            printf("\n----------------------------------All contacts : ----------------------------------\n");
            for(i=0;i<order;i++){
                printf("\tfull name : %s \n",book[i].fullName);
                printf("\tphone number : %d \n",book[i].phoneNumber);
                printf("\tid : %d\n",book[i].id);
                printf("\t----------------------------------\n");
            }
        }
    printf("\t Choose another number : ");
    }
    printf("\n\n********PROGRAM TERMINATED********");
    return 0;
}
