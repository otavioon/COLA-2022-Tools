#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

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
int main()
{
	int i,l;
	char s1[101];//????????????
	char s2[101]={0};//?????????????
	char *p=NULL,*q=NULL;//??????
	gets(s1);//?????
	l=strlen(s1);//????
	for(i=0,p=s1,q=s2;i<l;i++,p++,q++)//????????
	{
		if(i<l-1)//??????????
		{
            *q=*p+*(p+1);//???????????
		}
		else//??  ?????????
		{
			*q=*p+*(p-l+1);//???????????
   		}
	}
	cout <<s2<<endl;//??s2
	return 0;
}
