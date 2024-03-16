/*----------
DecToBinStack.c
Program to convert Decimal to Binary using Stack
18/01/2024
Rajesh C S
-----------*/

#include<stdio.h>
#define SIZE 60

typedef struct stacktype{
   int A[SIZE];
   int Top;
}STACK;   

STACK B;

//---------Prototype---------

void Push(int Num);
int Pop();
void InitStack();
int StackEmpty();

main()
{
  int Num, R, BinDigi, i, Dup;
  char Bin[30];
  
  printf("Program to convert Decimal to Binary using Stack\n\n");
  
  printf("Enter a Decimal Number: ");
  scanf("%d", &Num);
  
  Dup=Num;
  
  InitStack();
  
  while(Num!=0){
    R=Num%2;
    Push(R);
    Num=Num/2;
  }
  
  i=0;
  
  while(!StackEmpty()){
    BinDigi=Pop();
    if(BinDigi==1){
       Bin[i++]='1';
    }else if(BinDigi==0){
       Bin[i++]='0';
    }
  }          
  
  printf("Binary Equivalent of %d is %s", Dup, Bin);
    
}

//-----------------------------------

void Push(int Num)
{
  if(B.Top==SIZE-1){
    printf("\nStack Overflows\n\n");
    return;
  }else{
     B.Top++;
     B.A[B.Top]=Num;
  }   
}

int Pop()
{  
   int Num;
   
   if(B.Top==0){
     printf("\nStack Underflows\n\n");
     return 0;
   }else{
     Num=B.A[B.Top];
     B.Top--;
     return Num;
   }
}

void InitStack()
{
  B.Top=0;
}  

int StackEmpty()
{
  if(B.Top==0){
    return 1;
  }else{
    return 0;
  }    
}
