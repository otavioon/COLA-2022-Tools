#include <stdio.h>

using namespace std;

int A[10],x[3],y[3];

int main()
{
	int i,j;
	bool judge = true;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&A[3*i+j]);
			
	x[1] = A[1]-A[0]; x[2] = A[2]-A[0];	
	y[1] = A[3]-A[0]; y[2] = A[6]-A[0];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(A[i*3+j]-A[0]!=x[j]+y[i])judge = false;
		
	if(judge)printf("Yes");
	else printf("No");
	return 0;
}