#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ARREP(i,n,X) for(int i=0;i<(n);i++)cin>>X[i]
#define FOR(i,X,n) for(int i=(X);i<(n);i++)
#define EREP(i,n) for(int i=1;i<=(n);i++)

#define DEB(X) if(mode==1)cout<< #X <<": "<<X<<" ";
#define DEB2(X) if(mode==1)cout<<X<<" ";
#define ARDEB(i,X) if(mode==1)cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define FORDEB(n,X) if(mode==1)for(int i=0;i<(n);i++)ARDEB(i,X)
#define END if(mode==1)cout<<endl;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define ALL(X) X.begin(),X.end()
struct edge{int to,cost;};
//struct edge{int from,cost,to;};

const int INF=100000000;
int mode=1;

int main(){
	int ok,ng,n,a[100000],b[100000],c[100000];
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	REP(i,n){
		ll res=1;
		ok=0;ng=n;
		if(a[0]>=b[i])continue;
		while(abs(ok-ng)>1){
			int mid=(ok+ng)/2;
			if(a[mid]<b[i]) ok=mid;
			else ng=mid;
		}
		ok++;
		res*=ok;
		ok=n-1;ng=-1;
		if(c[n-1]<=b[i])continue;
		while(abs(ok-ng)>1){
			int mid=(ok+ng)/2;
			if(c[mid]>b[i]) ok=mid;
			else ng=mid;
		}
		res*=n-ok;
		ans+=res;
	}
	cout<<ans<<endl;
	return 0;
}