#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#define NMAX 40
#define AMAX 10
#define INF (int )1e9

//コメントアウトするとdebug()を実行しない
#define DEBUG

using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int ,int > P;
typedef long long ll;

int N,M[2],a[NMAX],b[NMAX],c[NMAX],dp[NMAX+1][NMAX*AMAX+1][NMAX*AMAX+1],ans = INF;
string S;
static const int dx[8] = {0,1,1,1,0,-1,-1,-1},
					dy[8] = {1,1,0,-1,-1,-1,0,1};

void solve(){
	dp[0][0][0] = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int ca = 0; ca < NMAX*AMAX; ++ca)
		{
			for (int cb = 0; cb < NMAX*AMAX; ++cb)
			{
				if(dp[i][ca][cb] == INF){
					continue;
				}
				dp[i+1][ca][cb] = min(dp[i+1][ca][cb],dp[i][ca][cb]);
				dp[i+1][ca+a[i]][cb+b[i]] = min(dp[i+1][ca+a[i]][cb+b[i]],dp[i][ca][cb]+c[i]);
			}
		}
	}
	for (int ca = 1; ca <= NMAX*AMAX; ++ca)
	{
		for (int cb = 1; cb <= NMAX*AMAX; ++cb)
		{
			if(ca*M[0] == cb*M[1]){
				ans = min(ans,dp[N][ca][cb]);
			}
		}
	}
	if(ans == INF)ans = -1;
}

void debug(){

}

void answer(){
	printf("%d\n",ans);
}

int main(){
	ios::sync_with_stdio(false);
	for(int i = 0; i <= NMAX; ++i){
		for(int ca = 0; ca <= NMAX*AMAX; ++ca){
			for(int cb = 0; cb <= NMAX*AMAX; ++cb){
				dp[i][ca][cb]=INF;
			} 
		}
	}
	// Fill(dp,INF);
	cin >> N >> M[0] >> M[1];
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	solve();
	#ifdef DEBUG
	debug();
	#endif
	answer();

	return 0;
}