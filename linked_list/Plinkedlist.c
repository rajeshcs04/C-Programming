/*---------------
Program: Linked List
14/2/24
Rajesh C S
-----------------*/

#include <stdio.h>
#include <stdlib.h>

//---------Linked List Declaration----------

typedef struct ListType{
    int Num;
    struct ListType *Next;
}LISTNODE;
LISTNODE *Head;

//---------Prototypes-----------

void InitList();
void InsertListNode(int Num);
void DisplayList(LISTNODE *Head);

int main()
{
    int i,Num,N;
    InitList();
    printf("Program to input some numbers into linked list\n\n");
    printf("Insert 5 numbers:");
    for(i=1;i<=5;i++){
        scanf("%d",&Num);
        InsertListNode(Num);
    }
    DisplayList(Head);
    return 0;
}

//---------------------------------

void InitList()
{
    Head=NULL;
}

//-----------------------------

void InsertListNode(int Num)

{
    LISTNODE *Prev,*Curr,*Node;
    //--------Create a new node from the data item Num
    Node = (LISTNODE*)malloc(sizeof(LISTNODE));
    Node->Num=Num;
    Node->Next=NULL;
    //---------Case 1-------- If the list is empty, therefore the incoming node will be initialized
    //--------at the head
    if(Head==NULL){
        Head=Node;
        return;
    }
    //---------Case 2---------- Inserting node at end of the list after traversing
    Curr=Head;
    while(Curr!=NULL){
        Prev=Curr;
        Curr=Curr->Next;
    }
    Prev->Next=Node;
}

//--------------------------------

void DisplayList(LISTNODE *Head)
{
    LISTNODE *Curr;
    Curr=Head;
    while(Curr){
        printf("%d ",Curr->Num);
        Curr=Curr->Next;
    }
}
