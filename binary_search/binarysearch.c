/*-----------------------------------
           Rajesh C S
           binarysearch.c
           19-02-2024
-----------------------------------*/

#include<stdio.h>
#include<stdlib.h>

//-----------prototypes---------------

void fnbublesort(int N,int a[20]);
void fninputarray(int N,int a[20]);
void fnprintarray(int N,int a[20]);
int fnbinarysearch(int N,int a[20],int num);

//---------------main

main()
{
	int i,N,x[20],found,num;
	printf("Program to arrange the numbers using bubblesort\n\n ");
	
	printf("Enter the value of N:");
	scanf("%d",&N);
	
	printf("\nEnter the %d numbers:",N);
	fninputarray(N,x);
	fnbublesort(N,x);
	
	printf("The sorted array is");
	fnprintarray(N,x);
	
	printf("\nEnter the number:");
	scanf("%d",&num);
	
	found=fnbinarysearch(N,x,num);
	if(found==1){
		printf("Number is found\n");
	}else{
		printf("Number not found\n");
	}
	
}

//-----------------------

void fninputarray(int N,int a[20])

{
	int i;
	for(i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
}

//------------

void fnbublesort(int N,int a[20])
{
	int i,j,temp;
	for(i=1;i<=(N-1);i++){
		for(j=1;j<=(N-i);j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

//------------------

void fnprintarray(int N,int a[20])

{
	int i;
	for(i=1;i<=N;i++){
		printf(" %d",a[i]);
	}
	
}

//--------------------------

int fnbinarysearch(int N,int a[20],int num)

{
	int low,high,middle,found;
	found = -1;
	low=1;
	high=N;
	while(low<high){
		middle=(low+high)/2;
		if(a[middle]==num){
			found=1;
			break;
		}else if(num<a[middle]){
			high=middle-1;
		}else{
			low=middle+1;
		}	
	}
	return found;
}