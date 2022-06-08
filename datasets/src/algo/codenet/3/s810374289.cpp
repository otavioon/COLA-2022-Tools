#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;


int main(void){
	int N,A[100010],B[100010],C[100010],D[100010]={},ans=0;
	scanf("%d",&N);
	rep(i,N)scanf("%d",&A[i]);
	rep(i,N)scanf("%d",&B[i]);
	rep(i,N)scanf("%d",&C[i]);
	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	rep(i,N){
		if(B[i]>=C[N-1]){
			D[i]=0;
			continue;
		}
		if(B[i]<C[0]){
			D[i]=N;
			continue;
		}
		int l=0,r=N-1;//rが可能
		while(r-l>1){
			int mid = (r+l)/2;
			if(B[i]<C[mid]){
				r = mid;
			}else{
				l = mid;
			}
		}
		D[i] = N-r;
	}
	rep(i,N){
		rep(j,N){
			if(A[i]<B[j]){
				ans+=D[j];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}