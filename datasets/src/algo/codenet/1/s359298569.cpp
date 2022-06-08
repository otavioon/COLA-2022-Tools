#include <stdio.h> 
int main(){
 int i,j,a[4],s=0,c[4][4],s1,s2,l=0;
 for(i=1;i<=3;i++)
 for(j=1;j<=3;j++)scanf("%d",&c[i][j]);
s1=c[2][1]-c[1][1];
s2=c[3][1]-c[2][1];
if(c[2][2]-c[1][2]==s1)l++;
if(c[3][2]-c[2][2]==s2)l++;
 if(c[2][3]-c[1][3]==s1)l++;
if(c[3][3]-c[2][3]==s2)l++;
if(l==4)printf("Yes");
    else printf("No");
	return 0;
	
}