#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef pair<int,int> pii;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
template<class Type> void join(const Type &a){for(auto elem:a)cout<<elem<<' ';cout<<endl;}

int main(){
	string s;
	int k;
	cin>>s>>k;
	
	llong ans=0;
	bool jud=false;
	for(int i=1;i<s.size();++i){
		if(s[i-1]==s[i]){
			if(jud){
				jud=false;
			}else{
				ans++;
				jud=true;
			}
		}else jud=false;
	}
	
	llong cnt=0;
	if(s[0]==s[s.size()-1] and !jud) cnt=1;
	
	cout<<ans*k+cnt*(k-1)<<endl;
}