#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef long double ldb;
typedef pair<int,int> pii;

int A[100001];
int B[100001];
int C[100001];
LL dp[100001][2];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>A[i];
    for(int i = 0; i < n; ++i)
        cin>>B[i];
    for(int i = 0; i < n; ++i)
        cin>>C[i];
    sort(A, A+n);
    sort(B, B+n);
    sort(C, C+n);
    int j = 0;
    for(int i = 0; i < n; ++i)
    {
        while(j < n && A[j]<B[i])
            ++j;
        dp[i][0] = j;
    }
    LL sum = 0;
    j = 0;
    LL ans = 0;
    for(int i = 0; i < n; ++i)
    {
        while(j < n && B[j]<C[i])
            sum += dp[j++][0];
        dp[i][1] = sum;
        ans += sum;
    }
    cout<<ans<<endl;
    return 0;
}
