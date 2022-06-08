#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[3][100005],c;
ll dp[2][100005],ans;
int main()
{

    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<3*n;i++)
        cin>>a[i/n][i%n];
    sort(a[0],a[0]+n);
    sort(a[1],a[1]+n);
    sort(a[2],a[2]+n);
    while(a[0][c]<a[1][0]&&c<n){
        c++,dp[0][0]++;
    }
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1];
        while(a[0][c]<a[1][i]&&c<n){
            c++,dp[0][i]++;
        }
    }
    c=0;
    while(a[1][c]<a[2][0]&&c<n){
        dp[1][0]+=dp[0][c];
        c++;
    }
    ans=dp[1][0];
    for(int i=1;i<n;i++){
        dp[1][i]=dp[1][i-1];
        while(a[1][c]<a[2][i]&&c<n){
            dp[1][i]+=dp[0][c];
            c++;
        }
        ans+=dp[1][i];
    }
    cout<<ans;
    return 0;
}