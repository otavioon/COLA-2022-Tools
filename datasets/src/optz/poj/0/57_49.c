#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int n,i,j;
    char *p1;
    int *p2;
    char a[10000][81];
    int b[10000];
    p2=b;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
                    p1=(a[i]);
                    gets(p1);
                    (*(p2+i))=1;
                    for(j=0;(*(p1+j))!='\0';j++)
                    {
                                                
                                                if(((*(p1+j))!='_')&&((!((*(p1+j))>47)&&((*(p1+j))<58)))&&((!((*(p1+j))>64)&&((*(p1+j))<91)))&&((!((*(p1+j))>96)&&((*(p1+j))<123))))
                                                {
                                                                                                                                                                                    (*(p2+i))=0;
                                                                                                                                                                                    break;
                                                }
                                                if((j==0)&&((!((*(p1+j))>64)&&((*(p1+j))<91))&&((!((*(p1+j))>96))&&((*(p1+j))<123))&&(*(p1+j))!='_'))
                                                {
                                                                                                                                                        (*(p2+i))=0;
                                                                                                                                                                                    break;
                                                }
                    }
    }
    for(i=0;i<n;i++)
    {
                    printf("%d\n",(*(p2+i)));
    }
   
    return 0;
}