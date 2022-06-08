#pragma GCC target("avx")
//#pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define DB double
#define LD long double
#define ST string
#define BS bitset
#define PA pair<LL,LL>
#define VE vector
#define VL vector<LL>
#define VP vector<pair<LL,LL>>
#define VVL vector<vector<LL>>
#define PQ priority_queue
#define PQS priority_queue<LL,vector<LL>,greater<LL>>
#define FI first
#define SE second
#define PB push_back
#define POB pop_back
#define PF push_front
#define POF pop_front
#define EB emplace_back
#define MP make_pair
#define TS to_string
#define TU to_ullong
#define BPL __builtin_popcountll
#define FOR(i,a,n) for(i=a;i<n;++i)
#define FORR(i,a,n) for(i=n-1;i>=a;--i)
#define rep(i,n) FOR(i,0,n)
#define repr(i,n) FORR(i,0,n)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define UB(a,n) *upper_bound(ALL(a),n)
#define UBn(a,n) upper_bound(ALL(a),n)-a.begin()
#define LB(a,n) *lower_bound(ALL(a),n)
#define LBn(a,n) lower_bound(ALL(a),n)-a.begin()
#define INF 1145141919810364364LL
#define PI 3.14159265358979
#define MOD 1000000007
//#define MOD 998244353
#define ERR 0.00000001
#define FAST cin.tie(0);ios::sync_with_stdio(false)

void Yn(LL a){if(a)printf("Yes\n");else printf("No\n");}
void YN(LL a){if(a)printf("YES\n");else printf("NO\n");}
LL pwmn(LL a,LL n){LL ans=1;while(ans<a)ans*=n;return ans;}
LL dig(LL n){LL ret=0;while(n)n/=10,ret++;return ret;}
LL GCD(LL a,LL b){LL c=1,tmp=max(a,b);b=min(a,b);a=tmp;while(c!=0){c=a%b;a=b;b=c;}return a;}
LL LCM(LL a,LL b){return a*b/GCD(a,b);}
int lcmp(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return 1;if(*(LL*)a<*(LL*)b)return -1;return 0;}
int lcmpr(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return -1;if(*(LL*)a<*(LL*)b)return 1;return 0;}
int ccmp(const void* a,const void* b){return *(char*)a-*(char*)b;}
int ccmpr(const void* a,const void* b){return *(char*)b-*(char*)a;}
int scmp(const void* a,const void* b){return strcmp((char*)a,(char*)b);}
int scmpr(const void* a,const void* b){return strcmp((char*)b,(char*)a);}
LL cmod(LL a,LL m){if(a%m<0)return a%m+abs(m);else return a%m;}
LL DIV(LL a,LL d,LL m){LL l=m,x=1,y=0,k;while(l){k=d/l;d-=k*l;swap(l,d);x-=k*y;swap(x,y);}return cmod(a*cmod(x,m),m);}
LL POW(LL a,LL n,LL m){LL ans=1;while(n>0){if(n&1)ans=ans*a%m;a=a*a%m;n>>=1;}return ans;}
VL fact,finv,inv;
void comi(LL n){LL i;fact.resize(max(2LL,n+1));finv.resize(max(2LL,n+1));inv.resize(max(2LL,n+1));fact[0]=fact[1]=1;finv[0]=finv[1]=1;inv[1]=1;FOR(i,2,n+1){fact[i]=fact[i-1]*i%MOD;inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;finv[i]=finv[i-1]*inv[i]%MOD;}}
LL com(LL n,LL k){if(n<k||n<0||k<0)return 0;return fact[n]*(finv[k]*finv[n-k]%MOD)%MOD;}
bool cmps(pair<LL,LL> a,pair<LL,LL> b){if(a.second!=b.second)return a.second<b.second;return a.first<b.first;}
template<typename T>bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

#define MI modint<MOD>
template<int mod>struct modint{
	int x;
	modint():x(0){}
	modint(LL n):x(n>=0?n%mod:(mod-(-n)%mod)%mod){}
	modint &operator+=(const modint &n){if((x+=n.x)>=mod)x-=mod;return *this;}
	modint &operator-=(const modint &n){if((x+=mod-n.x)>=mod)x-=mod;return *this;}
	modint &operator++(){*this+=1;return *this;}
  modint &operator--(){*this-=1;return *this;}
	modint &operator*=(const modint &n){x=(int)((LL)x*n.x%mod);return *this;}
	modint &operator/=(const modint &n){*this*=n.inv();return *this;}
	modint operator-()const{return modint(-x);}
	modint operator+(const modint &n)const{return modint(*this)+=n;}
	modint operator-(const modint &n)const{return modint(*this)-=n;}
	modint operator++(int){modint ret(*this);*this+=1;return ret;}
  modint operator--(int){modint ret(*this);*this-=1;return ret;}
	modint operator*(const modint &n)const{return modint(*this)*=n;}
	modint operator/(const modint &n)const{return modint(*this)/=n;}
	bool operator<(const modint &n)const{return x<n.x;}
	bool operator>(const modint &n)const{return x>n.x;}
	bool operator<=(const modint &n)const{return x<=n.x;}
	bool operator>=(const modint &n)const{return x>=n.x;}
	bool operator!=(const modint &n)const{return x!=n.x;}
	bool operator==(const modint &n)const{return x==n.x;}
	friend istream &operator>>(istream &is,modint &n){LL l;is>>l;n=modint<mod>(l);return is;}
	friend ostream &operator<<(ostream &os,const modint &n){return os<<n.x;}
	int getmod(){return mod;}
	modint inv()const{int a=x,b=mod,c=1,d=0,n;while(b){n=a/b;swap(a-=n*b,b);swap(c-=n*d,d);}return modint(c);}
	modint pow(LL n)const{modint ret(1),m(x);while(n){if(n&1)ret*=m;m*=m;n>>=1;}return ret;}
};

int main(){
  FAST;
  LL i,ans=0,N,K,mn=0,mx=INF,md,a;
	cin>>N>>K;
	VL A(N);
	rep(i,N)cin>>A[i];
	while(mx-mn>1){
		md=(mx+mn)/2;
		a=0;
		rep(i,N)a+=(A[i]-1)/md;
		if(a<=K)mx=md;
		else mn=md;
	}
	cout<<mx<<endl;
}
