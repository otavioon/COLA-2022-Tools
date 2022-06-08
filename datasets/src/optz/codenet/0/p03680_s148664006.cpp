#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=100000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

ll a[100001];

int main() {

	ll n;

	cin>>n;

	for(ll i=1; i<n+1; i++){
		cin>>a[i];
	}
	ll total=1;
	ll o=0;
	o=a[1];
	for(ll i=1; i<n+1; i++){
		if(a[o]==2){
			break;
		}else{
			total++;
			o=a[o];
		}
	}
	if(total>n){
		cout<<"-1"<<endl;
	}else{
	cout<<total+1<<endl;
	}
	return 0;
}
