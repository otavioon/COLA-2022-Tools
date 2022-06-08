#include<bits/stdc++.h>
using namespace std;

#define pi 3.141592654
#define fix(n) cout << fixed << setprecision(n)

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)

#define si(d)  scanf("%d",&d)
#define sll(d) scanf("%lld",&d)
#define pin(d) printf("%d\n",d)
#define pln(d) printf("%lld\n",d)
#define nl 	   printf("\n")

#define ll long long
#define ull unsigned long long

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define vi vector<int>
#define pii pair<int,int> 
#define piii pair<pair<int,int>,int> 

#define chalne_de continue
int mod=1000000007;
const int N = 1000005;

ll gcd(ll a , ll b)
{
    if ( b == 0)
    return a;
    return gcd( b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ll n, a, b;
	cin >> n >> a >> b;
	set<pair<ll,ll> > s,p;
	rep(i,0,n)
	{
		int x;
		cin >> x;
		s.insert({-x,i});
	}
	int cnt = 0;
	bool flag = true;
	ll t = a;
	while ( true)
	{
		cnt ++;
		if ( cnt % 2 )
		{
			while ( !s.empty())
			{
		auto x = *s.begin();
		s.erase(s.begin());
		int f = x.fi * -1;
		if ( flag )
		{
			f -= t;

		}
		else
			f -= b;
		if ( f > 0)
			p.insert({-f,x.se});
		}
		if ( p.size() == 0)
			break;
		}
		else
		{
			while ( !p.empty())
			{
		auto x = *p.begin();
		p.erase(p.begin());
		int f = x.fi * -1;
		if ( flag )
		f -= a, flag = false;
		else
			f -= b;
		if ( f > 0)
			s.insert({-f,x.se});
		}
		if ( s.size() == 0)
			break;
		}

		flag = true;

	}
	cout << cnt << endl;
	return 0;
}
