#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll a[300000];
int main(){
	int n;scanf("%d",&n);
	rep(i,n)scanf("%lld",&a[i]);
	multiset<ll>ms;
	rep(i,n)ms.insert(a[i]);
	int cnt=0;
	while(ms.size()>1){
		ll a=*ms.begin();ms.erase(ms.begin());
		for(ll i=1;i<INT_MAX;i<<=1){
			if(i>=a){
				auto it=ms.find(i-a);
				if(it!=ms.end()&&*it==i-a){
					ms.erase(it);
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;
}