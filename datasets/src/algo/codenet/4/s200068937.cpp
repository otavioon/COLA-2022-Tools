/*
    ||S|A|M|R|A|T||
    Author:codingsamrat
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ld long double
#define INF LONG_MAX
#define pb push_back
#define gcd __gcd
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define vii vector<int>
#define vll vector<long long>
typedef long long  ll;

ll bpow(ll a, ll b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
	int test;
	test=1;
	while(test--)
	{
	int n,k;
	cin>>n>>k;
	set<int> s;
	f(i,0,k)
	{
		int a;
		cin>>a;
		s.insert(a);
	}
	int c=10;
	int temp=1;
	for(auto i=s.begin();i!=s.end();i++)
	{
		if(*i==temp)
		temp++;
		else
		{c=temp;
		break;
		}
	}
	int ans=0;
	temp=0;
	while(n)
	{
		int k=n%10;
		n=n/10;
		if(s.count(k))
		k=c;
		
		ans+=(k*bpow(10,temp));
		temp++;
	}
	cout<<ans;
	
	
	}
     
return 0;

}
