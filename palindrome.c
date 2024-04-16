/*---------------------------------------------------------------

Palindrome.C
Program to check whether a given string is palindrome or not
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
  printf("Program to check whether a string is Palindrome or not\n");

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

  if(strcmp(Str,Rev)==0){
  printf("\nThe given string is a palindrome");
  }else{
       printf("\nThe given string is not a palindrome");
}
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

