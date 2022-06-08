#include <iostream>
#include <cstdio>
#include <algorithm>

constexpr int MAX_LENGTH = 100010;

int main()
{
	int N, A_list[MAX_LENGTH], B_list[MAX_LENGTH], C_list[MAX_LENGTH];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", A_list + i);
	}
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", B_list + i);
	}
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", C_list + i);
	}

	std::sort(A_list, A_list + N);
	std::sort(B_list, B_list + N);
	std::sort(C_list, C_list + N);

	int count_B_gt_A[MAX_LENGTH] = {};
	int i = N-1, j = N-1;
	while (i >= 0 && j >= 0)
	{
		if (B_list[i] > A_list[j])
		{
			count_B_gt_A[i--] = j + 1;
		}
		else
		{
			--j;
		}
	}

	int count_B_lt_C[MAX_LENGTH] = {};
	i = 0; j = 0;
	while (i < N && j < N)
	{
		if (B_list[i] < C_list[j])
		{
			count_B_lt_C[i++] = N - j;
		}
		else
		{
			++j;
		}
	}

	int result = 0;
	for (i = 0; i < N; ++i)
	{
		result += count_B_gt_A[i] * count_B_lt_C[i];
	}
	printf("%d", result);
}