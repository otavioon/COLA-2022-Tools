#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
#define ASCII 100
#define MAX_N 100
#define MAX_M 100
#define MAX 100
#define ASC 100
#define null 0
#define Len 100
#define shu 100
#define SUM 100
#define NUMBER 100
#define SIZE 100
#define X 100
#define Y 100
#define len 100
#define MAXN 100
#define MAXSIZE 100
#define maxrow 100
#define maxcol 100
#define num 100
#define mx 100
#define NUM 100
#define ROW 100
#define COL 100
#define SIZEE 100
#define MAX_LEN 100
#define LIU 100
#define maxsize 100
#define NUM 100
#define NO 100
#define Null 0
#define ID_DIGITS 100
#define INT_MAX 100
#define INT_MIN 100
#define FALSE 0
#define TRUE 1
struct students
{
	char name[21];
	int S1;
	int S2;
	char T1;
	char T2;
	int P;
	int JJ;
};

main()
{
	int n,i,max;
	struct students stu[NUM];
	long int all;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("\n%s %d %d %c %c %d",stu[i].name,&stu[i].S1,&stu[i].S2,&stu[i].T1,&stu[i].T2,&stu[i].P);
	}
	all=0;
	for(i=0;i<n;i++)
	{
		stu[i].JJ=0;
		if ((stu[i].S1>80)&&(stu[i].P>=1))
		{
			stu[i].JJ+=8000;
		}
		if((stu[i].S1>85)&&(stu[i].S2>80))
		{
			stu[i].JJ+=4000;
		}
		if (stu[i].S1>90)
		{
			stu[i].JJ+=2000;
		}
		if((stu[i].S1>85)&&(stu[i].T2=='Y'))
		{
			stu[i].JJ+=1000;
		}
		if((stu[i].S2>80)&&(stu[i].T1=='Y'))
		{
			stu[i].JJ+=850;
		}
		all =all +stu[i].JJ;
	}
	max=0;
	for (i=1;i<n;i++)
	{
		if (stu[i].JJ>stu[max].JJ)
		{
			max=i;
		}
	}
	printf("%s\n%d\n%ld\n",stu[max].name,stu[max].JJ,all);
}
