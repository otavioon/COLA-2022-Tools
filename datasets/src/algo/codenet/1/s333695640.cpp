#include <stdio.h>

using namespace std;

int A[10];

int main()
{
	int i,j;
	bool judge = true;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&A[3*i+j]);
		
	if(A[2]-A[1]==A[5]-A[4]&&A[5]-A[4]==A[8]-A[7])judge = true;
	else judge = false;
	if(A[1]-A[0]==A[4]-A[3]&&A[4]-A[3]==A[7]-A[6])judge = true;
	else judge = false;
	if(A[3]-A[0]==A[4]-A[1]&&A[4]-A[1]==A[5]-A[2])judge = true;
	else judge = false;
	if(A[6]-A[3]==A[7]-A[4]&&A[7]-A[4]==A[8]-A[5])judge = true;
	else judge = false;
	
	if(judge)printf("Yes");
	else printf("No");
	return 0;
}