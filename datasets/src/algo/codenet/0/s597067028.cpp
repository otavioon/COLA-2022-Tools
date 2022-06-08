#include<bits/stdc++.h>
using namespace std;
#define int long long
long long k;
string s;
long long first,middle;
int dp[110][2];
signed main(){
    cin>>s>>k;
    dp[0][0]=0,dp[0][1]=1;
    for(int i=1;i<s.size();i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+1;
        dp[i][1]=dp[i-1][0];
        if(s[i]!=s[i-1])dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
    }
    int ans1=min(dp[s.size()-1][0],dp[s.size()-1][1]);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1,dp[0][1]=(s[0]==s[s.size()-1])?100000000:0;
    for(int i=1;i<s.size();i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+1;
        dp[i][1]=dp[i-1][0];
        if(s[i]!=s[i-1])dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
    }
    int ans2=min(dp[s.size()-1][0],dp[s.size()-1][1]);
    cout<<ans1+ans2*k-ans2<<endl;
    return 0;
}
