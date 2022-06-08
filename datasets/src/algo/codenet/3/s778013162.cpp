#include <stdio.h>
#include <cstdio>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define itn int
#define fro for

long long int A[6543210];
long long int B[6543210];
long long int C[6543210];
long long int A_new[6543210];
long long int B_new[6543210];
long long int C_new[6543210];

int main()
{

	long long int  N;
	scanf("%lld", &N);

	for (long long int  a = 0; a < N; ++a)
	{
		scanf("%lld", &A[a]);
	}
	for (long long int  a = 0; a < N; ++a)
	{
		scanf("%lld", &B[a]);
	}
	for (long long int  a = 0; a < N; ++a)
	{
		scanf("%lld", &C[a]);
	}

	std::sort(A, A + N);
	std::sort(B, B + N);
	std::sort(C, C + N);

	long long int  A_start, B_start, C_end;
	long long int  A_end, B_end;
	long long int  counter;

	for (long long int  a = 0; a < N; ++a)
	{
		if (A[a] < B[0])
		{
			A_start = a;
			break;
		}
	}

	for (long long int  a = 0; a < N; ++a)
	{

		if (B[a] < C[0])
		{
			B_start = a;
			break;
		}
	}



	printf("%lld\n", (N - A_start) * (N - B_start) * N);


	

	return 0;
}