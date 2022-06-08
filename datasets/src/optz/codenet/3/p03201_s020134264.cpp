#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<(n);i++)
#define P pair<int,int>
#define mod 1000000007
#define S second
#define F first
#define int long long
using namespace std;
int a[200000],xx[200000],n;
bool bo[200000];
vector<pair<int,P>> v;
int solve(int x,int y){
	int l=x+1,r=n;
	while(r-l>=1){
		int i=(l+r)/2;
		if(a[i]==y) return i;
		else if(a[i]<x) l=i+1;
		else r=i;
	}
	return -1;
}
signed main(){
	int c=0,ans=0;
	cin>>n;
	f(i,n) cin>>a[i];
	sort(a,a+n);
	f(i,n){
		f(j,31){
			if(a[i]<pow(2,j+1)){
				int b=solve(i,pow(2,j+1)-a[i]);
				if(b!=-1){
					v.push_back(pair<int,P>(0,P(i,b)));
					c++;
				}
			}
		}
	}
	f(i,c){
		xx[v[i].S.F]++;
		xx[v[i].S.S]++;
	}
	f(i,c){
		v[i].F+=xx[v[i].S.F]+xx[v[i].S.S];
	}
	sort(v.begin(),v.end());
	int z=0;
	f(i,c){
		if(z+v[i].F>c*2) break;
		if(!bo[v[i].S.F]&&!bo[v[i].S.S]){
			bo[v[i].S.F]=true;
			bo[v[i].S.S]=true;
			z+=v[i].F;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
