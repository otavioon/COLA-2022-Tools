#include <bits/stdc++.h>
#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));
int n,k,a;
set<int> st;

int main(){
	cin >> n >> k;
	REP(i,0,k) cin >> a,st.insert(a);
	
	REP(i,n,n*100){
		string s=to_string(i); bool f=true;
		REP(j,0,s.size()) if(st.count(s[j]-'0')) f=false;
		if(f){cout << i << endl; break;}
	}
	return 0;
}
