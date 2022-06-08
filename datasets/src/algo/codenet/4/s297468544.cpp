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
#include<array>
#include<cassert>
#include<list>
#include<experimental/any>
#include<cstring>
#include<cctype>
#include<ctime>
#include<cstdbool>
#include<cstdint>
#include<cstddef>
#include<set>
#include<unordered_set>
#include<bitset>
#include<map>
#include<unordered_map>
 
using namespace std;
using experimental::any;
 
#define SPEEDY cin.tie(0);ios::sync_with_stdio(false);
 
#define REP(i,n) for(int i=0;i<(n);i++)
#define ARREP(i,n,X) for(int i=0;i<(n);i++)cin>>X[i]
#define FOR(i,X,n) for(int i=(X);i<(n);i++)
#define EREP(i,n) for(int i=1;i<=n;i++)
#define BitFOR(N) REP(Bit,1<<(N))
 
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define DEB2(X) cout<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define TFDEB(f) (f)? cout<<"true ":cout<<"false ";
#define FORDEB(n,X) for(int i=0;i<(n);i++)ARDEB(i,X)
#define END cout<<endl;
#else
#define DEB(X) {}
#define DEB2(X) {}
#define ARDEB(i,X) {}
#define TFDEB(f) {}
#define FORDEB(n,X) {}
#define END {}
#endif
 
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define ALL(X) X.begin(),X.end()
struct edge{int to,cost;};
//struct edge{int from,cost,to;};
struct P2{int x,y;};
#define BIT(Bit,n) bitset<n>(Bit)
#define Endl endl
 
const int MOD7=1000000007;
const int INF=100000000;
const int SET=1000;

int I=0,O=0;
#if 0
int main(){
	int n,m,ans=0,mode=0;
	char last;
	string s,ioi="IOI";
	cin>>n>>m>>s;
	n--;
	REP(i,n){
		ioi+="OI";
	}
	int siz=ioi.size();
	REP(i,s.size()){
		bool f=false;
		if(s[i]=='I'&&mode==0){
			I++,mode=1;
		}
		if(s[i]=='O'&&mode==1){
			O++,mode=0;
		}
		if(mode==1&&s[i]=='I'){
			I=0,O=0,mode=0;
		}
		if(mode==0&&s[i]=='O'){
			O=0,I=0,mode=0;
		}
		if(O==(siz/2)&&I==siz-(siz/2)){
			
		}
	}
	cout<<ans<<endl;
	return 0;
}
#endif
int main(){
	int n,m,a[11];
	char s[1000]={'\0'};
	set<int> st;
	bool f[1000]={false};
	cin>>n>>m;
	REP(i,m){
		cin>>a[i];
		st.insert(a[i]);
	}
	sprintf(s,"%d",n);
	DEB(s)DEB(strlen(s))END
	REP(i,strlen(s)){
		int dim=int(s[i]-'0');
		if(st.find(dim)!=st.end()){
			for(int j=dim;j<=9;j++){
				if(st.find(j)==st.end()){
					s[i]=char(j+'0');
					break;
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}