#include<stdio.h>
#include<stdlib.h>

struct contact
{
    int phoneNumber;
    int id;
    char fullName[10];
};

typedef struct contact contact;

int main(){
    int userPick=0, order=0;
    contact book[8];
    printf("\t Choose one of the following by typing in the corresponding number: \n----------------------------------\n");
    printf("\t1. Add a contact.\n");
    printf("\t2. List contacts\n");
    printf("\t3. Quit.\n ----------------------------------\n\t");
    while(userPick != 3){
    scanf("%d",&userPick);
        if(userPick == 1){
            char* temp;
            printf("\tEnter the full name : ");
            scanf("%s",book[order].fullName);
            //fgets(book[order].fullName, 10, stdin);
            printf("\t----------------------------------\n");
            printf("\tEnter the phone number : ");
            scanf("%d",&book[order].phoneNumber);
            printf("----------------------------------\n");
            book[order].id=order;;
            order++;
        }
        if(userPick == 2){
            printf("\n----------------------------------All contacts : ----------------------------------\n");
            for(int i=0;i<order;i++){
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
