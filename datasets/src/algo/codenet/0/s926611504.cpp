#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003,INF=1<<30;

int main(){

    string S;cin>>S;
    int K;cin>>K;
    int N=int(S.size());
    int dp[N+1][2];
    for(int i=0;i<=N;i++){
        dp[i][0]=INF;
        dp[i][1]=INF;
    }
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[1][1]=1;
    
    for(int i=1;i<N;i++){
        if(S[i-1]==S[i]){
            dp[i+1][0]=dp[i][1];
            dp[i+1][1]=min(dp[i][0]+1,dp[i][1]+1);
        }else{
            dp[i+1][0]=min(dp[i][0],dp[i][1]);
            dp[i+1][1]=min(dp[i][0]+1,dp[i][1]+1);
        }
    }
    
    if(S[0]!=S[N-1]) cout<<ll(min(dp[N][0],dp[N][1]))*K<<endl;
    else{
        bool ok=true;
        for(int i=1;i<N;i++){
            if(S[i]!=S[0]) ok=false;
        }
        
        if(ok){
            cout<<ll(N)*ll(K)/2<<endl;
        }else{
            cout<<ll(dp[N][1])*(K-1)+min(dp[N][0],dp[N][1])<<endl;
        }
    }
    //cout<<min(dp[N][0],dp[N][1])<<endl;
}


