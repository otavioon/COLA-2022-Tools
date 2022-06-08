/*
  KUNAL ANAND
  MNNIT ALLAHABAD
*/  
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define debug1(x) cout << # x << " " << x << endl;
#define debug2(x,y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x,y,z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long int ll;
const ll INF=1e14;
const ll mod=1e9+7;
ll dp[100005][3],ans=LLONG_MIN,var=0;
vector<ll>graph[100005];
ll nod_val[100005];
ll power(ll x,ll y)
{
    if(y==0)
        return 1;
    ll a=power(x,y/2);
    a=(a*a);
    if(y%2)
        a=(a*x);
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t,x;
    ll i,j,k,a,b,n,m,q,y,flag=0,c,d,sum=0,cr=0,maxi=0,cl=0,temp,curr,l,r,sum1,sum2,sum3,low,high,mid;
    cin >> n;
    ll A[n],B[n],C[n];
    for(i=0;i<n-1;i++)
        cin >> B[i];
    A[0]=A[1]=B[0];
    for(i=1;i<n-1;i++)
    {
        if(B[i]<A[i])
        {
            A[i]=B[i];
            A[i+1]=B[i];
        }
        else
            A[i+1]=B[i];
    }
    ll ans=0;
    for(i=0;i<n;i++)
        ans+=A[i];
    cout << ans << endl;
    return 0;
}    