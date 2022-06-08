#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp

signed main(){
	map<int,int> mp1;
  map<int,int> mp2;
  map<int,int> mp3;
  map<int,int> mp4;
  vvi vec(3,vi(3));
	set<int> s1;
  	set<int> s2;
  	set<int> s3;
  	set<int> s4;
  rep(i,0,3){
	int a,b,c; cin>>a>>b>>c;
    vec[i][0]=a; vec[i][1]=b; vec[i][2]=c;
  	s1.insert(b-a); s2.insert(c-b);
  }
	bool ok;
	rep(i,0,3){
		int a=vec[0][i];
		int b=vec[1][i];
		int c=vec[2][i];
		s3.insert(b-a); s4.insert(c-b);
	}
	if(s1.size()==1 && s2.size()==1){
		if(s3.size()==1 && s4.size()==1){
			ok=true;
		}
	}
	if(ok) cout<<"Yes";
	else cout<<"No";
	return 0;
}