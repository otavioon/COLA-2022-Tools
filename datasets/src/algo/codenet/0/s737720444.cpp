#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

char str[101];
int main() {
	int k, len = 0;

	char ch = getchar();
	while (ch != '\n') {
		str[len++] = ch;
		ch = getchar();
	}
	str[len++] = str[0];
	str[len] = '\0';
	scanf("%d", &k);

	int cnt = 1, cntt = 1;
	long long sum = 0, summ = 0;
	int flag = 0;
	for (int i = len - 2; i >= 0; i--) {
		if (str[i] == str[i + 1] && (i == len - 2||flag==1)) {
			cntt++;
			flag = 1;
		}
		else if (str[i] == str[i + 1]) {
			cnt++;
		}
		else {
			if (flag == 1) {
				summ += cntt / 2;			
				flag = 0;
			}
			else {
				if (cnt != 1) {
					sum += cnt / 2;
					cnt = 1;
				}
			}
		}
	}
	sum += cnt / 2;
	sum *= k;
	sum += summ * (k - 1);
	if (cntt != 0)	sum += (cntt - 1) / 2;
	printf("%lld\n", sum);
	return 0;
}