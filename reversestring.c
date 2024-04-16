/*---------------------------------------------------------------

StackRev.C
Program to reverse a string using stack
Rajesh C S
22/01/2023

-----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct StackType{
char Rev[SIZE];
int Top;
}STACK;

STACK S;

//_______________________________________________________PROTOTYPES

void Push(char ch);
char Pop();

//_____________________________________________________Main

main()
{
S.Top=0;

char Str[50],Rev[50];
int i,len;
printf("Program to reverse a string\n");

printf("Enter a strng of your choice: \n");
gets(Str);

len=strlen(Str);
for(i=0;i<len;i++){
Push(Str[i]);
}

printf("\n Original String: %s\n",Str);

for(i=0;i<len;i++){
Rev[i]=Pop();
}
Rev[i]='\0';
printf("Reversed String: %s",Rev);
}

//__________________________________________________Push

void Push(char ch)
{
if(S.Top==(SIZE-1)){
printf("Stack Overflow");
}else{
S.Top++;
S.Rev[S.Top]=ch;
    }
}

//_________________________________________________Pop

char Pop()
{
char ch;
if(S.Top==0){
printf("Stack Underflow");
}
ch=S.Rev[S.Top];
S.Top--;
return ch;
}

