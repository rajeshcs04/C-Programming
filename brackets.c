/*......................................
program to check the brackets alingment
              Brackets.c
              Rajesh C S
              24/010/2024
......................................*/

#include<stdio.h>

#define SIZE 30

typedef struct stacktype{
   char A[SIZE];
   int Top;
}STACK;

STACK B;

//------------Prototype-------------
char Pop();
void Push(char Ch[]);
int StackEmpty();
void InitStack();

//-----------------------------------

main()
{
   char Brkt[30], Ch;
   int i=0;
   
   printf("Program to check whether the brackets in Expression are correctly assigned using stack\n\n");
   
   printf("Enter Brackets:\n");
   gets(Brkt);
   
   InitStack();
   
   while(Brkt[i]!='\0'){
      if(Brkt[i]=='('){
        Push(Brkt[i]);
      }else if(Brkt[i]==')'){
         Ch=Pop();
           if(Ch!='('){  
             printf("Improper Alignment of Brackets");
             exit(1);
           }
      }
      i++;
   }
   
   if(StackEmpty()){
      printf("Brackets are properly Aligned");
   }else{
      printf("Improper Alignment of Brackets");
   }   
}

void Push(char Ch[])
{
   if(B.Top==SIZE-1){
     printf("Stack Overflow\n");
     return;
   }else{
      B.Top++;
      B.A[B.Top]=Ch;
   }
}

char Pop()
{
  char Ch;
  
  if(B.Top==0){
    printf("Stack Underflow\n");
    return -1;
  }else{
    Ch=B.A[B.Top];
    B.Top--;
    return Ch ;
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
