#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int main ()
{
	int a[3][3];
	int n,i,j;
	for (i=0;i<3;i++)
	for (j=0;j<3;j++)
	scanf("%d",&a[i][j]);
	if (a[0][0]-a[1][0]==a[0][1]-a[1][1]&&a[0][0]-a[1][0]==a[0][2]-a[1][2]&&a[1][0]-a[2][0]==a[1][1]-a[2][1]&&a[1][0]-a[2][0]==a[1][2]-a[2][2])
	printf ("Yes\n");
	else printf ("No\n");
	return 0;
}