#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define LEN 100
#define ASCII 100
#define MAX_N 100
#define MAX_M 100
#define MAX 100
#define ASC 100
#define null 0
#define Len 100
#define SUM 100
#define NUMBER 100
#define SIZE 100
#define MAXN 100
#define MAXSIZE 100
#define maxrow 100
#define maxcol 100
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
#define hang 100
#define lie 100
#define lll 100
#define LEM 100
#define K 100
#define INF 100
#define MONTH 12
#define true 1
#define PI 100
#define maxlen 100
#define maxinputint 100
#define STUDENT_NUM 100
#define TOTAL 100
#define LEN1 100
#define student_num 100
#define MAXLEN 100
#define MAXL 100
#define nMax 100
#define Vocabularysize 100
#define Sentencelength 100
#define LENGTH 100
#define ARRAY 100
/*
 * julipaixu.cpp
 *????????n??????10??,??n?????????,???? [ ????]  ???????????????????
 *  Created on: 2013-11-1
 *      Author: 13141
 *
????????????????n??????????????????(??????)?????????0?100????????????????
 *
?????n????????n*(n-1)/2???????????
(x1,y1,z1)-(x2,y2,z2)=??
???????????2??
 */
int main()
{
	int n;
	cin>>n;
	int x[n],y[n],z[n];
	int t=n*(n-1)/2;//CN2 ??
	int d[t];
	int a[t],b[t];//??????????????
	int k=0,i,j;
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			d[k]=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));//????????
			a[k]=i;
			b[k]=j;
			k++;
		}
	}
	for(int c=1;c<t;c++)
	{
		for(int r=0;r<(k-c);r++)
		{
			if(d[r]<d[r+1])
			{
				swap(d[r],d[r+1]);
				swap(a[r],a[r+1]);
				swap(b[r],b[r+1]);
			}
		}
	}
	for(int w=0;w<t;w++)
	{
		cout<<"("<<x[a[w]]<<","<<y[a[w]]<<","<<z[a[w]]<<")-("<<x[b[w]]<<","<<y[b[w]]<<","<<z[b[w]]<<")="<<fixed<<setprecision(2)<<sqrt(d[w])<<endl;
	}

	return 0;
}