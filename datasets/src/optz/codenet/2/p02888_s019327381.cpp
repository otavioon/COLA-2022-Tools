#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int mod = 1000000007;
#define ll long long

int sum[2010][2010] = { 0 };
int L[2010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	sort(L, L + N, greater<int>());
	int ans = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = N - 1; k > j; k--) {
				if (L[i] - L[j] < L[k]) {
					//cout << j << " " << k << endl;
					ans += k - j;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}
