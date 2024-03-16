/*-------------------------------------------------------------
InfixtoPostfix.c
Program to convert from infix to postfix
Rajesh C S
17/01/2024
------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25

typedef struct StackType {
    char Optrs[SIZE];
    int Top;
} STACK;

STACK S;

// Prototypes
void Push(char Optr);
char Pop(void);
int StackEmpty(void);
void InitStack(void);
char *InfixtoPost(char Infix[]);
int Precedence(char Optr);

// main()
int main(void) {
    char Infix[30], *Postfix;

    InitStack();
    printf("Program to convert infix expression into postfix expression\n");

    printf("\nEnter an INFIX expression:\n");
    gets(Infix);

    Postfix = InfixtoPost(Infix);

    printf("\nThe POSTFIX expression\n");
    puts(Postfix);

    getchar();

    return 0;
}

// push()
void Push(char Optr) {
    if (S.Top == SIZE - 1) {
        printf("STACK FULL");
        return;
    } else {
        S.Top += 1;
        S.Optrs[S.Top] = Optr;
    }
}

// pop()
char Pop(void) {
    char Optr;

    if (S.Top == 0) {
        printf("STACK EMPTY");
        return 0;
    } else {
        Optr = S.Optrs[S.Top];
        S.Top--;
        return Optr;
    }
}

// StackEmpty
int StackEmpty(void) {
    return S.Top == 0;
}

// initstack
void InitStack(void) {
    S.Top = 0;
}

// precedence
int Precedence(char Optr) {
    if (Optr == ')') {
        return 1;
    } else if (Optr == '(') {
        return 2;
    } else if ((Optr == '+') || (Optr == '-')) {
        return 3;
    } else if ((Optr == '/') || (Optr == '*')) {
        return 4;
    } else if (Optr == '^') {
        return 5;
    } else {
        return 0; // Default case
    }
}

// InfixtoPostfix
char *InfixtoPost(char Infix[]) {
    int i, j;
    char Optr, OptrStack, Ch;
    static char Postfix[30]; // Made it static to return it from the function

    i = 0;
    j = 0;

    while ((Ch = Infix[i]) != '\0') {
        if (Ch == '(') {
            Push(Ch);
        } else if ((Ch >= 'A' && Ch <= 'Z') || (Ch >= '0' && Ch <= '9')) 

