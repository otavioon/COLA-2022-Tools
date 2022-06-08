#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

const long long MOD = 1000000007;

char s[110];
char t[210];
long long szS;
long long szT;
long long k;

long long checkDupCount(char *s, int szS)
{
	long long ans = 0;
	for (int i = 1 ; i < szS - 1 ; i++)
	{
		if (s[i - 1] == s[i])
		{
			ans++;
			s[i]++;
			if (s[i] > 'z')
				s[i] = 'a';
			if (s[i] == s[i + 1])
			{
				s[i]++;
				if (s[i] > 'z')
					s[i] = 'a';
			}
		}
	}
	
	int tail = szS - 1;
	if (s[tail - 1] == s[tail])
	{
		ans++;
		s[tail]++;
		if (s[tail] > 'z')
			s[tail] = 'a';
	}
	
	return ans;
}

int main()
{
	scanf("%s\n", s);
	scanf("%d", &k);
	
	szS = strlen(s);
	strcpy(t, s);
	szT = strlen(t);
	
	long long curCount = checkDupCount(t, szT);
	
	if (k == 1)
	{
		printf("%lld\n", curCount);
	}
	else
	{
		strcpy(t, s);
		strcat(t, s);
		szT = strlen(t);
		
		long long allCount = checkDupCount(t, szT);
		long long sectionCount = allCount - curCount;
		long long ans = sectionCount * (k - 1) + curCount;
		printf("%lld\n", ans);
	}
	
	return 0;
}
