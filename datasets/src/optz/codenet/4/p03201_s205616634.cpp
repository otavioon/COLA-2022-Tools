#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

int const MAXN=220000;
int N;
int a[MAXN];
unordered_map<int,set<int>> b;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);

	cin>>N;
	rep(i,0,N) cin>>a[i];

	rep(i,0,N) b[a[i]].insert(i);

	int res=0;
	per(k,0,31) {
		int x=1<<k;
		rep(i,0,N) if (a[i]!=-1 && a[i]<x && b.count(x-a[i])) {
			b[a[i]].erase(i);

			auto &bb=b[x-a[i]];
			while (!bb.empty() && a[*bb.begin()]==-1) bb.erase(bb.begin());
			if (!bb.empty()) {
				int j=*bb.begin();
				bb.erase(bb.begin());
				a[i]=-1;
				a[j]=-1;
				res++;
			}

			if (a[i]!=-1) b[a[i]].insert(i);
		}
	}
	cout<<res<<"\n";
}
