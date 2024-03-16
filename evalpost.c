
/*---------------------------------------------------

EvalPost.C
Program to implement the evaluation of postfix expression
Prashan Chhetri
23/01/2024

--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 25

typedef struct StackType {
    int Top;
    float Oprnd[SIZE];
} STACK;

STACK S;

//____________________________________________________________user defined function

float Pop();
void Push(float Num);
int StackEmpty();
void InitStack();
void DisplayStack();
void Process(char Optr);
float EvalPostfix(char Postfix[]);


//________________________________________________________________________________

int main() 
{
    float Result;
    char Postfix[SIZE];

    printf("Program to evaluate postfix expression \n\n");

    printf("Enter the postfix expression: \n");
    InitStack();
    fgets(Postfix, SIZE, stdin);

    Result = EvalPostfix(Postfix);
    printf("Result = %5.2f \n", Result);

    return 0;
}

//____________________________________________________________push

void Push(float Num) 
{
    if (S.Top == SIZE - 1) {
        printf("STACK IS FULL \n");
    } else {
        S.Top++;
        S.Oprnd[S.Top] = Num;
    }
}

//____________________________________________________________pop

float Pop(void) 
{
    float Num;

    if (S.Top == 0) {
        printf("STACK IS EMPTY. \n");
        return -1;
    } else {
        Num = S.Oprnd[S.Top];
        S.Top--;
    }
    return Num;
}

//____________________________________________________________StackEmpty

int StackEmpty()
{
 return S.Top == 0;
}

//____________________________________________________________InitStack

void InitStack() 
{
    S.Top = 0;
}

//____________________________________________________________DisplayStack

void DisplayStack() 
{
    int i;

    if (S.Top == 0) {
        printf("EMPTY STACK\n");
    } else {
        for (i = 1; i <= S.Top; i++) {
            printf("%f \n", S.Oprnd[i]);
        }
    }
}

//____________________________________________________________function to process the data

void Process(char Optr) 
{
    float Result;
    float Num1, Num2;

    Num2 = Pop();
    Num1 = Pop();

    switch (Optr) {
        case '+':
            Result = Num1 + Num2;
            break;
        case '-':
            Result = Num1 - Num2;
            break;
        case '*':
            Result = Num1 * Num2;
            break;
        case '^':
            Result = pow(Num1, Num2);
            break;
        case '/':
            if (Num2 != 0) {
                Result = Num1 / Num2;
                break;
            } else {
                printf("DIVIDE BY ZERO ERROR \n");
                break;
            }
        default:
            printf("Invalid operator\n");
    }

    Push(Result);
}

//____________________________________________________________EvalExp()

float EvalPostfix(char Postfix[]) 
{
    char ch;
    float Result, Num;
    int i = 0;

    while ((ch = Postfix[i++]) != '\0') {
        if (ch >= '0' && ch <= '9') {
            Num = ch - '0';
            Push(Num);
        } else if (strchr("+-*/^", ch)) {
            Process(ch);
        }
    }

    Result = Pop();
    return Result;
}
