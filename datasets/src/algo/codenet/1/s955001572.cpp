#include<stdio.h>
int main()
{
	int a[10],i,s=0;
	for(i=1;i<=9;i++)
	scanf("%d",&a[i]); 
	if((a[2]-a[1])==(a[5]-a[4])&&(a[2]-a[1])==(a[8]-a[7]))
	s++;
	if((a[3]-a[2])==(a[6]-a[5])&&(a[3]-a[2])==(a[9]-a[8]))
	s++;
		if((a[4]-a[1])==(a[5]-a[2])&&(a[6]-a[3])==(a[4]-a[1]))
		s++;
			if((a[7]-a[4])==(a[8]-a[5])&&(a[7]-a[4])==(a[9]-a[6]))
		s++;
		if(s==4)
		printf("yes\n");
		else
		printf("no\n");
		return 0;
}