#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;

int N =0;
const int MAXN = 1e5+10;
int A[MAXN];
int B[MAXN];
int C[MAXN];

int main(){
	scanf("%d",&N);
	for(int n=0;n<N;n++){
		scanf("%d",&A[n]);
	}
	for(int n=0;n<N;n++){
		scanf("%d",&B[n]);
	}
	for(int n=0;n<N;n++){
		scanf("%d",&C[n]);
	}
	sort(A,A+N);sort(B,B+N);sort(C,C+N);
	long long int ans=0;
	long long int p = 0;
	long long int q = 0;
	
	for(int i=0;i<N;i++){
		while(A[p]<B[i]&&p<N)	p++;
		while(C[q]<=B[i]&&q<N)	q++;
		ans+=p*(N-q);
	}
	
	printf("%lld",ans);
	
	return 0;
}