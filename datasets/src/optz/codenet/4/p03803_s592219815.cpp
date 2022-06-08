#include<bits/stdc++.h>
#define fi first
#define se second
#define bug cout<<"--------------"<<endl
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=1e9;
const ll llf=1e18;
const int mod=1e9+7;
const int maxn=1e5+10;
int n;
struct ppo{
	int a,b,c;
	bool operator <(const ppo &r) const {
		if(a==r.a&&b==r.b) return c<r.c;
		if(a==r.a) return b<r.b;
		return a<r.a;
	}
};
set<ppo>q;
int a[45],b[45],c[45];
int ma,mb;
int ans=inf;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void dfs(int pos,int x,int y,int z){
	if(pos==(n+1)/2){
		q.insert(ppo{x,y,z});
		return;
	}
	dfs(pos+1,x+a[pos],y+b[pos],z+c[pos]);
	dfs(pos+1,x,y,z);
}
void dd(int pos,int x,int y,int z){
	if(pos==n+1){
		for(int i=1;i<=20;i++){
			int ka=ma*i,kb=mb*i;
			auto it=q.lower_bound(ppo{ka-x,kb-y,0});
			if(it!=q.end()){
				int da=it->a+x;
				int db=it->b+y;
				if(da==ka&&db==kb){
					ans=min(ans,z+it->c);
				}
			}
		}
		return;
	}
	dd(pos+1,x+a[pos],y+b[pos],z+c[pos]);
	dd(pos+1,x,y,z);
}
int main(){
	//ios::sync_with_stdio(false);
	//freopen("in","r",stdin);
	cin>>n>>ma>>mb;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	dfs(1,0,0,0);
	dd((n+1)/2,0,0,0);
	if(ans==inf) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
