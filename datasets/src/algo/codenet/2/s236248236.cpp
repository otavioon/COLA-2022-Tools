#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int v[200200];
bitset<200200> bs;
int main() {
	int n;
	scanf("%d ",&n);
	for(int i=0;i<n;i++) {
		int t;
		scanf("%d ",&t);
		v[i] = t;
	}
	sort(v,v+n);
	for(int i=30;i>=0;i--) {
		int tot = 1<<i;
		int s = 0,e = n;
		while(s<e) {
			e--;
			if(bs[e]) continue;
			while(s < n && (v[s]+v[e]<tot || bs[s])) {s++;}
			if(s >= e) break;
			if(v[s]+v[e] == tot && !(bs[e] || bs[s])) {bs.set(e);bs.set(s);
			//printf("match %d %d\n",s,e);
			}
		}
	}
	printf("%d\n",bs.count()/2);
}
