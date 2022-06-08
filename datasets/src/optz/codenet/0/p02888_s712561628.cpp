#include <stdio.h>

#define MAXL 1001
int Stick[MAXL];
int StickKind[MAXL];

int main()
{
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif

	int N;
	scanf("%d", &N);

	int StickKindLen = 0;
	int t;
	for (int n = 0; n < N; n++)
	{
		scanf("%d", &t);
		Stick[t]++;
	}

	for (int l = 0; l < MAXL; l++)
		if (Stick[l])
			StickKind[StickKindLen++] = l;

#ifdef _WIN32
	printf("Kind : ");
	for(int i = 0; i < StickKindLen; i++)
		printf("%d ", StickKind[i]);
	printf("\n");
#endif

	int Result = 0;
	while (1)
	{
		int l = 0;
		int L[3] = {0,0,0};
		for (int i = 0; i < StickKindLen && l < 3; i++)
			if (StickKind[i])
			{
				if (l < 2)
					L[l++] = i;
				else if (StickKind[i] < StickKind[L[0]] + StickKind[L[1]])
				{
					L[l++] = i;
					break;
				}
			}


		if (l != 3)
			break;

		while (	0 < Stick[StickKind[L[0]]] && 
				0 < Stick[StickKind[L[1]]] && 
				0 < Stick[StickKind[L[2]]])
		{
			Stick[StickKind[L[0]]]--; 
			if (!Stick[StickKind[L[0]]]) 
				StickKind[L[0]] = 0;
			Stick[StickKind[L[1]]]--; 
			if (!Stick[StickKind[L[1]]]) 
				StickKind[L[1]] = 0;
			Stick[StickKind[L[2]]]--; 
			if (!Stick[StickKind[L[2]]]) 
				StickKind[L[2]] = 0;
			Result++;
		}

	}


	printf("%d", Result);
}