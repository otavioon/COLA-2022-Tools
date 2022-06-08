#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll i,j,a[1010][1010],mi;
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			cin>>a[i][j];
	for(i=1;i<=3;i++)
	{
		mi=10e17;
		for(j=1;j<=3;j++)
			mi=min(mi,a[i][j]);
		for(j=1;j<=3;j++)
			a[i][j]-=mi;
	}
	for(i=1;i<=3;i++)
	{
		mi=10e17;
		for(j=1;j<=3;j++)
			mi=min(mi,a[j][i]);
		for(j=1;j<=3;j++)
			a[j][i]-=mi;
	}
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			if(a[i][j]!=0)
			{
				cout<<"No\n";
				return 0;
			}
	cout<<"Yes\n";
}