#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pli> vpli;

#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file freopen("out.out","w",stdout);
#define RE cout<<233<<endl;
#define Tnum(x) cout<<x<<endl;
#define Tall(x,n) for(int i=0;i<n;i++)cout<<x[i]<<(i==n-1?"\n":" ");
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REV(a) reverse(a.begin(),a.end())
#define SORT(a) sort(a.begin(),a.end())
#define inf (int)1e9
#define linf (ll)1e18
#define mod (inf+7)

int main() {
  fastio;
  int cnt=0;
  FOR(i,1,3+1){
  	FOR(j,1,3+1){
  		int x;
  		cin>>x;
  		if(x==i+j)cnt++;;
		}
	}
	if(cnt==6)cout<<"Yes\n";
	else cout<<"No\n";







  return 0;
}
