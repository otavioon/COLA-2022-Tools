#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII 100
#define MAX_N 100
#define MAX_M 100
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
#define tsuhu 100
#define l 100
#define h 100
#define maxn 100
#define MAXLENGTH 100
#define SEX 100
//
//  main.c
//  Track 79,???C???
//
//  Created by Charles.thRay.Lee on 2/1/13.
//  Copyright (c) 2013 Peking University. All rights reserved.
/*
 ??	???? ???? 06 ????? ????
 ??
 ??n????????????????????C?????????????????????C????????
 ????
 ??????n???n?????????????????????????????20?
 ????
 ?????????????C????????????yes?????no?
 ????
 6
GUE9NF1Ic
cGB8nd97F3
RKPEGX9R;TWyYcp
iefZIko1s}zy9XBg
sapOF3
6Lv5BYPeLPJ3vV`2[h
 ????
 yes
 
 yes
 
 no
 
 no
 
 yes
 
 no
 ??
 ??????????
 
 ??:???????????????? &#8226; ??:
 ??????????????,????????? ??????
 ?????(????)
 ???????(????????)  ??:????,??????32???
?:???????????
sum Sum M.D.John day Date 3days student_name #33 lotus_1_2_3
char a>b _above $123
*/


int main()
{
    int n,i,i1,k=1;
    long len;
    scanf("%d",&n);
    char s[500][20];
    
    for (i=0; i<n; i++) {
        scanf("%s",s[i]);
        k=1;
        if ((s[i][0]<'A'||s[i][0]>'Z')&&(s[i][0]<'a'||s[i][0]>'z')&&s[i][0]!='_') {
            printf("no\n");
            continue;
        }
        len=strlen(s[i]);
        for (i1=1; i1<len; i1++) {
            if ((s[i][i1]<'A'||s[i][i1]>'Z')&&(s[i][i1]<'a'||s[i][i1]>'z')&&s[i][i1]!='_'&&(s[i][i1]<'0'||s[i][i1]>'9'))
            {
                printf("no\n");
                k=0;
                break;
            }
        }
        if (k==1) {
            printf("yes\n");
        }
    }
    
}
