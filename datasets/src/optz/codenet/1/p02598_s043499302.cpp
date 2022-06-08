/*
Author: Vishal Singh  
(singhvishal0304@gmail.com)

"The days that break you are the days that make you."

*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);\
cin.tie(NULL);

#define md 1000000007


#define lli long long int
#define pb push_back
#define mp make_pair
#define vvi(r,c) vector<vector<lli>> v(r,vector<lli>(c));
#define fi first
#define se second
#define mem(arr,x) memset(arr,x,sizeof(arr))

lli power(lli a,lli b){
	if(b==0)
		return 1;
	if(b%2)
		return ((a%md)*(power(a,b-1)))%md;
	else
	{
		lli x=power(a,b/2);
		return (x*x)%md;
	}
}

lli numCuts(vector<lli>& a,lli mid){
	int n=a.size();
	lli sum=0;
	for(int i=0;i<n;i++){
		lli x=a[i]/mid;
		if(a[i]%mid)
		x++;
		sum+=x-1;
	}
	return sum;
}
lli bin_search(vector<lli>& a,lli l,lli r,lli k){
	if(l<r){
		lli mid=l+(r-l)/2;
		if(numCuts(a,mid)>k)
			return bin_search(a,mid+1,r,k);
		return bin_search(a,l,mid,k);
	}
	return l;
}

void solve(){
	lli n,k;
	cin>>n>>k;
	vector<lli> a(n);
	lli r=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		r=max(r,a[i]);
	}
	lli ans=bin_search(a,1,r,k);
	cout<<ans<<endl;

}


int main()
{	
    fastio();
	int t;
	
	t=1;
	while(t--){
		solve();
	}

	return 0;
}