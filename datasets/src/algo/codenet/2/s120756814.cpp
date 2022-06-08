#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<set>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
int N;
multiset<int> A;
int main() {
	int t, k, c=0;
	scanf("%d", &N);
	rep(i, 0, N)scanf("%d", &t), A.insert(t);
	while (A.size() > 1) {
		auto it = A.end();
		it--;
		t = *it;
		A.erase(it);
		for (k = 1; k <= t; k *= 2);
		it = A.find(k - t);
		if (it != A.end()) {
			A.erase(it);
			c++;
		}
	}
	printf("%d", c);
	return 0;
}