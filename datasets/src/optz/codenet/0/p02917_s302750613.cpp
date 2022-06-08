#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
double PHI = 1.6180339;
#define endl "\n"    
typedef long long ll;
#define int long long
//#define int unsigned long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int arr[n+10];
    for(int i=1;i<=n-1;i++)
    cin>>arr[i];
    arr[n]=arr[n-1];
    arr[n+1]=arr[n];
    arr[0]=arr[1];

    vector<int>v;

    for(int i=1;i<=n;i++)
    {
        int x=min({arr[i-1],arr[i],arr[i+1]});
        v.push_back(x);
    }

    int res=0;
    for(int i=0;i<v.size();i++)
    {
         res+=v[i];
    }
    cout<<res<<endl;

    
}
 