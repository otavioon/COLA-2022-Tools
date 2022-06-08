#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int n,ans;
pair<ll,int> a[200001];
int main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i].first;
	sort(a,a+n);
	for (int i=n;i--;)
    {
		if (a[i].second) continue;
		ll t=2LL<<__lg(a[i].first);
		int k=upper_bound(a,a+i,mp(t-a[i].first,0))-a;
		if (0<k && k<=i && a[i].first+a[k-1].first==t) ans++,a[k-1].second=1;
    }
	cout<<ans;
	return 0;
}