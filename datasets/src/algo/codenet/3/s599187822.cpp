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
		rep(j,N){
			if(B[i]<C[j]){
				D[i]=N-j;
				break;
			}
		}
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