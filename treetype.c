/*..............................
            treetype.c
            Rajesh C S
            28/03/2024
................................*/

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeType {
    int Num;
    struct TreeType *Right;
    struct TreeType *Left;
} TREENODE;

TREENODE *Root;

void InitTree();
void InOrder(TREENODE *Root);
void Input(int N);
void InsertTreeNode(int Num);

int main() 
{
    int Num, N;
    
    printf("Program to input Numbers into a binary Tree and using INORDER TRAVERSAL \n\n");
    printf("Enter the value for N: ");
    scanf("%d", &N);
    
    printf("Enter %d numbers: ", N);
    Input(N);
    InOrder(Root);
    printf("\n");
    
    return 0;
}

void InitTree() 
{
    Root = NULL;
}

void Input(int N) 
{
    int i, Num;
    for (i = 0; i < N; i++) {
        scanf("%d", &Num);
        InsertTreeNode(Num);
    }
}

void InsertTreeNode(int Num) 
{
    TREENODE *Prev, *Curr, *Node;
    
    Node = (TREENODE *)malloc(sizeof(TREENODE));
    Node->Num = Num;
    Node->Left = NULL;
    Node->Right = NULL;
    
    // Case 1: no tree present
    if (Root == NULL) {
        Root = Node;
        return;
    }
    
    // Case 2: Tree Exists, insert at an appropriate location
    Curr = Root;
    while (Curr) {
        Prev = Curr;
        if (Num < Curr->Num) {
            Curr = Curr->Left;
        } else {
            Curr = Curr->Right;
        }
    }
    
    if (Prev->Num < Num) {
        Prev->Right = Node;
    } else {
        Prev->Left = Node;
    }
}

void InOrder(TREENODE *Root) 
{
    if (Root) {
        InOrder(Root->Left);
        printf("%d\t", Root->Num); 
        InOrder(Root->Right);
    }
}
