#include <stdio.h>

int main()
{
	int C[9];
	for(int i = 0; i < 9; i++)
		scanf("%d", &C[i]);
	
	int p1 = C[0]+C[4]+C[8];
	int p2 = C[1]+C[5]+C[6];
	int p3 = C[2]+C[3]+C[7];
	
	printf(p1==p2 && p2==p3 ? "Yes" : "No") ;
}