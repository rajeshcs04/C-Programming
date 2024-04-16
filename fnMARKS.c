/*--------------------------------------------
MarksReport.c
A program to get the record of a class of students
---------------------------------------------*/

typedef struct StudentType{
	int SID;
	char Name[20];
	int M1,M2,M3;
	float Total, Avg;
	int Result;
}STUDENT;

# include <stdio.h>
# include <stdlib.h>
void fnInputStudentData();
void fnPrintStudentData();
void fnPrintMarksCard();
void fnMenu(int *Choice);

STUDENT S[20];
int N;

main()
{
	int Choice;
	
	fnMenu(&Choice);
	
	while(Choice){
		switch(Choice){
			case 1:
				fnInputStudentData();
				fnMenu(&Choice);
				break;
			case 2:
				fnPrintStudentData();
				fnMenu(&Choice);
				break;
			case 3:
				fnPrintMarksCard();
				fnMenu(&Choice);
				break;
			case 4:
				exit(1);
				break;
			default:
				fnMenu(&Choice);
				break;
		}
	}
}
//-------------------------MENU--------------------------------
void fnMenu(int *Choice){
	system("cls");
	printf("\tSt Josephs' University \n\n");
	printf("\tStudent information menu \n");
	printf("----------------------MENU---------------------\n");
	printf("1- Inputing student Data \n");
	printf("2- Printing class consolidated results\n");
	printf("3- Print Student report\n");
	printf("4- Exit");
	printf("\nEnter your choice: ");
	scanf("%d", Choice);
}

//------------------------(1)Inputing Data-------------------------
void fnInputStudentData() {
	int i;
	
    system("cls");
    printf("Input students' data\n");
    printf("Number of students: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        printf("Enter Name: ");
        scanf("%s", S[i].Name);
        printf("Enter ID: ");
        scanf("%d", &S[i].SID);
        printf("Enter three subject marks: ");
        scanf("%d %d %d", &S[i].M1, &S[i].M2, &S[i].M3);

        S[i].Total = S[i].M1 + S[i].M2 + S[i].M3;
        S[i].Avg = S[i].Total / 3;



        }
    }
}



//----------------------------(2)Consolidated Data--------------------
void fnPrintStudentData()
{
	int i;
	
	system("cls");
	printf("\t\t\t St.Josephs' University\n\n");
	printf("\t\t\t Consolidated Results\n\n");
	printf("ID\tName\tMaths\tComp\tEng\tTotal\t\tAverage\t\tResult\n\n");
	
	for(i=1;i<=N;i++){
		printf("%d\t%s\t",S[i].SID,S[i].Name);
		printf("%d\t%d\t%d\t%0.2f\t\t%0.2f\t\t",S[i].M1,S[i].M2,S[i].M3,S[i].Total,S[i].Avg);
		
		if (S[i].Result==0)
		printf("Distinction");
		if (S[i].Result==1)
		printf("First Class");
		if (S[i].Result==2)
		printf("Second Class");
		if (S[i].Result==3)
		printf("Pass");
		if (S[i].Result==-1)
		printf("Fail");
	printf("\n");
	}
	getch();
}

//--------------------------------(3)Induvidual Report--------------------
void fnPrintMarksCard()
{
	int i, SID, found=-1;
	
	system("cls");
	printf("\t\t St Josephs' University \n\n");
	printf("\t\t -----Marks' Card-----\n\n");
	printf("Enter your ID number: ");
	scanf("%d",&SID);
	for(i=1;i<=N;i++){
		if(SID==S[i].SID){
			found=1;
			printf(" Student ID: \t%d \n Name: \t\t%s\n Mathematics: \t%d\n Computers: \t%d\n English: \t%d\n Total: \t%0.2f\n Average: \t%0.2f\n\n",S[i].SID,S[i].Name,S[i].M1,S[i].M2,S[i].M3,S[i].Total,S[i].Avg);
			printf("---------------------------------------------------------\n\t\t");
			if (S[i].Result==0)
				printf("%s passed with Distinction", S[i].Name);
			if (S[i].Result==1)
				printf("%s passed with First Class", S[i].Name);
			if (S[i].Result==2)
				printf("%s passed with Second Class", S[i].Name);
			if (S[i].Result==3)
				printf("%s passed", S[i].Name);
			if (S[i].Result==-1)
				printf("%s failed", S[i].Name);
			printf("\n---------------------------------------------------------\n");
		}
	}
	if(found==-1){
		printf("%d does not exist..", SID);
	}
	getch();
}
