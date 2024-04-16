/*---------------------------------------------------------------

Palindrome.C
Program to find a factorial of a number
Rajesh C S
22/01/2023

-----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct StackType{
char A[SIZE];
int Top;
}STACK;

STACK S;

//_______________________________________________________PROTOTYPES

void Push(int Num);
int Pop();
void InitStack();

//_______________________________________________________Main

main()
{
int Num,i,N;
double Fact;

InitStack();

printf("Program to find the factorial using stack\n");

printf("Enter a number of your choice: ");
scanf("%d",&N);

i=1;
Push(1);
while(i<=N){
Num=Pop();
Push(Num*i);
i++;
}
Fact=Pop();
printf("Factorial of %d:  %0.0lf",N,Fact);
}

//____________________________________________________________________int()

void InitStack()
{
S.Top=0;
}

//__________________________________________________Push

void Push(int Num)
{
if(S.Top==(SIZE-1)){
printf("Stack Overflow");
}else{
S.Top++;
S.A[S.Top]=Num;
    }
}

//_________________________________________________Pop

int Pop()
{
int Num;
if(S.Top==0){
printf("Stack Underflow");
}
Num=S.A[S.Top];
S.Top--;
return Num;
}

