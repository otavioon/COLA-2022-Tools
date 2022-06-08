#include<stdio.h>
int main(void)
{
	int N, D,K,P;
	P = 1;

	scanf("%d %d", &N, &D);
	while (K >= N) {
		K = 1 + D * 2;
		P++;
	}
	printf("%d", P);

	return 0;


}