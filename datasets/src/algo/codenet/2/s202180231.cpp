#include<bits/stdc++.h>
using namespace std;
#define SC scanf
#define PR printf
#define pb push_back
#define mp make_pair
#define SZ(v) ((int)(v).size())
#define rep(i,n) for(int i=0;i<(n);i++)
#define INF 1000000000
#define ll long long
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<pii> vii;
const int xx[4]={1,-1,0,0};
const int yy[4]={0,0,1,-1};
multiset<ll>ms;
int main(){
    ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		ms.insert(t);
	}
	int ans=0;
	while(!ms.empty()){
		auto it=ms.end();
		it--;
		int x=*it;
		ms.erase(it);
		int i;
		for(i=1;i<=x;i*=2);
		if(ms.find(i-x)!=ms.end()){
			ans++;
			ms.erase(i-x);
		}
	}
	cout<<ans<<endl;
	return 0;
}