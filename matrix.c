/*........................................
            Matrix.c
            Rajesh C S
            31/08/2023
.........................................*/

#include<stdio.h>
#include<stdlib.h>

main()
{
	int A[10][10],M,N,i,j;
	
	printf("Enter the value of matrix to see the content of an array\n");
	
	printf("Enter the value of M & N:");
	scanf("%d%d",&M,&N);
	
	for(i=1;i<=M;i++){
		for(j=1;j<=N;j++){
			scanf("%d",A[i][j]);
		}
	}
	for(i=1;i<=M;i++){
		for(j=1;j<=N;j++){
			printf("%c",A[i][j]);
		}
	}
}
