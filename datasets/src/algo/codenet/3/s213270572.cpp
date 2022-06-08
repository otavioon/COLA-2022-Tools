#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=2e9;
int main(){
	int N;cin>>N;
	int A[N+1],B[N+1],C[N+1];
	A[N]=inf;B[N]=inf;C[N]=inf;
	rep(i,0,N) cin>>A[i];
	rep(i,0,N) cin>>B[i];
	rep(i,0,N) cin>>C[i];
	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	long ans = 0;int i = 0,k = 0;
	rep(j,0,N){
		while(A[i] < B[j]) i++;
		while(B[j] >= C[k]) k++;
		ans += i * (N - k);
	}cout<<ans<<endl;
}