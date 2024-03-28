/*-----------
fnstddev.c
Program to find standard deviations using functions
Rajesh C S
24/09/2023
-------------*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//----Prototype----
void fnInputArray(int N, int A[20]);
void fnPrintArray(int N, int A[20]);
float fnstddev(int N, int A[20]);

main()
{
   int N, X[20];
   float stddev;
   
   printf("Program to find standard deviations using functions\n\n");
   
   printf("Enter value of N: ");
   scanf("%d", &N);
   
   printf("Enter %d Numbers:", N);
   fnInputArray(N, X);
   
   printf("Content of Array: ");
   fnPrintArray(N, X);
   
   stddev=fnstddev(N, X);
   
   printf("\nStandard Deviation = %f", stddev);
}   
//-------------------

void fnInputArray(int N, int A[20])
{
   int i;
   
   for(i=1;i<=N;i++){
      scanf("%d", &A[i]);
   }
}

void fnPrintArray(int N, int A[20])
{
   int i;
   
   for(i=1;i<=N;i++){
      printf("%d ", A[i]);
   }
}
      
float fnstddev(int N, int A[20])
{
   int i, sumx, sumxsqr;
   float Avg, T1, T2, var, stddev;
   
   sumx=0;
   sumxsqr=0;
   
   for(i=1;i<=N;i++){
      sumx=sumx+A[i];
      sumxsqr=sumxsqr+A[i]*A[i];
   }
   
   Avg=sumx/N;
   T1=sumxsqr/N;
   T2=Avg*Avg;
   var=T1-T2;
   stddev=sqrt(var);
   
   return stddev;
}
