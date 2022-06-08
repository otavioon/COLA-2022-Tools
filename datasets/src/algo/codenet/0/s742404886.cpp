#include <stdio.h>
char arr[105], a;
int main()
{
	//从第二个循环开始一致(当输入字符串的字符一样，另讨论）
	int i = 1, flag = 0, hehe=0;
	long long n = 0, m = 0, k;
	while ((arr[i] = getchar()) != '\n')
	{
		i++;
	}
	for (int j = 1; j <= i - 2; j++)
	{
		if (arr[j] != arr[j + 1]) hehe = 1;
	}
//	printf("i=%d\n", i);
	scanf("%lld", &k);
	arr[0] = ' ';
	for (int j = 1; j <= i - 1; j++)
	{
//		printf("%c\n", arr[j]);
		if (arr[j - 1] == arr[j]&&flag==0)
		{
//			printf("!!");
			n++;
			flag = 1;
			continue;
		}
		if (arr[j - 1] != arr[j] || (arr[j - 1] == arr[j] && flag == 1))
		{
//			printf("@@");
			flag = 0;
			continue;
		}
	}
	if (hehe == 0)
	{
		if ((i-1) % 2 == 0) printf("%lld\n", n * k);
		else printf("%lld\n", n * ((k + 1) / 2) + (n + 1) * (k - (k + 1) / 2));
		return 0;
	}
//	printf("%d\n", n);
	if (flag == 0) arr[0] = arr[i - 1];
	if (flag == 1) arr[0] = ' ';
	flag = 0;																																	
	for (int j = 1; j <= i - 1; j++)
	{
//		printf("%c\n", arr[j]);
		if (arr[j - 1] == arr[j] && flag == 0)
		{
//			printf("!!!");
			m++;
			flag = 1;
			continue;
		}
		if (arr[j - 1] != arr[j] || (arr[j - 1] == arr[j] && flag == 1))
		{
//			printf("@@@");
			flag = 0;
			continue;
		}
	}
//	printf("%d\n", m);
	long long ans = n + (k - 1) * m;
	printf("%lld\n", ans);
	return 0;
}