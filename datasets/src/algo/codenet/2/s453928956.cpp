#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

multiset<ll> s;

int main()
{jizz
	ll ans=0,n,x;
	cin >> n;
	while(n--)
		cin >> x,s.insert(x);
	while(s.size()>=2)
	{
		x=*s.rbegin(),s.erase(--s.end());
		n=1<<__lg(x)+1;
		if(s.find(n-x)!=s.end())
			s.erase(s.find(n-x)),++ans;
	}
	cout << ans << "\n";
}