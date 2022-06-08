#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define VSORT(v) sort(v.begin(), v.end())
#define DVSORT(v) sort(v.begin(), v.end(),greater<int>())
#define SORT(v, n) sort(v, v+n)
#define DSORT(v,n) sort(v, v+n,greater<int>())
#define vi vector<int>
#define pb push_back
#define P pair<int,int>
 
template <class T> void chmin(T&a,const T&b) { a = min(a,b); }
template <class T> void chmax(T&a,const T&b) { a = max(a,b); }
 
void print(){cout<<endl;}
template <class Head, class... Tail>
void print(Head&& h,Tail&&... t){ 
	if(sizeof...(t)==0)
		cout<<h;
	else
		cout<<h<<' ';
	print(move(t)...);
}
 
const double EPS =1e-9;
const long INF =2147483647;//32bit 2*1e+9
const long MOD =1e+9+7;
#define PI 3.14159265258979
 
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};


int main(void){
	int N;
	ll result=0,A[100000],B[100000],C[100000];

	cin>>N;
	REP(i,N)	cin>>A[i];
	REP(i,N)	cin>>B[i];
	REP(i,N)	cin>>C[i];
	SORT(A,N);
	SORT(B,N);
	SORT(C,N);

	REP(i,N){
		REP(j,N){
			REP(r,N){
				if(A[i]<B[j] && B[j]<C[r]){
					result+=(N-r);
					break;
				}
			}

		}
	}

	print(result);
	return 0;
}

