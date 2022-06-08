
// Problem : E - Logs
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#define int long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define mod 998244353
#define bug cout<<"HY"<<endl
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define numize(A) A.numize(unique(A.begin(), A.end()) - A.begin())
typedef pair<int,int> P;
int power(int a,int b)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return (power((a*a)%mod,b/2))%mod;
    return (a*(power((a*a)%mod,b/2))%mod)%mod;
}
int modInv(int n)
{
    return power(n, MOD-2);
}
int nCr(int n, int r, int p=MOD)
{
   if (r==0)
      return 1;
    int Fact[n+1];
    Fact[0] = 1;
    for (int i=1 ; i<=n; i++)
    {
        Fact[i] = (Fact[i-1]*i)%p;
    }
    return (((Fact[n]* modInv(Fact[r])) % MOD) *(modInv(Fact[n-r]) % MOD)) % MOD;
}
double PI=3.14159265359;
void solve()
{
	int n,k,i;
	cin>>n>>k;
	int A[n];
	for(i=0;i<n;i++)
		cin>>A[i];	
	sort(A,A+n);
	double low=0,high=A[n-1];
	double ans=0;
	while(high-low>=.000001)
	{
		double mid=(low+high)/2;
		int cnt=0;
		for(i=0;i<n;i++)
		{
			int num=A[i]/mid;
			if(A[i]==num*mid)
				num--;
			cnt+=num;
		}
		ans=mid;
		if(cnt>k)
		{
			low=mid;
		}
		else
		{
			high=mid;
		}
	}
	// ans=(int)ans
	// cout<<ans<<endl;
	int f=ans;
	// cout<<ans-f<<endl;
	if(ans-f>=.5)
		cout<<f+1<<endl;
	else
		cout<<f<<endl;
}
int32_t main()
{
    boost;
    int  t=1;
    // cin>>t;
    while(t--)
    {
    	solve();
    }
}
