#include <bits/stdc++.h>
using namespace std;

const int Maxd = 3;

int A[Maxd][Maxd];

int main()
{
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			scanf("%d", &A[i][j]);
	int got = A[1][0] - A[0][0];
	for (int j = 1; j < Maxd; j++)
		if (A[1][j] - A[0][j] != got) { printf("No\n"); return 0; }
	got = A[2][0] - A[0][0];
	for (int j = 1; j < Maxd; j++)
		if (A[2][j] - A[0][j] != got) { printf("No\n"); return 0; }
	printf("Yes\n");
	return 0;
}