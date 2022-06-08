#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = ((B)-1); I >= (A); --I)
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c[4][4];
	FOR(i,1,4){
		FOR(j,1,4){
			cin >> c[i][j];
		}
	}
	bool ok = true;
	ll a[4];
	FOR(i,0,101){
		FOR(j,0,101){
			FOR(k,0,101){
				a[1]=i;
				a[2]=j;
				a[3]=k;
				set<ll> b[4];
				FOR(i,1,4)FOR(j,1,4){
					b[i].insert(c[j][i]-a[j]);
				}
				if(b[1].size()==1&&b[2].size()==1&&b[3].size()==1){
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
}