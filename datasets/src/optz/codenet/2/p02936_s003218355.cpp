#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <cstdio>
using namespace std;
typedef long long int ll;
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}

int n,q;
vector<int>abc[200001];
int ans[200001]={0};

void dfs(int p)
{
    if(abc[p].size())
    for(int i=0;i<abc[p].size();i++)
    {
        ans[abc[p][i]]+=ans[p];
        dfs(abc[p][i]);
    }
    
}
int main()
{
    
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        abc[a].push_back(b);
    }
    for(int i=0;i<q;i++)
    {
        int p,x;
        cin>>p>>x;
        p--;
        ans[p]+=x;
    }
    dfs(0);
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
