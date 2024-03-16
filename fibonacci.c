/*----------------------
5/1/24
fibonacci.c
Rajesh C S
----------------*/

#include<stdio.h>
#define SIZE 20

void Push(int Num);
double Pop();
void DisplayStack();

typedef struct StackType{
	int Fib[SIZE];
	int Top;
}STACK;

STACK F;

int main()
{
	int N,i,F1,F2,F3;
	
	system("cls");
	printf("prg to find N fibonacci series\n\n");
	printf("enter a number:");
	scanf("%d",&N);
	
	F1=0;
	F2=1;
	Push(F1);
	Push(F2);
	i=3;
	while(i<=N){
		F2=Pop();
		F1=Pop();
		F3=F1+F2;
		Push(F1);
		Push(F2);
		Push(F3);
		i++;
	}
	DisplayStack();
}


void Push(int Num)
{
	if(F.Top==SIZE-1){
		printf("stack overflow\n");
		return;
	}else{
		F.Top++;
		F.Fib[F.Top]=Num;
	}
}

double Pop()
{
	int num;
	if(F.Top==0){
		printf("Stack underflow\n");
		return 0;
	}else{
		num=F.Fib[F.Top];
		F.Top--;
		return num;
	}
}

void DisplayStack()
{
	int i;
	for(i=1;i<=F.Top;i++){
		printf("%d ",F.Fib[i]);
	}
}
