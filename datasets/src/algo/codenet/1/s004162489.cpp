#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e5 + 7;
const int Inf = 1 << 30;
int a[5][5];

int main() {
	int sum = 0;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
	}
	if(sum % 3) puts("No");
	else puts("Yes");
}