#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define repr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr_inv(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define rep(i,n) repr(i,0,n)
#define INF 2000000000
#define INFLL 9000000000000000000
using namespace std;
int main(void)
{
	int n;
	long long ans=0;

	cin>>n;

	vector<long long> a(n), b(n), c(n);

	rep(i, n) cin>>a[i];
	rep(i, n) cin>>b[i];
	rep(i, n) cin>>c[i];

	sort(a.begin(), a.end());
	sort(c.begin(), c.end());

	rep(i, n){
		vector<long long>::iterator top=lower_bound(a.begin(), a.end(), b[i]);
		vector<long long>::iterator bottom=upper_bound(c.begin(), c.end(), b[i]);
		ans+=(long long)(top-a.begin())*(n-(long long)(bottom-c.begin()));
	}
	cout<<ans<<endl;
}
