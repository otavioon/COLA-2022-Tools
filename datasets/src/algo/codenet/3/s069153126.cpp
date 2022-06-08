#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define lgr cerr<<"-------------"<<endl;
#define ms(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int MAXN=1e5+10;
int main()
{
	int n;
	cin>>n;
	int a[MAXN],b[MAXN],c[MAXN];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(a+1,a+1+n);
	sort(c+1,c+1+n);
	ll cnt=0;
	for(int i=1;i<=n;i++){
		int x=0,y=0;
		for(int j=1;j<=n;j++){
			if (b[i]>a[j])
				x++;
			if (b[i]<c[j])
				y++;
		}
		cnt+=x*y;
	}
	cout<<cnt<<endl; 
	return 0;
}