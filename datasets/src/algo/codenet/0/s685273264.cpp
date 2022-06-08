#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

long long int count(char *S, int len)
{
	long long int cnt = 0;
	for (int i = 0; i < len;){
		char prev = S[i]; int j;
		for (j = i + 1; j < len; j++){
			if (prev != S[j]){
				break;
			}
		}
		cnt += (j - i) / 2;
		i = j;
	}

	return cnt;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	char S[200]; scanf("%s", S);
	long long int K; scanf("%lld", &K);

	int len = strlen(S);
	long long int ret = 0;

	if (S[0] == S[len - 1]){
		int left = 0;
		for (; left < len; left++){
			if (S[left] != S[0]){
				break;
			}
		}
		int right = len - 1;
		for (; right >= 0; right--){
			if (S[right] != S[len - 1]){
				break;
			}
		}
		if (len == left){
			ret = ((long long int)len * K) / 2;
		}
		else{
			ret += count(S + left, right - left + 1)*K;
			ret += ((left + len - right - 1) / 2)*(K - 1) + left / 2 + (len - right - 1) / 2;
		}
	}
	else{
		ret += count(S, len)*K;
	}

	printf("%lld", ret);


	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}