#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
#define ASCII 100
#define MAX_N 100
#define MAX_N 100
#define L 100
#define MAX 100
#define ASC 100
#define null 0
#define Len 100
#define M 100
#define SUM 100
#define NUMBER 100
#define SIZE 100
#define N 100
#define Max 100
#define X 100
#define Y 100
#define A 100
#define MAXN 100
#define MAXSIZE 100
struct patient
{
	char num[10];
	int age;
	struct patient *next;
};
int n;
struct patient *creat(void)
{
	struct patient *head;
	struct patient *p1,*p2;
	int num=1;
	head=NULL;
	while(num<=n)
	{
		p1=(struct patient *)malloc(LEN);
		scanf("%s %d",p1->num,&p1->age);
		if (num==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		num++;
	}
	p2->next=NULL;
	return (head);
}
int main()
{
	struct patient *pt,*p,*pre;
	int i,max,num=0;
	scanf("%d",&n);
	pt=creat();
	for (p=pt;p;p=p->next)
	{
		if (p->age>=60)
			num++;
	}
	for (i=1;i<=num;i++)
	{
		max=59;
		for (p=pt;p;p=p->next)
		{
			if (max<p->age)
				max=p->age;
		}
		for (p=pre=pt;p;p=p->next)
		{
			if (p->age!=max)
				pre=p;
			else
				break;
		}
		printf("%s\n",p->num);
		if (p==pt)
			pt=p->next;
		else
			pre->next=p->next;
	}
	for (p=pt;p;p=p->next)
		printf("%s\n",p->num);
	return 0;
}