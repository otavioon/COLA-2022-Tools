#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

bool primes[int(1e5)+1];
void sieve()
{
	primes[0]=primes[1]= 0;
	for(int i = 2; i<=sqrt(int(1e5)+1); i++)
		if(primes[i])
			for(ll j = i*i; j<=int(1e5); j+=i)
				primes[j]= 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(primes,1,int(1e5)+1);
	ll n, f= INT_MAX;
	cin>>n;
	for(int i = 1;i <= int(1e5); i++)
	{
		if(primes[i] && n%i==0)
		{
			ll h = n/i;
			ll t = log10(h)+1, k = log10(i)+1;
			t = max(t,k);
			if(t<f)
				f = t;
		}
	}
	cout<<f<<endl;
	return 0;
}