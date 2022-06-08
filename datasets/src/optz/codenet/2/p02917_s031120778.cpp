#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll visit[4000000],ar[5000500],len=0;
map<string , int>mp;
string s,ss[100000];


int main()
{

    ll i,j,k,n,mx=-19999999999,tc,a,b,c,ans=0,m1,m2;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>ar[i];
        ans+=ar[i];
    }
    ans+=ar[0];
    for(i=0;i<n-2;i++)
    {
        if(ar[i]>ar[i+1])
            ans-=ar[i]-ar[i+1];
    }
    cout<<ans<<endl;






    return 0;
}
