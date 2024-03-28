/*----------------------------------------------------

Sumof2diagonal8.C
Program to find the sum of two principal diagonal			
Prashan Chhetri
07/09/2023

-----------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

main()
{
	int A[20][20],N,i,j,Sum,D1,D2;
	
	printf("Program to find the sum of two principal diagonals");
	
	printf("\n\nEnter the value of N:");
	scanf("%d",&N);
	
	printf("\n\nEnter the elements of the matrix:\n");
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("The Matrix is: \n\n");
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	D1=0;
	D2=0;
	Sum=0;
	for(i=1;i<=N;i++){
		D1=D1+A[i][i];
		D2=D2+A[i][N-i+1];
	}
	Sum=D1+D2;
	
	printf("The sum of two principal diagonal is= %d  ",Sum);
}
