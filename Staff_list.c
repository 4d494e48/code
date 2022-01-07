#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

typedef struct{
    char ID[10];
    char name[25];
    char roll[25];
    int phone_number;
}staff;

typedef struct NODE{
    staff data;
    struct NODE* next;
}node;

staff inputStaffData(){
    staff nv;

    fflush(stdin);
    printf("\n\tID: ");
    gets(nv.ID);

    fflush(stdin);
    printf("\tName: ");
    gets(nv.name);

    fflush(stdin);
    printf("\tRoll: ");
    gets(nv.roll);

    printf("\tPhone Number: ");
    scanf("%d",&nv.phone_number);
    return nv;
}

node* first = NULL;

node* createNode(){
    node* pNode = (node*)malloc(sizeof(node));
    pNode->data=inputStaffData();
    pNode->next=NULL;
    return pNode;
}

void addNodeToFirst(){
    if(first == NULL){
        node* pNode = createNode();
        first = pNode;
    }
    else{
        node* pNode = createNode();
        pNode->next = first;
        first = pNode;
    }
}

void addNodeToLast(){
    if(first == NULL){
        addNodeToFirst();
    }
    else{
        node* pNode = createNode();
        node* lastNode;
        for(lastNode->next=first; lastNode->next!=NULL; lastNode=lastNode->next);
        lastNode->next = pNode;
    }
}

void createStaffList(){
    while(1){
        addNodeToLast();
        char c;
        printf("\nContinue? (Y/N): ");
        fflush(stdin);
        c = getch();
        if(c=='N' || c=='n'){
            break;
        }
    }
}

void displayList(){
    if(first == NULL){
        printf("Empty List");
        return;
    }
    else{
        printf("\t\tSTAFF LIST\n");
        printf("|%8s|%10s|%25s|%25s|%15s|\n","Ordinal","ID","NAME","ROLL","PHONE_NUMBER");
        node* i;
        int ord=0;
        for(ord++,i->next=first; i->next!=NULL; i=i->next){
            printf("|%7s|%10d|%25s|%25s|%11d|\n",ord,i->data.ID,i->data.name,i->data.roll,i->data.phone_number);
        }
    }
}

void menu(){
    printf("\t\tMENU");
    printf("\n\t1. Create Staff List");
    printf("\n\t2. Display Staff List");
    printf("\n\t3. Delete Staff");
    printf("\n\t4. Exit");
    printf("\n\tPlease chose: ");
}

int main(){
    int chon;
    int ID;
    while(1){
        menu();
        scanf("%d",&chon);
        system("cls");
        switch(chon){
            case 1:
                printf("\tCreate Staff List");
                createStaffList();
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("\n\t\tDelete Staff");
                printf("\n\tEnter the staff ID: ");
                scanf("%d",&ID);
                //delStaff(ID);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Pls enter 0-4");
                break;
        }
    printf("\nPress any key to continue");
    getch();
    system("cls");
    }
    return 0;
}