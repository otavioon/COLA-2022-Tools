#include <stdio.h>
#include <stdlib.h>
int main()
{
	int iNum1 = 1;
	int iNum2 = 1;
	int iCount1;
	int iMaxCount1 = 0;
	int** piNum;
	piNum = (int**)malloc(sizeof(int*) * 3000);
	for (iCount1 = 0; iCount1 < 3000; iCount1++)
	{
		piNum[iCount1] = (int*)malloc(sizeof(int) * 2);
	}
	do
	{
		scanf("%d%d", &iNum1,&iNum2);
		piNum[iMaxCount1][0] = iNum1;
		piNum[iMaxCount1][1] = iNum2;
		iMaxCount1++;
	} while (iNum1 != 0 || iNum2 != 0);
	for (iCount1 = 0; iCount1 < iMaxCount1 - 1; iCount1++)
	{
		if (piNum[iCount1][0] > piNum[iCount1][1])
		{
			printf("%d %d\n", piNum[iCount1][1], piNum[iCount1][0]);
		}
		else
		{
			printf("%d %d\n", piNum[iCount1][0], piNum[iCount1][1]);
		}
	}
	for (iCount1 = 0; iCount1 < 50; iCount1++)
	{
		free(piNum[iCount1]);
	}
	free(piNum);
	return 0;
}
