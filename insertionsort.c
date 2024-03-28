/*.....................................
              Insertionsort.c
              Rajesh C S
              07/02/2024
......................................*/

#include<stdio.h>
#include<stdlib.h>

//_____________________________prototype______________________

void InputArray(int A[30], int N);
void PrintArray(int A[30], int N);
void Insertionsort(int A[30], int N);

//____________________________________________________________

main()
{
	int A[30],N;
	
	printf("Program to enter some number and sort using insertion sort");
	
	printf("Enter the value of N:");
	scanf("%d",&N);
	
	printf("Enter the numbers:",N);
	InputArray(A,N);
	
	printf("Array before sorting:");
	PrintArray(A,N);
	
	printf("Array after sorting:");
	printArray(A,N);
}

//______________________function to Input Array__________________

void InputArray(int A[30], int N)
{
	int i;
	
	for(i=1;i<=N;i++){
		scanf("%d",&A[i]);
	}
}

//______________________function to Print Array___________________

void PrintArray(int A[30], int N)
{
	int i;
	
	for(i=1;i<=N;i++){
		printf("%d",A[i]);
	}
}

//_______________________function to Insertion sort________________

void Insertionsort(int A[30], int N)
{
	int i,j,X;
	
	for(i=2;i<=N;i++){
		X=A[i];
		j=j-1;
		while((X<A[j])&&(j>=1)){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=X;
    }
}
